/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:46:05 by sclam             #+#    #+#             */
/*   Updated: 2022/05/31 18:38:17 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	danger(t_mlx_map *mlx, int n)
{
	char	*path;
	int		img_width;
	int		img_height;
	void	*img;

	if (n == 0)
		path = "assets/danger1.xpm";
	if (n == 1)
		path = "assets/danger2.xpm";
	if (n == 2)
		path = "assets/danger3.xpm";
	if (n == 3)
		path = "assets/danger4.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	mlx->assets.enemy = img;
}

void	hero_left2(t_mlx_map *mlx, int n)
{
	char	*path;
	int		img_width;
	int		img_height;
	void	*img;

	if (n == 1)
		path = "assets/up1_left.xpm";
	if (n == 2)
		path = "assets/up2_left.xpm";
	if (n == 3)
		path = "assets/down1_left.xpm";
	if (n == 4)
		path = "assets/down2_left.xpm";
	if (n == 5)
		path = "assets/death1_left.xpm";
	if (n == 6)
		path = "assets/death2_left.xpm";
	if (n == 7)
		path = "assets/death3_left.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	mlx->assets.hero = img;
}

void	hero_right2(t_mlx_map *mlx, int n)
{
	char	*path;
	int		img_width;
	int		img_height;
	void	*img;

	if (n == 1)
		path = "assets/up1_right.xpm";
	if (n == 2)
		path = "assets/up2_right.xpm";
	if (n == 3)
		path = "assets/down1_right.xpm";
	if (n == 4)
		path = "assets/down2_right.xpm";
	if (n == 5)
		path = "assets/death1_right.xpm";
	if (n == 6)
		path = "assets/death2_right.xpm";
	if (n == 7)
		path = "assets/death3_right.xpm";
	if (n == 8)
		path = "assets/death4.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	mlx->assets.hero = img;
}

void	floor_asset(t_mlx_map *mlx)
{
	char	*path;
	int		img_width;
	int		img_height;
	void	*img;

	path = "assets/grass.xpm";
	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	mlx->assets.floor = img;
}

void	init_assets(t_mlx_map *mlx)
{
	wall(mlx);
	hero_right(mlx, 1);
	floor_asset(mlx);
	exit_asset(mlx, 4);
	collect(mlx, 1);
	danger(mlx, 0);
	mlx->anim.enemy_step = ENEMY_STEP_TICKS;
	mlx->map.end_game = 0;
	mlx->anim.anim = 40;
	mlx->anim.dang = 40;
	mlx->anim.step = 0;
	mlx->anim.col_flag = 0;
	mlx->map.moves = 0;
	mlx->anim.dir = 'r';
	mlx->anim.exit = 0;
	mlx->anim.death = 0;
}
