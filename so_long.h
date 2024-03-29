/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:38:34 by sclam             #+#    #+#             */
/*   Updated: 2022/03/21 17:06:26 by sclam            ###   ########.fr       */
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
# include "libft/libft.h"
# include <mlx.h>

# define TILE 80
# define ENEMY_STEP_TICKS 30
# define STEP_TICKS 15

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'W'
}	t_tiletype;

typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		orig;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_enemy
{
	t_tile			*tile;
	char			dir;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_map
{
	char	**map;
	size_t	len;
	size_t	height;
	int		h_pos_x;
	int		h_pos_y;
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
	int		enemy_step;
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
	t_map		map;
	t_assets	assets;
	t_anim		anim;
	t_tile		**tilemap;
	t_tile		*hero;
	t_enemy		*enemy_list;
}				t_mlx_map;

void	map_checker(t_mlx_map *mlx);
void	init_map(char **argv, t_mlx_map *mlx);
void	ber(char *argv);
t_tile	**generate_tilemap(t_mlx_map *mlx);
void	error(t_mlx_map *mlx, int error, char *str);

void	move_up(t_mlx_map *mlx);
void	move_down(t_mlx_map *mlx);
void	move_left(t_mlx_map *mlx);
void	move_right(t_mlx_map *mlx);

void	danger(t_mlx_map *mlx, int n);
void	floor_asset(t_mlx_map *mlx);
void	hero_right2(t_mlx_map *mlx, int n);
void	hero_left2(t_mlx_map *mlx, int n);
void	wall(t_mlx_map *mlx);
void	hero_right(t_mlx_map *mlx, int n);
void	hero_left(t_mlx_map *mlx, int n);
void	collect(t_mlx_map *mlx, int n);
void	exit_asset(t_mlx_map *mlx, int n);
void	hero_exit(t_mlx_map *mlx, int n);
void	render(t_mlx_map *mlx);
void	init_assets(t_mlx_map *mlx);
int		anim(t_mlx_map *mlx);

t_enemy	*ft_lst_new(void);
t_enemy	*ft_lst_last(t_enemy *lst);
int		ft_lst_add_back(t_enemy **lst, t_enemy *new);

#endif /*SO_LONG_H*/