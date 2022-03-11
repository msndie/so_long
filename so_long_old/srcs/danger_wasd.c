/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   danger_wasd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:32:26 by sclam             #+#    #+#             */
/*   Updated: 2021/11/15 16:18:48 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_danger_a(t_mlx_map *mlx)
{
	if (mlx->map.enemy_s > 0)
		ft_patrol_s(mlx);
	if (mlx->map.enemy_w > 0)
		ft_patrol_w(mlx);
	if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x - 1] != 'W'
		&& mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x - 1] != 'S')
		return (1);
	if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x - 1] == 'S')
		mlx->map.enemy_s = 0;
	if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x - 1] == 'W')
		mlx->map.enemy_w = 0;
	mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x - 1] = 'P';
	mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x] = '0';
	mlx->anim.death = 18;
	mlx->map.end_game = 2;
	mlx->map.h_pos_x -= 1;
	mlx->anim.dir = 'l';
	return (0);
}

int	ft_danger_s(t_mlx_map *mlx)
{
	if (mlx->map.enemy_s > 0)
		ft_patrol_s(mlx);
	if (mlx->map.enemy_w > 0)
		ft_patrol_w(mlx);
	if (mlx->map.map[mlx->map.h_pos_y + 1][mlx->map.h_pos_x] != 'W'
		&& mlx->map.map[mlx->map.h_pos_y + 1][mlx->map.h_pos_x] != 'S')
		return (1);
	if (mlx->map.map[mlx->map.h_pos_y + 1][mlx->map.h_pos_x] == 'W')
		mlx->map.enemy_w = 0;
	if (mlx->map.map[mlx->map.h_pos_y + 1][mlx->map.h_pos_x] == 'S')
		mlx->map.enemy_s = 0;
	mlx->map.map[mlx->map.h_pos_y + 1][mlx->map.h_pos_x] = 'P';
	mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x] = '0';
	mlx->map.h_pos_y += 1;
	mlx->anim.death = 18;
	mlx->map.end_game = 2;
	return (0);
}

int	ft_danger_d(t_mlx_map *mlx)
{
	if (mlx->map.enemy_s > 0)
		ft_patrol_s(mlx);
	if (mlx->map.enemy_w > 0)
		ft_patrol_w(mlx);
	if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x + 1] != 'W'
		&& mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x + 1] != 'S')
		return (1);
	if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x + 1] == 'W')
		mlx->map.enemy_w = 0;
	if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x + 1] == 'S')
		mlx->map.enemy_s = 0;
	mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x + 1] = 'P';
	mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x] = '0';
	mlx->map.h_pos_x += 1;
	mlx->anim.death = 18;
	mlx->map.end_game = 2;
	mlx->anim.dir = 'r';
	return (0);
}

int	ft_danger_w(t_mlx_map *mlx)
{
	if (mlx->map.enemy_s > 0)
		ft_patrol_s(mlx);
	if (mlx->map.enemy_w > 0)
		ft_patrol_w(mlx);
	if (mlx->map.map[mlx->map.h_pos_y - 1][mlx->map.h_pos_x] != 'W'
		&& mlx->map.map[mlx->map.h_pos_y - 1][mlx->map.h_pos_x] != 'S')
		return (1);
	if (mlx->map.map[mlx->map.h_pos_y - 1][mlx->map.h_pos_x] == 'W')
		mlx->map.enemy_w = 0;
	if (mlx->map.map[mlx->map.h_pos_y - 1][mlx->map.h_pos_x] == 'S')
		mlx->map.enemy_s = 0;
	mlx->map.map[mlx->map.h_pos_y - 1][mlx->map.h_pos_x] = 'P';
	mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x] = '0';
	mlx->anim.death = 18;
	mlx->map.end_game = 2;
	mlx->map.h_pos_y -= 1;
	return (0);
}
