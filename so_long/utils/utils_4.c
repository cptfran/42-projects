/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:10:15 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/01 15:18:05 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_floor(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->floor, data->map_x, data->map_y);
}

void	change_knight_image(char *filename, t_data *data)
{
	data->knight = mlx_xpm_file_to_image(data->mlx_ptr, filename, &data->img_x,
			&data->img_y);
}
