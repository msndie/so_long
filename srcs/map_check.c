/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:38:08 by sclam             #+#    #+#             */
/*   Updated: 2022/03/12 17:05:07 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	checker_helper(char *str, int n, t_mlx_map *mlx)
{
	size_t	i;

	i = 0;
	if (n == 1)
	{
		if (str[ft_strlen(str) - 1] == '\n')
		{
			while (str[i] == '1')
				i++;
			if (i == ft_strlen(str) - 1)
				return ;
		}
		else if (str[ft_strlen(str) - 1] == '1')
		{
			if (str[0] == '1' && str[ft_strlen(str) - 1] == '1')
				return ;
		}
		error(mlx, -1, "Map error");
	}
	if (n == 2)
	{
		if (str[0] == '1' && str[ft_strlen(str) - 2] == '1')
			return ;
		error(mlx, -1, "Map error");
	}
}

static void	walls_checker(t_mlx_map *mlx)
{
	size_t	i;

	i = 0;
	while (mlx->map.map[i])
	{
		if (i == 0)
			checker_helper(mlx->map.map[i], 1, mlx);
		else if (i == mlx->map.height - 1)
			checker_helper(mlx->map.map[i], 1, mlx);
		else
			checker_helper(mlx->map.map[i], 2, mlx);
		i++;
	}
}

static int	check_char(t_mlx_map *mlx, int i, int n)
{
	char	c;

	c = mlx->map.map[i][n];
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C' && c != '\n'
		&& c != 'W' && c != 'S')
		error(mlx, -1, "Map error");
	return (0);
}

static void	find_pos(t_mlx_map *mlx, int i, int n)
{
	while (mlx->map.map[i])
	{
		while (mlx->map.map[i][n])
		{
			check_char(mlx, i, n);
			if (mlx->map.map[i][n] == 'P')
			{
				if (mlx->map.h_pos_x != 0 || mlx->map.h_pos_y != 0)
					error(mlx, -1, "Map error");
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

void	map_checker(t_mlx_map *mlx)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	mlx->map.h_pos_x = 0;
	mlx->map.h_pos_y = 0;
	mlx->map.coll = 0;
	mlx->map.ex = 0;
	walls_checker(mlx);
	find_pos(mlx, i, n);
	if (mlx->map.coll == 0 || mlx->map.ex == 0 || mlx->map.h_pos_x == 0
		|| mlx->map.h_pos_y == 0)
		error(mlx, -1, "Map error");
}
