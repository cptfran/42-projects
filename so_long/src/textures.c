/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:11:06 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 14:06:46 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
 * Function: load_images
 * ----------------------------
 *   Loads the images for the game. It uses the mlx_xpm_file_to_image function to load the images for the door,
 *   floor, knight, sword, and wall from XPM files. The images are stored in the data structure.
 *
 *   data: The game data.
 */
void	load_images(t_data *data)
{
	data->door = mlx_xpm_file_to_image(data->mlx_ptr, DOOR_CLOSED,
			&data->img_x, &data->img_y);
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &data->img_x,
			&data->img_y);
	data->knight = mlx_xpm_file_to_image(data->mlx_ptr, KNIGHT_R, &data->img_x,
			&data->img_y);
	data->sword = mlx_xpm_file_to_image(data->mlx_ptr, SWORD, &data->img_x,
			&data->img_y);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &data->img_x,
			&data->img_y);
}

/*
 * Function: draw_map
 * ----------------------------
 *   Draws the game map. If all collectibles have been collected, it opens the exit. Then it draws each row of the map.
 *
 *   data: The game data.
 */
void	draw_map(t_data *data)
{
	if (data->map->coll_count == 0)
		open_door(data);
	loop_vertical(data);
}

/*
 * Function: loop_vertical
 * ----------------------------
 *   Draws each row of the game map. It initializes the coordinates and then draws each row until it has drawn all rows.
 *
 *   data: The game data.
 */
void	loop_vertical(t_data *data)
{
	init_coordinates(data);
	while (data->map_y <= data->map->all_line_count * 64
		&& data->map->line_i <= data->map->all_line_count)
	{
		data->map_x = 0;
		draw_horizontal(data);
		data->map_y += 64;
		data->map->line_i++;
	}
}

/*
 * Function: draw_horizontal
 * ----------------------------
 *   Draws each tile in a row of the game map. It iterates over the tiles in the row, and if it finds a wall ('1'),
 *   a player ('P'), a collectible ('C'), an exit ('E'), or a floor ('0'), it draws the corresponding image.
 *
 *   data: The game data.
 */
void	draw_horizontal(t_data *data)
{
	while (data->map->full_map && data->map_x <= data->map->line_len * 64)
	{
		if (data->map->full_map[data->map->i] == 0)
			break ;
		if (data->map->full_map[data->map->i] == '\n')
		{
			data->map->i++;
			break ;
		}
		if (data->map->full_map[data->map->i] == '1')
			draw_wall(data);
		if (data->map->full_map[data->map->i] == '0')
			draw_floor(data);
		if (data->map->full_map[data->map->i] == 'P')
			draw_player(data);
		if (data->map->full_map[data->map->i] == 'E')
			draw_exit(data);
		if (data->map->full_map[data->map->i] == 'C')
			draw_collectible(data);
		data->map_x += 64;
		data->map->i++;
	}
}
