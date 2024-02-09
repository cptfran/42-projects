/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:11:06 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/23 15:54:05 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	draw_map(t_data *data)
{
	if (data->map->coll_count == 0)
		open_door(data);
	loop_vertical(data);
}

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
