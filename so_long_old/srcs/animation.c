/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:30:33 by sclam             #+#    #+#             */
/*   Updated: 2021/11/15 16:18:44 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_pick_col_l(t_mlx_map *mlx)
{
	if (mlx->anim.col_flag == 35)
		ft_hero_left(mlx, 2);
	if (mlx->anim.col_flag == 27)
		ft_hero_left(mlx, 3);
	if (mlx->anim.col_flag == 20)
		ft_hero_left(mlx, 4);
	if (mlx->anim.col_flag == 14)
		ft_hero_left(mlx, 5);
	if (mlx->anim.col_flag == 7)
		ft_hero_left(mlx, 6);
	mlx->anim.col_flag -= 1;
	if (mlx->anim.col_flag == 0)
		ft_hero_left(mlx, 1);
}

void	ft_pick_col_r(t_mlx_map *mlx)
{
	if (mlx->anim.col_flag == 35)
		ft_hero_right(mlx, 2);
	if (mlx->anim.col_flag == 27)
		ft_hero_right(mlx, 3);
	if (mlx->anim.col_flag == 20)
		ft_hero_right(mlx, 4);
	if (mlx->anim.col_flag == 14)
		ft_hero_right(mlx, 5);
	if (mlx->anim.col_flag == 7)
		ft_hero_right(mlx, 6);
	mlx->anim.col_flag -= 1;
	if (mlx->anim.col_flag == 0)
		ft_hero_right(mlx, 1);
}

void	ft_anim_col(t_mlx_map *mlx)
{
	if (mlx->anim.anim == 40)
		ft_collect(mlx, 1);
	if (mlx->anim.anim == 32)
		ft_collect(mlx, 2);
	if (mlx->anim.anim == 24)
		ft_collect(mlx, 3);
	if (mlx->anim.anim == 17)
		ft_collect(mlx, 4);
	if (mlx->anim.anim == 9)
		ft_collect(mlx, 3);
	if (mlx->anim.anim == 3)
		ft_collect(mlx, 2);
	mlx->anim.anim -= 1;
	if (mlx->anim.anim == 0)
		mlx->anim.anim = 40;
}

void	ft_step(t_mlx_map *mlx)
{
	if (mlx->anim.step > 0 && mlx->anim.dir == 'r')
	{
		if (mlx->anim.step == 15)
			ft_hero_right(mlx, 7);
		if (mlx->anim.step == 9)
			ft_hero_right(mlx, 8);
		if (mlx->anim.step == 4)
			ft_hero_right(mlx, 9);
		mlx->anim.step -= 1;
		if (mlx->anim.step == 0)
			ft_hero_right(mlx, 1);
	}
	if (mlx->anim.step > 0 && mlx->anim.dir == 'l')
	{
		if (mlx->anim.step == 15)
			ft_hero_left(mlx, 7);
		if (mlx->anim.step == 9)
			ft_hero_left(mlx, 8);
		if (mlx->anim.step == 4)
			ft_hero_left(mlx, 9);
		mlx->anim.step -= 1;
		if (mlx->anim.step == 0)
			ft_hero_left(mlx, 1);
	}
}

void	ft_exit_anim(t_mlx_map *mlx)
{
	if (mlx->anim.exit > 0 && mlx->anim.dir == 'l')
	{
		if (mlx->anim.exit == 20)
			ft_exit(mlx, 2);
		if (mlx->anim.exit == 10)
			ft_exit(mlx, 3);
		mlx->anim.exit -= 1;
		if (mlx->anim.exit == 0)
			ft_exit(mlx, 1);
	}
	if (mlx->anim.exit > 0 && mlx->anim.dir == 'r')
	{
		if (mlx->anim.exit == 20)
			ft_exit(mlx, 4);
		if (mlx->anim.exit == 10)
			ft_exit(mlx, 5);
		mlx->anim.exit -= 1;
		if (mlx->anim.exit == 0)
			ft_exit(mlx, 1);
	}
}
