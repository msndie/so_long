/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 06:14:55 by sclam             #+#    #+#             */
/*   Updated: 2021/11/15 16:20:08 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <mlx.h>

typedef struct s_map
{
	char	**map;
	size_t	len;
	size_t	height;
	int		h_pos_x;
	int		h_pos_y;
	int		e1_pos_x;
	int		e1_pos_y;
	int		e2_pos_x;
	int		e2_pos_y;
	int		enemy_w;
	int		enemy_s;
	int		end_game;
	int		coll;
	int		ex;
	int		moves;
}				t_map;

typedef struct s_anim
{
	int		col_flag;
	int		anim;
	int		step;
	int		exit;
	int		up;
	int		down;
	int		death;
	int		dang;
	char	dir;
	char	enemy_dir1;
	char	enemy_dir2;
}				t_anim;

typedef struct s_assets
{
	void	*hero;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collect;
	void	*enemy;
}				t_assets;

typedef struct s_mlx_map {
	void		*mlx;
	void		*win;
	int			tile;
	t_map		map;
	t_assets	assets;
	t_anim		anim;
}				t_mlx_map;

void	ft_init_map(char **argv, t_mlx_map *mlx);
void	ft_render(t_mlx_map *mlx);
int		ft_check_w(t_mlx_map *mlx);
int		ft_check_s(t_mlx_map *mlx);
int		ft_check_d(t_mlx_map *mlx);
int		ft_check_a(t_mlx_map *mlx);
void	ft_map_checker(t_mlx_map *mlx);
void	ft_floor(t_mlx_map *mlx);
void	ft_init_assets(t_mlx_map *mlx);
void	ft_wall(t_mlx_map *mlx);
void	ft_hero_right(t_mlx_map *mlx, int n);
void	ft_hero_right2(t_mlx_map *mlx, int n);
void	ft_hero_left(t_mlx_map *mlx, int n);
void	ft_hero_left2(t_mlx_map *mlx, int n);
void	ft_collect(t_mlx_map *mlx, int n);
void	ft_exit(t_mlx_map *mlx, int n);
void	ft_pick_col_l(t_mlx_map *mlx);
void	ft_pick_col_r(t_mlx_map *mlx);
void	ft_anim_col(t_mlx_map *mlx);
void	ft_step(t_mlx_map *mlx);
void	ft_exit_anim(t_mlx_map *mlx);
int		ft_anim(t_mlx_map *mlx);
void	ft_find_pos(t_mlx_map *mlx, int i, int n);
void	ft_error(t_mlx_map *mlx, int error, char *str);
void	ft_danger(t_mlx_map *mlx, int n);
void	ft_patrol_s(t_mlx_map *mlx);
void	ft_patrol_w(t_mlx_map *mlx);
void	ft_enemy_pos(t_mlx_map *mlx);
int		ft_danger_a(t_mlx_map *mlx);
int		ft_danger_s(t_mlx_map *mlx);
int		ft_danger_d(t_mlx_map *mlx);
int		ft_danger_w(t_mlx_map *mlx);
void	ft_anim_dang(t_mlx_map *mlx);
void	ft_ber(char *argv);

#endif /*SO_LONG_H*/