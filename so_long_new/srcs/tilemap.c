/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:42:35 by sclam             #+#    #+#             */
/*   Updated: 2022/05/31 18:41:16 by sclam            ###   ########.fr       */
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
		return (ENEMY);
	else if (c == 'S')
		return (ENEMY);
	else
		return (EMPTY);
}

static t_tiletype	define_orig_tiletype(t_tiletype type)
{
	if (type == WALL)
		return (WALL);
	else if (type == COLLECTABLE)
		return (EMPTY);
	else if (type == PLAYER)
		return (EMPTY);
	else if (type == EXIT)
		return (EXIT);
	else if (type == ENEMY)
		return (EMPTY);
	else
		return (EMPTY);
}

static void	init_tile(t_tile **tilemap, int i, int j)
{
	if (i)
		tilemap[i][j].up = &tilemap[i - 1][j];
	if (tilemap[i + 1])
		tilemap[i][j].down = &tilemap[i + 1][j];
	if (j)
		tilemap[i][j].left = &tilemap[i][j - 1];
	tilemap[i][j].right = &tilemap[i][j + 1];
}

void	add_enemy(t_mlx_map *mlx, int i, int j, t_tile *tile)
{
	t_enemy	*tmp;

	if (ft_lst_add_back(&mlx->enemy_list, ft_lst_new()) == -1)
	{
		ft_putstr_fd("We lose one enemy because of malloc(((\n", 2);
		mlx->tilemap[i][j].type = EMPTY;
		return ;
	}
	tmp = ft_lst_last(mlx->enemy_list);
	if (mlx->map.map[i][j] == 'W')
		tmp->dir = 'W';
	else
		tmp->dir = 'S';
	tmp->tile = tile;
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
	mlx->enemy_list = NULL;
	while (mlx->map.map[i])
	{
		j = -1;
		while (mlx->map.map[i][++j])
		{
			tilemap[i][j].type = define_tiletype(mlx->map.map[i][j]);
			tilemap[i][j].orig = define_orig_tiletype(tilemap[i][j].type);
			init_tile(tilemap, i, j);
			if (mlx->map.map[i][j] == 'W' || mlx->map.map[i][j] == 'S')
				add_enemy(mlx, i, j, &tilemap[i][j]);
		}
		tilemap[i][j].type = 0;
		i++;
	}
	tilemap[i] = NULL;
	return (tilemap);
}
