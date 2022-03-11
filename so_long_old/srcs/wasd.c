/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:23:38 by sclam             #+#    #+#             */
/*   Updated: 2021/11/15 16:19:15 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_w(t_mlx_map *mlx)
{
	if (mlx->map.map[mlx->map.h_pos_y - 1][mlx->map.h_pos_x] == '1')
		return (-1);
	if (ft_danger_w(mlx) == 0)
		return (0);
	if (mlx->map.map[mlx->map.h_pos_y - 1][mlx->map.h_pos_x] == '0')
		mlx->anim.up = 10;
	else if (mlx->map.map[mlx->map.h_pos_y - 1][mlx->map.h_pos_x] == 'C')
	{
		mlx->anim.col_flag = 35;
		mlx->map.coll -= 1;
	}
	else if (mlx->map.map[mlx->map.h_pos_y - 1][mlx->map.h_pos_x] == 'E')
	{
		if (mlx->map.coll != 0)
			return (-1);
		mlx->map.end_game = 1;
		mlx->anim.exit = 20;
		mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x] = '0';
		return (0);
	}
	mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x] = '0';
	mlx->map.map[mlx->map.h_pos_y - 1][mlx->map.h_pos_x] = 'P';
	mlx->map.h_pos_y -= 1;
	return (0);
}

int	ft_check_s(t_mlx_map *mlx)
{
	if (mlx->map.map[mlx->map.h_pos_y + 1][mlx->map.h_pos_x] == '1')
		return (-1);
	if (ft_danger_s(mlx) == 0)
		return (0);
	if (mlx->map.map[mlx->map.h_pos_y + 1][mlx->map.h_pos_x] == '0')
	{
		mlx->map.map[mlx->map.h_pos_y + 1][mlx->map.h_pos_x] = 'P';
		mlx->anim.down = 10;
	}
	else if (mlx->map.map[mlx->map.h_pos_y + 1][mlx->map.h_pos_x] == 'C')
	{
		mlx->anim.col_flag = 35;
		mlx->map.map[mlx->map.h_pos_y + 1][mlx->map.h_pos_x] = 'P';
		mlx->map.coll -= 1;
	}
	else if (mlx->map.map[mlx->map.h_pos_y + 1][mlx->map.h_pos_x] == 'E')
	{
		if (mlx->map.coll != 0)
			return (-1);
		mlx->map.end_game = 1;
		mlx->anim.exit = 20;
	}
	mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x] = '0';
	mlx->map.h_pos_y += 1;
	return (0);
}

int	ft_check_d(t_mlx_map *mlx)
{
	if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x + 1] == '1')
		return (-1);
	if (ft_danger_d(mlx) == 0)
		return (0);
	if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x + 1] == '0')
		mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x + 1] = 'P';
	else if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x + 1] == 'C')
	{
		mlx->anim.col_flag = 35;
		mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x + 1] = 'P';
		mlx->map.coll -= 1;
	}
	else if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x + 1] == 'E')
	{
		if (mlx->map.coll != 0)
			return (-1);
		mlx->map.end_game = 1;
		mlx->anim.exit = 20;
	}
	mlx->anim.step = 15;
	mlx->anim.dir = 'r';
	mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x] = '0';
	mlx->map.h_pos_x += 1;
	return (0);
}

int	ft_check_a(t_mlx_map *mlx)
{
	if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x - 1] == '1')
		return (-1);
	if (ft_danger_a(mlx) == 0)
		return (0);
	if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x - 1] == '0')
		mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x - 1] = 'P';
	else if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x - 1] == 'C')
	{
		mlx->anim.col_flag = 35;
		mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x - 1] = 'P';
		mlx->map.coll -= 1;
	}
	else if (mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x - 1] == 'E')
	{
		if (mlx->map.coll != 0)
			return (-1);
		mlx->map.end_game = 1;
		mlx->anim.exit = 20;
	}
	mlx->anim.step = 15;
	mlx->anim.dir = 'l';
	mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x] = '0';
	mlx->map.h_pos_x -= 1;
	return (0);
}
