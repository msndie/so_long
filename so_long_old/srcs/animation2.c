/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:07:54 by sclam             #+#    #+#             */
/*   Updated: 2021/11/15 16:18:41 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_up_down_r(t_mlx_map *mlx)
{
	if (mlx->anim.up > 0 && mlx->anim.dir == 'r')
	{
		if (mlx->anim.up == 10)
			ft_hero_right2(mlx, 1);
		if (mlx->anim.up == 5)
			ft_hero_right2(mlx, 2);
		mlx->anim.up -= 1;
		if (mlx->anim.up == 0)
			ft_hero_right(mlx, 1);
	}
	if (mlx->anim.down > 0 && mlx->anim.dir == 'r')
	{
		if (mlx->anim.down == 10)
			ft_hero_right2(mlx, 3);
		if (mlx->anim.down == 5)
			ft_hero_right2(mlx, 4);
		mlx->anim.down -= 1;
		if (mlx->anim.down == 0)
			ft_hero_right(mlx, 1);
	}
}

static void	ft_up_down_l(t_mlx_map *mlx)
{
	if (mlx->anim.up > 0 && mlx->anim.dir == 'l')
	{
		if (mlx->anim.up == 10)
			ft_hero_left2(mlx, 1);
		if (mlx->anim.up == 5)
			ft_hero_left2(mlx, 2);
		mlx->anim.up -= 1;
		if (mlx->anim.up == 0)
			ft_hero_left(mlx, 1);
	}
	if (mlx->anim.down > 0 && mlx->anim.dir == 'l')
	{
		if (mlx->anim.down == 10)
			ft_hero_left2(mlx, 3);
		if (mlx->anim.down == 5)
			ft_hero_left2(mlx, 4);
		mlx->anim.down -= 1;
		if (mlx->anim.down == 0)
			ft_hero_left(mlx, 1);
	}
}

static void	ft_hole_anim(t_mlx_map *mlx)
{
	static int	i = 0;
	static int	n = 15;

	if (i == 0)
	{
		if (n == 15)
			ft_exit(mlx, 7);
		if (n == 8)
			ft_exit(mlx, 6);
		n--;
		if (n == 0)
		{
			i = 1;
			ft_exit(mlx, 1);
		}
	}
}

static void	ft_death(t_mlx_map *mlx)
{
	if (mlx->anim.death > 0 && mlx->anim.dir == 'l')
	{
		if (mlx->anim.death == 18)
			ft_hero_left2(mlx, 5);
		if (mlx->anim.death == 12)
			ft_hero_left2(mlx, 6);
		if (mlx->anim.death == 6)
			ft_hero_left2(mlx, 7);
	}
	else if (mlx->anim.death > 0 && mlx->anim.dir == 'r')
	{
		if (mlx->anim.death == 18)
			ft_hero_right2(mlx, 5);
		if (mlx->anim.death == 12)
			ft_hero_right2(mlx, 6);
		if (mlx->anim.death == 6)
			ft_hero_right2(mlx, 7);
	}
	mlx->anim.death -= 1;
	if (mlx->anim.death == 0)
		mlx->map.map[mlx->map.h_pos_y][mlx->map.h_pos_x] = '0';
}

int	ft_anim(t_mlx_map *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	if (mlx->anim.death > 0)
		ft_death(mlx);
	if (mlx->anim.col_flag > 0 && mlx->anim.dir == 'r')
		ft_pick_col_r(mlx);
	if (mlx->anim.col_flag > 0 && mlx->anim.dir == 'l')
		ft_pick_col_l(mlx);
	if (mlx->anim.step > 0)
		ft_step(mlx);
	if (mlx->anim.exit > 0)
		ft_exit_anim(mlx);
	if ((mlx->anim.up > 0 || mlx->anim.down > 0) && mlx->anim.dir == 'r')
		ft_up_down_r(mlx);
	if ((mlx->anim.up > 0 || mlx->anim.down > 0) && mlx->anim.dir == 'l')
		ft_up_down_l(mlx);
	if (mlx->map.coll == 0)
		ft_hole_anim(mlx);
	ft_anim_dang(mlx);
	ft_anim_col(mlx);
	ft_render(mlx);
	return (0);
}
