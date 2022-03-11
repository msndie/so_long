/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:08:16 by sclam             #+#    #+#             */
/*   Updated: 2021/11/15 16:52:25 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_anim_dang(t_mlx_map *mlx)
{
	if (mlx->anim.dang == 40)
		ft_danger(mlx, 0);
	if (mlx->anim.dang == 32)
		ft_danger(mlx, 1);
	if (mlx->anim.dang == 24)
		ft_danger(mlx, 2);
	if (mlx->anim.dang == 17)
		ft_danger(mlx, 3);
	if (mlx->anim.dang == 9)
		ft_danger(mlx, 2);
	if (mlx->anim.dang == 3)
		ft_danger(mlx, 1);
	mlx->anim.dang -= 1;
	if (mlx->anim.dang == 0)
		mlx->anim.dang = 40;
}

void	ft_patrol_s(t_mlx_map *mlx)
{
	int	y;
	int	x;

	y = mlx->map.e2_pos_y;
	x = mlx->map.e2_pos_x;
	if ((mlx->map.map[y - 1][x] == '1' || mlx->map.map[y - 1][x] == 'C'
		|| mlx->map.map[y - 1][x] == 'E') && mlx->anim.enemy_dir2 == 'w')
		mlx->anim.enemy_dir2 = 's';
	else if (mlx->map.map[y - 1][x] == '0' && mlx->anim.enemy_dir2 == 'w')
	{
		mlx->map.map[mlx->map.e2_pos_y - 1][mlx->map.e2_pos_x] = 'S';
		mlx->map.map[mlx->map.e2_pos_y][mlx->map.e2_pos_x] = '0';
		mlx->map.e2_pos_y -= 1;
	}
	else if ((mlx->map.map[y + 1][x] == '1' || mlx->map.map[y + 1][x] == 'C'
		|| mlx->map.map[y + 1][x] == 'E' || mlx->map.map[y + 1][x] == 'W')
		&& mlx->anim.enemy_dir2 == 's')
		mlx->anim.enemy_dir2 = 'w';
	else if (mlx->map.map[y + 1][x] == '0' && mlx->anim.enemy_dir2 == 's')
	{
		mlx->map.map[mlx->map.e2_pos_y + 1][mlx->map.e2_pos_x] = 'S';
		mlx->map.map[mlx->map.e2_pos_y][mlx->map.e2_pos_x] = '0';
		mlx->map.e2_pos_y += 1;
	}
}

void	ft_patrol_w(t_mlx_map *mlx)
{
	int	y;
	int	x;

	y = mlx->map.e1_pos_y;
	x = mlx->map.e1_pos_x;
	if ((mlx->map.map[y - 1][x] == '1' || mlx->map.map[y - 1][x] == 'C'
		|| mlx->map.map[y - 1][x] == 'E' || mlx->map.map[y - 1][x] == 'S')
		&& mlx->anim.enemy_dir1 == 'w')
		mlx->anim.enemy_dir1 = 's';
	else if (mlx->map.map[y - 1][x] == '0' && mlx->anim.enemy_dir1 == 'w')
	{
		mlx->map.map[mlx->map.e1_pos_y - 1][mlx->map.e1_pos_x] = 'W';
		mlx->map.map[mlx->map.e1_pos_y][mlx->map.e1_pos_x] = '0';
		mlx->map.e1_pos_y -= 1;
	}
	else if ((mlx->map.map[y + 1][x] == '1' || mlx->map.map[y + 1][x] == 'C'
		|| mlx->map.map[y + 1][x] == 'E' || mlx->map.map[y + 1][x] == 'S')
		&& mlx->anim.enemy_dir1 == 's')
		mlx->anim.enemy_dir1 = 'w';
	else if (mlx->map.map[y + 1][x] == '0' && mlx->anim.enemy_dir1 == 's')
	{
		mlx->map.map[mlx->map.e1_pos_y + 1][mlx->map.e1_pos_x] = 'W';
		mlx->map.map[mlx->map.e1_pos_y][mlx->map.e1_pos_x] = '0';
		mlx->map.e1_pos_y += 1;
	}
}

void	ft_enemy_pos(t_mlx_map *mlx)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (mlx->map.map[i])
	{
		while (mlx->map.map[i][n])
		{
			if (mlx->map.map[i][n] == 'W')
			{
				mlx->map.e1_pos_x = n;
				mlx->map.e1_pos_y = i;
			}
			if (mlx->map.map[i][n] == 'S')
			{
				mlx->map.e2_pos_x = n;
				mlx->map.e2_pos_y = i;
			}
			n++;
		}
		n = 0;
		i++;
	}
}
