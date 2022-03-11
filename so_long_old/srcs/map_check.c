/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:45:00 by sclam             #+#    #+#             */
/*   Updated: 2021/11/16 15:48:02 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	ft_checker_helper(char *str, int n, t_mlx_map *mlx)
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
		ft_error(mlx, -1, "Map error");
	}
	if (n == 2)
	{
		if (str[0] == '1' && str[ft_strlen(str) - 2] == '1')
			return ;
		ft_error(mlx, -1, "Map error");
	}
}

static void	ft_walls_checker(t_mlx_map *mlx)
{
	size_t	i;

	i = 0;
	while (mlx->map.map[i])
	{
		if (i == 0)
			ft_checker_helper(mlx->map.map[i], 1, mlx);
		else if (i == mlx->map.height - 1)
			ft_checker_helper(mlx->map.map[i], 1, mlx);
		else
			ft_checker_helper(mlx->map.map[i], 2, mlx);
		i++;
	}
}

void	ft_ber(char *argv)
{
	size_t	i;

	i = ft_strlen(argv);
	if (ft_strncmp(argv + (i - 4), ".ber", 4) == 0 && i - 4 != 0)
		return ;
	printf("Wrong extension\n");
	exit(EXIT_FAILURE);
}

void	ft_map_checker(t_mlx_map *mlx)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	mlx->map.h_pos_x = 0;
	mlx->map.h_pos_y = 0;
	mlx->map.coll = 0;
	mlx->map.ex = 0;
	mlx->map.enemy_s = 0;
	mlx->map.enemy_w = 0;
	ft_walls_checker(mlx);
	ft_find_pos(mlx, i, n);
	ft_enemy_pos(mlx);
	if (mlx->map.coll == 0 || mlx->map.ex == 0 || mlx->map.h_pos_x == 0
		|| mlx->map.h_pos_y == 0)
		ft_error(mlx, -1, "Map error");
}
