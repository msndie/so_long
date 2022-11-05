/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:36:55 by sclam             #+#    #+#             */
/*   Updated: 2022/03/10 18:41:46 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_len(t_mlx_map *mlx, size_t i)
{
	size_t	n;

	n = 0;
	mlx->map.len = ft_strlen(mlx->map.map[n]);
	while (n < i - 1)
	{
		if (ft_strlen(mlx->map.map[n++]) != mlx->map.len)
			error(mlx, -1, "Map error");
	}
	if (mlx->map.map[n][ft_strlen(mlx->map.map[n]) - 1] != '\n')
	{
		if (ft_strlen(mlx->map.map[n]) != mlx->map.len - 1)
			error(mlx, -1, "Map error");
	}
	if (mlx->map.map[n][ft_strlen(mlx->map.map[n]) - 1] == '\n')
	{
		if (ft_strlen(mlx->map.map[n]) != mlx->map.len)
			error(mlx, -1, "Map error");
	}
}

void	init_map(char **argv, t_mlx_map *mlx)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
		error(mlx, 1, "Open");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(mlx, 1, "Open");
	mlx->map.map = (char **)malloc(sizeof(char **));
	if (!mlx->map.map)
		error(mlx, 1, "Malloc");
	mlx->map.map[i] = get_next_line(fd);
	if (!mlx->map.map[i])
		error(mlx, -1, "Map error");
	while (mlx->map.map[i])
	{
		mlx->map.map = ft_realloc(mlx->map.map, sizeof(char **) * (++i + 1));
		if (!mlx->map.map)
			error(mlx, 1, "Malloc");
		mlx->map.map[i] = get_next_line(fd);
	}
	check_len(mlx, i);
	mlx->map.height = i;
	close(fd);
}

void	ber(char *argv)
{
	size_t	i;

	i = ft_strlen(argv);
	if (ft_strncmp(argv + (i - 4), ".ber", 4) == 0 && i - 4 != 0)
		return ;
	printf("Wrong extension\n");
	exit(EXIT_FAILURE);
}
