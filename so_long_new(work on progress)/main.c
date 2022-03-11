/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:37:09 by sclam             #+#    #+#             */
/*   Updated: 2022/03/10 20:25:31 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_mlx_map *mlx, int error, char *str)
{
	if (error == 1)
		perror(str);
	if (error == 0)
	{
		ft_free_arr((void **)mlx->tilemap);
		exit(EXIT_SUCCESS);
	}
	if (error == -1)
	{
		printf("%s\n", str);
		ft_free_arr((void **)mlx->map.map);
	}
	exit(EXIT_FAILURE);
}

// void	ft_danger(t_mlx_map *mlx, int n)
// {
// 	char	*path;
// 	int		img_width;
// 	int		img_height;
// 	void	*img;

// 	if (n == 0)
// 		path = "assets/danger1.xpm";
// 	if (n == 1)
// 		path = "assets/danger2.xpm";
// 	if (n == 2)
// 		path = "assets/danger3.xpm";
// 	if (n == 3)
// 		path = "assets/danger4.xpm";
// 	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
// 	mlx->assets.enemy = img;
// }

static int	ft_close(t_mlx_map *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_error(mlx, 0, "Good bye");
	return (0);
}

static void	ft_change_map(t_mlx_map *mlx, char c)
{
	int	i;

	i = -1;
	if (mlx->anim.col_flag > 0 || mlx->anim.down > 0 || mlx->anim.up > 0)
		return ;
	if (c == 'W')
		i = ft_check_w(mlx);
	if (c == 'S')
		i = ft_check_s(mlx);
	if (c == 'A')
		i = ft_check_a(mlx);
	if (c == 'D')
		i = ft_check_d(mlx);
	if (i == -1)
		return ;
	mlx->map.moves += 1;
	mlx_clear_window(mlx->mlx, mlx->win);
	ft_render(mlx);
}

static int	ft_key_hook(int keycode, t_mlx_map *mlx)
{
	if (mlx->map.end_game == 0)
	{
		if (keycode == 13 || keycode == 126)
			ft_change_map(mlx, 'W');
		if (keycode == 1 || keycode == 125)
			ft_change_map(mlx, 'S');
		if (keycode == 0 || keycode == 123)
			ft_change_map(mlx, 'A');
		if (keycode == 2 || keycode == 124)
			ft_change_map(mlx, 'D');
	}
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		ft_error(mlx, 0, "Good bye");
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_map		mlx;
	size_t			h;
	size_t			l;

	if (argc < 2)
	{
		printf("No map file\n");
		return (0);
	}
	if (argc > 2)
		printf("Only first argument will be used\n");
	ft_ber(argv[1]);
	ft_init_map(argv, &mlx);
	ft_map_checker(&mlx);
	mlx.tilemap = generate_tilemap(&mlx);
	ft_free_arr((void **)mlx.map.map);
	if (!mlx.tilemap)
		return (1);
	mlx.hero = &mlx.tilemap[mlx.map.h_pos_y][mlx.map.h_pos_x];
	h = mlx.map.height;
	l = mlx.map.len - 1;
	mlx.mlx = mlx_init();
	ft_init_assets(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, l * TILE, h * TILE, "so_long");
	ft_render(&mlx);
	mlx_key_hook(mlx.win, ft_key_hook, &mlx);
	// mlx_loop_hook(mlx.mlx, ft_anim, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_close, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
