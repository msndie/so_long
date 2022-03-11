/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:22:25 by sclam             #+#    #+#             */
/*   Updated: 2022/03/10 20:22:51 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_w(t_mlx_map *mlx)
{
	if (mlx->hero->up->type == WALL)
		return (-1);
	else if (mlx->hero->up->type == EMPTY)
	{
		mlx->hero->up->type = PLAYER;
		mlx->hero->type = EMPTY;
		mlx->hero = mlx->hero->up;
	}
	else if (mlx->hero->up->type == COLLECTABLE)
	{
		mlx->hero->up->type = PLAYER;
		mlx->hero->type = EMPTY;
		mlx->hero = mlx->hero->up;
		mlx->map.coll -= 1;
	}
	else if (mlx->hero->up->type == EXIT)
	{
		if (mlx->map.coll == 0)
		{
			mlx->hero->type = EMPTY;
			mlx->map.end_game = 1;
		}
	}
	return (0);
}

int	ft_check_s(t_mlx_map *mlx)
{
	if (mlx->hero->down->type == WALL)
		return (-1);
	else if (mlx->hero->down->type == EMPTY)
	{
		mlx->hero->down->type = PLAYER;
		mlx->hero->type = EMPTY;
		mlx->hero = mlx->hero->down;
	}
	else if (mlx->hero->down->type == COLLECTABLE)
	{
		mlx->hero->down->type = PLAYER;
		mlx->hero->type = EMPTY;
		mlx->hero = mlx->hero->down;
		mlx->map.coll -= 1;
	}
	else if (mlx->hero->down->type == EXIT)
	{
		
	}
	return (0);
}

int	ft_check_a(t_mlx_map *mlx)
{
	if (mlx->hero->left->type == WALL)
		return (-1);
	else if (mlx->hero->left->type == EMPTY)
	{
		mlx->hero->left->type = PLAYER;
		mlx->hero->type = EMPTY;
		mlx->hero = mlx->hero->left;
	}
	else if (mlx->hero->left->type == COLLECTABLE)
	{
		mlx->hero->left->type = PLAYER;
		mlx->hero->type = EMPTY;
		mlx->hero = mlx->hero->left;
		mlx->map.coll -= 1;
	}
	else if (mlx->hero->left->type == EXIT)
	{
		
	}
	return (0);
}

int	ft_check_d(t_mlx_map *mlx)
{
	if (mlx->hero->right->type == WALL)
		return (-1);
	else if (mlx->hero->right->type == EMPTY)
	{
		mlx->hero->right->type = PLAYER;
		mlx->hero->type = EMPTY;
		mlx->hero = mlx->hero->right;
	}
	else if (mlx->hero->right->type == COLLECTABLE)
	{
		mlx->hero->right->type = PLAYER;
		mlx->hero->type = EMPTY;
		mlx->hero = mlx->hero->right;
		mlx->map.coll -= 1;
	}
	else if (mlx->hero->right->type == EXIT)
	{

	}
	return (0);
}
