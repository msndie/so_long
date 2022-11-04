/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:25:17 by sclam             #+#    #+#             */
/*   Updated: 2022/05/31 18:36:51 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
			ft_exit(mlx, 3);
		if (n == 8)
			ft_exit(mlx, 2);
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
		mlx->hero->type = EMPTY;
}

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
			ft_hero_exit(mlx, 2);
		if (mlx->anim.exit == 10)
			ft_hero_exit(mlx, 3);
		mlx->anim.exit -= 1;
		if (mlx->anim.exit == 0)
			ft_hero_exit(mlx, 1);
	}
	if (mlx->anim.exit > 0 && mlx->anim.dir == 'r')
	{
		if (mlx->anim.exit == 20)
			ft_hero_exit(mlx, 4);
		if (mlx->anim.exit == 10)
			ft_hero_exit(mlx, 5);
		mlx->anim.exit -= 1;
		if (mlx->anim.exit == 0)
			ft_hero_exit(mlx, 1);
	}
}

void	patrol(t_enemy *enemy, t_mlx_map *mlx)
{
	if (enemy->dir == 'W')
	{
		if (enemy->tile->up->type == EMPTY && enemy->tile->type != EMPTY)
		{
			enemy->tile->up->type = ENEMY;
			enemy->tile->type = EMPTY;
			enemy->tile = enemy->tile->up;
		}
		else if (enemy->tile->up->type == PLAYER)
		{
			enemy->tile->type = EMPTY;
			mlx->anim.death = 20;
			mlx->map.end_game = 2;
		}
		else
			enemy->dir = 'S';
	}
	else
	{
		if (enemy->tile->down->type == EMPTY && enemy->tile->type != EMPTY)
		{
			enemy->tile->down->type = ENEMY;
			enemy->tile->type = EMPTY;
			enemy->tile = enemy->tile->down;
		}
		else if (enemy->tile->down->type == PLAYER)
		{
			enemy->tile->type = EMPTY;
			mlx->anim.death = 20;
			mlx->map.end_game = 2;
		}
		else
			enemy->dir = 'W';
	}
}

void	move_enemy(t_mlx_map *mlx)
{
	t_enemy	*tmp;

	if (mlx->map.end_game != 0)
		return ;
	tmp = mlx->enemy_list;
	if (tmp)
		mlx->anim.enemy_step -= 1;
	if (mlx->anim.enemy_step == 0)
	{
		while (tmp)
		{
			patrol(tmp, mlx);
			tmp = tmp->next;
		}
		mlx->anim.enemy_step = 50;
	}
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
	ft_anim_col(mlx);
	if (mlx->map.end_game == 0)
		move_enemy(mlx);
	ft_anim_dang(mlx);
	ft_render(mlx);
	return (0);
}
