/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:08:54 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/01 15:18:01 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_wall(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->wall, data->map_x, data->map_y);
}

void	draw_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->floor, data->map_x, data->map_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->knight, data->map_x, data->map_y);
}

void	draw_exit(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->floor, data->map_x, data->map_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->door, data->map_x, data->map_y);
}

void	draw_collectible(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->floor, data->map_x, data->map_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sword, data->map_x, data->map_y);
}

void	open_door(t_data *data)
{
	data->door = mlx_xpm_file_to_image(data->mlx_ptr, DOOR_OPEN,
			&data->img_x, &data->img_y);
}
