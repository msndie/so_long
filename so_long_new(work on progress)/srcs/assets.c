/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:45:57 by sclam             #+#    #+#             */
/*   Updated: 2022/03/12 15:24:13 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_wall(t_mlx_map *mlx)
{
	char	*path;
	int		img_width;
	int		img_height;
	void	*img;

	path = "assets/rock.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	mlx->assets.wall = img;
}

void	ft_hero_right(t_mlx_map *mlx, int n)
{
	char	*path;
	int		img_width;
	int		img_height;
	void	*img;

	if (n == 1)
		path = "assets/idle_right.xpm";
	if (n == 2)
		path = "assets/collect1_right.xpm";
	if (n == 3)
		path = "assets/collect2_right.xpm";
	if (n == 4)
		path = "assets/collect3_right.xpm";
	if (n == 5)
		path = "assets/collect4_right.xpm";
	if (n == 6)
		path = "assets/collect5_right.xpm";
	if (n == 7)
		path = "assets/move_right1.xpm";
	if (n == 8)
		path = "assets/move_right2.xpm";
	if (n == 9)
		path = "assets/move_right3.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	mlx->assets.hero = img;
}

void	ft_hero_left(t_mlx_map *mlx, int n)
{
	char	*path;
	int		img_width;
	int		img_height;
	void	*img;

	if (n == 1)
		path = "assets/idle_left.xpm";
	if (n == 2)
		path = "assets/collect1_left.xpm";
	if (n == 3)
		path = "assets/collect2_left.xpm";
	if (n == 4)
		path = "assets/collect3_left.xpm";
	if (n == 5)
		path = "assets/collect4_left.xpm";
	if (n == 6)
		path = "assets/collect5_left.xpm";
	if (n == 7)
		path = "assets/move_left1.xpm";
	if (n == 8)
		path = "assets/move_left2.xpm";
	if (n == 9)
		path = "assets/move_left3.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	mlx->assets.hero = img;
}

void	ft_collect(t_mlx_map *mlx, int n)
{
	char	*path;
	int		img_width;
	int		img_height;
	void	*img;

	if (n == 1)
		path = "assets/collect1.xpm";
	if (n == 2)
		path = "assets/collect2.xpm";
	if (n == 3)
		path = "assets/collect3.xpm";
	if (n == 4)
		path = "assets/collect4.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	mlx->assets.collect = img;
}

void	ft_hero_exit(t_mlx_map *mlx, int n)
{
	char	*path;
	int		img_width;
	int		img_height;
	void	*img;
	
	if (n == 1)
		path = "assets/exit.xpm";
	if (n == 2)
		path = "assets/exit1_left.xpm";
	if (n == 3)
		path = "assets/exit2_left.xpm";
	if (n == 4)
		path = "assets/exit1_right.xpm";
	if (n == 5)
		path = "assets/exit2_right.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	mlx->assets.hero = img;
}

void	ft_exit(t_mlx_map *mlx, int n)
{
	char	*path;
	int		img_width;
	int		img_height;
	void	*img;

	if (n == 1)
		path = "assets/exit.xpm";
	if (n == 2)
		path = "assets/exit1.xpm";
	if (n == 3)
		path = "assets/exit2.xpm";
	if (n == 4)
		path = "assets/exit3.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	mlx->assets.exit = img;
}
