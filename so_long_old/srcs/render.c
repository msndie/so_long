/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:22:18 by sclam             #+#    #+#             */
/*   Updated: 2021/11/15 16:19:10 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_draw_tile(t_mlx_map *mlx, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.floor, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.collect, x, y);
	else if (c == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.floor, x, y);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.hero, x, y);
	}
	else if (c == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.exit, x, y);
	else if (c == 'S')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.enemy, x, y);
	else if (c == 'W')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.enemy, x, y);
}

static void	ft_draw_line(t_mlx_map *mlx, char *str, int i, int n)
{
	while (str[n] != '\0')
	{
		if (str[n] == '1')
			ft_draw_tile(mlx, n * mlx->tile, i * mlx->tile, '1');
		else if (str[n] == '0')
			ft_draw_tile(mlx, n * mlx->tile, i * mlx->tile, '0');
		else if (str[n] == 'C')
			ft_draw_tile(mlx, n * mlx->tile, i * mlx->tile, 'C');
		else if (str[n] == 'P')
			ft_draw_tile(mlx, n * mlx->tile, i * mlx->tile, 'P');
		else if (str[n] == 'E')
			ft_draw_tile(mlx, n * mlx->tile, i * mlx->tile, 'E');
		else if (str[n] == 'S')
			ft_draw_tile(mlx, n * mlx->tile, i * mlx->tile, 'S');
		else if (str[n] == 'W')
			ft_draw_tile(mlx, n * mlx->tile, i * mlx->tile, 'W');
		n++;
	}
}

static void	ft_draw_score(t_mlx_map *mlx)
{
	char	*str;
	int		x;

	x = (mlx->map.len - 1) * mlx->tile - mlx->tile / 4;
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
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (mlx->map.map[i])
	{
		ft_draw_line(mlx, mlx->map.map[i], i, n);
		i++;
	}
	ft_draw_score(mlx);
}
