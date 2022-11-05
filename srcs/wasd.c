/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:22:25 by sclam             #+#    #+#             */
/*   Updated: 2022/03/21 17:06:12 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_mlx_map *mlx)
{
	mlx->anim.up = 10;
	if (mlx->hero->up->type == COLLECTABLE)
	{
		mlx->anim.up = 0;
		mlx->map.coll -= 1;
		mlx->anim.col_flag = 35;
	}
	else if (mlx->hero->up->type == EXIT)
	{
		if (mlx->map.coll == 0)
		{
			mlx->hero->up->orig = EMPTY;
			mlx->map.end_game = 1;
			mlx->anim.exit = 20;
			mlx->anim.up = 0;
		}
	}
	else if (mlx->hero->up->type == ENEMY)
	{
		mlx->anim.up = 0;
		mlx->map.end_game = 2;
		mlx->anim.death = 20;
	}
	if (mlx->hero->orig != EXIT)
		mlx->hero->type = EMPTY;
	else
		mlx->hero->type = EXIT;
	mlx->hero->up->type = PLAYER;
	mlx->hero = mlx->hero->up;
}

void	move_down(t_mlx_map *mlx)
{
	mlx->anim.down = 10;
	if (mlx->hero->down->type == COLLECTABLE)
	{
		mlx->anim.down = 0;
		mlx->map.coll -= 1;
		mlx->anim.col_flag = 35;
	}
	else if (mlx->hero->down->type == EXIT)
	{
		if (mlx->map.coll == 0)
		{
			mlx->hero->down->orig = EMPTY;
			mlx->anim.down = 0;
			mlx->map.end_game = 1;
			mlx->anim.exit = 20;
		}
	}
	else if (mlx->hero->down->type == ENEMY)
	{
		mlx->anim.down = 0;
		mlx->map.end_game = 2;
		mlx->anim.death = 20;
	}
	if (mlx->hero->orig != EXIT)
		mlx->hero->type = EMPTY;
	else
		mlx->hero->type = EXIT;
	mlx->hero->down->type = PLAYER;
	mlx->hero = mlx->hero->down;
}

void	move_left(t_mlx_map *mlx)
{
	mlx->anim.dir = 'l';
	mlx->anim.step = STEP_TICKS;
	if (mlx->hero->left->type == COLLECTABLE)
	{
		mlx->map.coll -= 1;
		mlx->anim.step = 0;
		mlx->anim.col_flag = 35;
	}
	else if (mlx->hero->left->type == EXIT)
	{
		if (mlx->map.coll == 0)
		{
			mlx->anim.step = 0;
			mlx->map.end_game = 1;
			mlx->anim.exit = 20;
		}
	}
	else if (mlx->hero->left->type == ENEMY)
	{
		mlx->anim.step = 0;
		mlx->map.end_game = 2;
		mlx->anim.death = 20;
	}
	if (mlx->hero->orig != EXIT)
		mlx->hero->type = EMPTY;
	else
		mlx->hero->type = EXIT;
	mlx->hero->left->type = PLAYER;
	mlx->hero = mlx->hero->left;
}

void	move_right(t_mlx_map *mlx)
{
	mlx->anim.dir = 'r';
	mlx->anim.step = STEP_TICKS;
	if (mlx->hero->right->type == COLLECTABLE)
	{
		mlx->anim.step = 0;
		mlx->map.coll -= 1;
		mlx->anim.col_flag = 35;
	}
	else if (mlx->hero->right->type == EXIT)
	{
		if (mlx->map.coll == 0)
		{
			mlx->anim.step = 0;
			mlx->map.end_game = 1;
			mlx->anim.exit = 20;
		}
	}
	else if (mlx->hero->right->type == ENEMY)
	{
		mlx->anim.step = 0;
		mlx->map.end_game = 2;
		mlx->anim.death = 20;
	}
	if (mlx->hero->orig != EXIT)
		mlx->hero->type = EMPTY;
	else
		mlx->hero->type = EXIT;
	mlx->hero->right->type = PLAYER;
	mlx->hero = mlx->hero->right;
}
