/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:24:39 by sclam             #+#    #+#             */
/*   Updated: 2021/11/16 18:07:37 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_check_char(t_mlx_map *mlx, int i, int n)
{
	char	c;

	c = mlx->map.map[i][n];
	if (c == 'W')
	{
		mlx->map.e1_pos_x = n;
		mlx->map.e1_pos_y = i;
		mlx->map.enemy_w += 1;
		if (mlx->map.enemy_w > 1)
			ft_error(mlx, -1, "Map error");
	}
	if (c == 'S')
	{
		mlx->map.e2_pos_x = n;
		mlx->map.e2_pos_y = i;
		mlx->map.enemy_s += 1;
		if (mlx->map.enemy_s > 1)
			ft_error(mlx, -1, "Map error");
	}
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C' && c != '\n'
		&& c != 'W' && c != 'S')
		ft_error(mlx, -1, "Map error");
	return (0);
}

void	ft_find_pos(t_mlx_map *mlx, int i, int n)
{
	while (mlx->map.map[i])
	{
		while (mlx->map.map[i][n])
		{
			ft_check_char(mlx, i, n);
			if (mlx->map.map[i][n] == 'P')
			{
				if (mlx->map.h_pos_x != 0 || mlx->map.h_pos_y != 0)
					ft_error(mlx, -1, "Map error");
				mlx->map.h_pos_x = n;
				mlx->map.h_pos_y = i;
			}
			if (mlx->map.map[i][n] == 'C')
				mlx->map.coll += 1;
			if (mlx->map.map[i][n] == 'E')
				mlx->map.ex += 1;
			n++;
		}
		n = 0;
		i++;
	}
}

static void	ft_check_len(t_mlx_map *mlx, size_t i)
{
	size_t	n;

	n = 0;
	mlx->map.len = ft_strlen(mlx->map.map[n]);
	while (n < i - 1)
	{
		if (ft_strlen(mlx->map.map[n++]) != mlx->map.len)
			ft_error(mlx, -1, "Map error");
	}
	if (mlx->map.map[n][ft_strlen(mlx->map.map[n]) - 1] != '\n')
	{
		if (ft_strlen(mlx->map.map[n]) != mlx->map.len - 1)
			ft_error(mlx, -1, "Map error");
	}
	if (mlx->map.map[n][ft_strlen(mlx->map.map[n]) - 1] == '\n')
	{
		if (ft_strlen(mlx->map.map[n]) != mlx->map.len)
			ft_error(mlx, -1, "Map error");
	}
}

void	ft_init_map(char **argv, t_mlx_map *mlx)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
		ft_error(mlx, 1, "Open");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(mlx, 1, "Open");
	mlx->map.map = (char **)malloc(sizeof(char **));
	if (!mlx->map.map)
		ft_error(mlx, 1, "Malloc");
	mlx->map.map[i] = get_next_line(fd);
	if (!mlx->map.map[i])
		ft_error(mlx, -1, "Map error");
	while (mlx->map.map[i])
	{
		mlx->map.map = ft_realloc(mlx->map.map, sizeof(char **) * (++i + 1));
		if (!mlx->map.map)
			ft_error(mlx, 1, "Malloc");
		mlx->map.map[i] = get_next_line(fd);
	}
	ft_check_len(mlx, i);
	mlx->map.height = i;
	close(fd);
}
