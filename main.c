/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:37:09 by sclam             #+#    #+#             */
/*   Updated: 2022/03/21 17:05:57 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_mlx_map *mlx, int error, char *str)
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

static int	close_window(t_mlx_map *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	error(mlx, 0, "Good bye");
	return (0);
}

static void	change_map(t_mlx_map *mlx, char c)
{
	if (mlx->anim.col_flag > 0 || mlx->anim.down > 0 || mlx->anim.up > 0
		|| mlx->anim.step > STEP_TICKS / 2 || mlx->map.end_game)
		return ;
	if (c == 'W' && mlx->hero->up->type != WALL)
		move_up(mlx);
	else if (c == 'S' && mlx->hero->down->type != WALL)
		move_down(mlx);
	else if (c == 'A' && mlx->hero->left->type != WALL)
		move_left(mlx);
	else if (c == 'D' && mlx->hero->right->type != WALL)
		move_right(mlx);
	else
		return ;
	mlx->map.moves += 1;
}

static int	key_hook(int keycode, t_mlx_map *mlx)
{
	if (mlx->map.end_game == 0)
	{
		if (keycode == 13 || keycode == 126)
			change_map(mlx, 'W');
		if (keycode == 1 || keycode == 125)
			change_map(mlx, 'S');
		if (keycode == 0 || keycode == 123)
			change_map(mlx, 'A');
		if (keycode == 2 || keycode == 124)
			change_map(mlx, 'D');
	}
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		error(mlx, 0, "Good bye");
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
	ber(argv[1]);
	init_map(argv, &mlx);
	map_checker(&mlx);
	mlx.tilemap = generate_tilemap(&mlx);
	ft_free_arr((void **)mlx.map.map);
	if (!mlx.tilemap)
		return (1);
	mlx.hero = &mlx.tilemap[mlx.map.h_pos_y][mlx.map.h_pos_x];
	h = mlx.map.height;
	l = mlx.map.len - 1;
	mlx.mlx = mlx_init();
	init_assets(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, l * TILE, h * TILE, "so_long");
	render(&mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop_hook(mlx.mlx, anim, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
