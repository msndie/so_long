/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:50:14 by sclam             #+#    #+#             */
/*   Updated: 2022/05/31 18:40:49 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_draw_tile(t_mlx_map *mlx, int x, int y, t_tiletype t)
{
	if (t == WALL)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.wall, x, y);
	else if (t == EMPTY)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.floor, x, y);
	else if (t == COLLECTABLE)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.collect, x, y);
	else if (t == PLAYER)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.hero, x, y);
	else if (t == EXIT)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.exit, x, y);
	else if (t == ENEMY)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.enemy, x, y);
}


static void	ft_draw_score(t_mlx_map *mlx)
{
	char	*str;
	int		x;

	x = (mlx->map.len - 1) * TILE - TILE / 4;
	str = ft_itoa(mlx->map.moves);
	if (mlx->map.end_game == 0)
		mlx_string_put(mlx->mlx, mlx->win, x, 10, 0x00FFFFFF, str);
	if (mlx->map.end_game == 1)
		mlx_string_put(mlx->mlx, mlx->win, x, 10, 0x00FFFF00, str);
	if (mlx->map.end_game == 2)
		mlx_string_put(mlx->mlx, mlx->win, x, 10, 0x00FF0040, str);
	free(str);
}

void	ft_render(t_mlx_map *mlx)
{
	size_t		i;
	size_t		n;
	t_tiletype	type;

	i = 0;
	while (mlx->tilemap[i])
	{
		n = 0;
		while (mlx->tilemap[i][n].type)
		{
			type = mlx->tilemap[i][n].type;
			if (type == mlx->tilemap[i][n].orig)
				ft_draw_tile(mlx, n * TILE, i * TILE, type);
			else
			{
				ft_draw_tile(mlx, n * TILE, i * TILE, mlx->tilemap[i][n].orig);
				ft_draw_tile(mlx, n * TILE, i * TILE, type);
			}
			n++;
		}
		i++;
	}
	ft_draw_score(mlx);
}
