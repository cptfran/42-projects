/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:36:19 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/01 16:34:01 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

// TEXTURES

# define DOOR_CLOSED "./textures/door_closed.xpm"
# define DOOR_OPEN "./textures/door_open.xpm"
# define FLOOR "./textures/floor.xpm"
# define KNIGHT_R "./textures/knight_r.xpm"
# define KNIGHT_R_2 "./textures/knight_r_2.xpm"
# define KNIGHT_L "./textures/knight_l.xpm"
# define KNIGHT_L_2 "./textures/knight_l_2.xpm"
# define KNIGHT_U "./textures/knight_u.xpm"
# define KNIGHT_D "./textures/knight_d.xpm"
# define SWORD "./textures/sword.xpm"
# define WALL "./textures/wall.xpm"

// KEYS

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

// SET NEW INDEXES FOR PATH CHECKING STRUCT

typedef struct s_i
{
	int	t;
	int	b;
	int	l;
	int	r;
}	t_i;

// MAP CHECKER STRUCT

typedef struct s_map
{
	char	*full_map;
	char	*tmp_map;
	char	*map_cat;
	char	*line;
	int		fd;
	int		map_len;
	int		all_line_count;
	int		mid_line_count;
	int		first_line_len;
	int		line_len;
	int		i;
	int		line_i;
	int		player_count;
	int		player_i;
	int		exit_count;
	int		t;
	int		b;
	int		l;
	int		r;
	int		coll_count;
	int		coll_i;
	char	c;
}	t_map;

// GAME DATA STRUCT

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		img_x;
	int		img_y;
	void	*door;
	void	*floor;
	void	*knight;
	void	*sword;
	void	*wall;
	int		move_count;
	int		map_x;
	int		map_y;
	t_map	*map;
}	t_data;

// MAP CHECKER FUNCTIONS (map.c, map_2.c, map_3.c)

int		check_map(char *map_file, t_map *map);
int		read_map(char *map_file, t_map *map);
int		check_walls(t_map *map);
int		check_top_wall(t_map *map);
int		check_mid_walls(t_map *map);
int		check_bot_wall(t_map *map);
int		check_rect(t_map *map);
int		check_player(t_map *map);
int		check_exit(t_map *map);
int		check_path(t_map *map);
int		check_floor_p(t_map *map, t_i i);
int		check_floor_c(t_map *map, t_i i);
int		check_collectible(t_map *map);
int		check_size(t_map *map);
int		check_wrong_char(t_map *map);

// UTILS FUNCTIONS (utils.c, utils_2.c, utils_3.c, utils_4.c)

void	init_hooks(t_data *data);
int		close_game(t_data *data);
int		line_loop(t_map *map);
int		find_player_i(t_map *map);
void	init_checkers(t_map *map, int index, char c, t_i *i);
t_i		init_i(int top, int bot, int left, int right);
int		not_wall(t_map *map, int side);
int		not_wall_or_exit(t_map *map, int side);
int		surrounded(t_map *map, t_i i);
void	init_coordinates(t_data *data);
void	draw_wall(t_data *data);
void	draw_player(t_data *data);
void	draw_exit(t_data *data);
void	draw_collectible(t_data *data);
void	open_door(t_data *data);
void	draw_floor(t_data *data);
void	change_knight_image(char *filename, t_data *data);

// TEXTURES FUNCTIONS (textures.c)

void	load_images(t_data *data);
void	draw_map(t_data *data);
void	loop_vertical(t_data *data);
void	draw_horizontal(t_data *data);

// CONTROLS FUNCTIONS (controls.c, controls_2.c)

int		keypress(int keysymbol, t_data *data);
int		keyrelease(int keysymbol, t_data *data);
int		move_left(t_map *map, t_data *data);
int		move_right(t_map *map, t_data *data);
int		move_up(t_map *map, t_data *data);
int		move_down(t_map *map, t_data *data);

#endif