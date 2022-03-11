/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:42:35 by sclam             #+#    #+#             */
/*   Updated: 2022/03/10 18:43:22 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_tile	**alloc_tilemap(t_mlx_map *mlx)
{
	t_tile	**tilemap;
	int		i;

	tilemap = malloc(sizeof(t_tile *) * mlx->map.height + 1);
	if (!tilemap)
		return (NULL);
	i = 0;
	while (mlx->map.map[i])
	{
		tilemap[i] = malloc(sizeof(t_tile) * (ft_strlen(mlx->map.map[i]) + 1));
		if (!tilemap[i])
			return (ft_free_arr((void **)tilemap));
		i++;
	}
	return (tilemap);
}

static t_tiletype	define_tiletype(char c)
{
	if (c == '1')
		return (WALL);
	else if (c == 'C')
		return (COLLECTABLE);
	else if (c == 'P')
		return (PLAYER);
	else if (c == 'E')
		return (EXIT);
	else if (c == 'W')
		return (ENEMY_W);
	else if (c == 'S')
		return (ENEMY_S);
	else
		return (EMPTY);
}

static void	init_tile(t_tile **tilemap, int i, int j)
{
	tilemap[i][j].pos.x = j * TILE;
	tilemap[i][j].pos.y = i * TILE;
	if (i)
		tilemap[i][j].up = &tilemap[i - 1][j];
	if (tilemap[i + 1])
		tilemap[i][j].down = &tilemap[i + 1][j];
	if (j)
		tilemap[i][j].left = &tilemap[i][j - 1];
	tilemap[i][j].right = &tilemap[i][j + 1];
}

t_tile	**generate_tilemap(t_mlx_map *mlx)
{
	t_tile	**tilemap;
	int		i;
	int		j;

	tilemap = alloc_tilemap(mlx);
	if (!tilemap)
		return (NULL);
	i = 0;
	while (mlx->map.map[i])
	{
		j = 0;
		while (mlx->map.map[i][j])
		{
			tilemap[i][j].type = define_tiletype(mlx->map.map[i][j]);
			init_tile(tilemap, i, j);
			j++;
		}
		tilemap[i][j].type = 0;
		i++;
	}
	tilemap[i] = NULL;
	return (tilemap);
}
