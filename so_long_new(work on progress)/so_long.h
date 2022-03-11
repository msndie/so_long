/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:38:34 by sclam             #+#    #+#             */
/*   Updated: 2022/03/10 20:23:46 by sclam            ###   ########.fr       */
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

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY_W = 'W',
	ENEMY_S = 'S'
}	t_tiletype;

typedef struct s_tile
{
	t_tiletype	type;
	t_tiletype	og_type;
	t_vector	pos;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

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
	// void	*enemy;
}				t_assets;

typedef struct s_mlx_map {
	void		*mlx;
	void		*win;
	t_map		map;
	t_assets	assets;
	t_anim		anim;
	t_tile		**tilemap;
	t_tile		*hero;
}				t_mlx_map;

void	ft_map_checker(t_mlx_map *mlx);
void	ft_init_map(char **argv, t_mlx_map *mlx);
void	ft_ber(char *argv);
t_tile	**generate_tilemap(t_mlx_map *mlx);
void	ft_error(t_mlx_map *mlx, int error, char *str);

int		ft_check_w(t_mlx_map *mlx);
int		ft_check_s(t_mlx_map *mlx);
int		ft_check_a(t_mlx_map *mlx);
int		ft_check_d(t_mlx_map *mlx);

void	ft_floor(t_mlx_map *mlx);
void	ft_hero_right2(t_mlx_map *mlx, int n);
void	ft_hero_left2(t_mlx_map *mlx, int n);
void	ft_wall(t_mlx_map *mlx);
void	ft_hero_right(t_mlx_map *mlx, int n);
void	ft_hero_left(t_mlx_map *mlx, int n);
void	ft_collect(t_mlx_map *mlx, int n);
void	ft_exit(t_mlx_map *mlx, int n);
void	ft_render(t_mlx_map *mlx);
void	ft_init_assets(t_mlx_map *mlx);

#endif /*SO_LONG_H*/