/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:46:06 by sclam             #+#    #+#             */
/*   Updated: 2021/12/05 21:59:19 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_close(t_mlx_map *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_error(mlx, 0, "Good bye");
	return (0);
}

static void	ft_change_map(t_mlx_map *mlx, char c)
{
	int	i;

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

void	ft_error(t_mlx_map *mlx, int error, char *str)
{
	if (error == 1)
		perror(str);
	if (error == 0)
	{
		ft_free_arr(mlx->map.map);
		exit(EXIT_SUCCESS);
	}
	if (error == -1)
	{
		printf("%s\n", str);
		ft_free_arr(mlx->map.map);
	}
	exit(EXIT_FAILURE);
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
	h = mlx.map.height;
	l = mlx.map.len - 1;
	mlx.mlx = mlx_init();
	ft_init_assets(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, l * mlx.tile, h * mlx.tile, "so_long");
	ft_render(&mlx);
	mlx_key_hook(mlx.win, ft_key_hook, &mlx);
	mlx_loop_hook(mlx.mlx, ft_anim, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_close, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
