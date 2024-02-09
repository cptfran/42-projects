/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:42:39 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/23 15:02:26 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	keypress(int keysymbol, t_data *data)
{
	if (keysymbol == ESC)
		close_game(data);
	if (keysymbol == A && move_left(data->map, data))
	{
		change_knight_image(KNIGHT_L_2, data);
		draw_map(data);
	}
	if (keysymbol == D && move_right(data->map, data))
	{
		change_knight_image(KNIGHT_R_2, data);
		draw_map(data);
	}
	if (keysymbol == W && move_up(data->map, data))
	{
		change_knight_image(KNIGHT_U, data);
		draw_map(data);
	}
	if (keysymbol == S && move_down(data->map, data))
	{
		change_knight_image(KNIGHT_D, data);
		draw_map(data);
	}
	return (0);
}

int	keyrelease(int keysymbol, t_data *data)
{
	if (keysymbol == A)
	{
		change_knight_image(KNIGHT_L, data);
		draw_map(data);
	}
	if (keysymbol == D)
	{
		change_knight_image(KNIGHT_R, data);
		draw_map(data);
	}
	if (keysymbol == W)
	{
		change_knight_image(KNIGHT_R, data);
		draw_map(data);
	}
	if (keysymbol == S)
	{
		change_knight_image(KNIGHT_R, data);
		draw_map(data);
	}
	return (0);
}

int	move_left(t_map *map, t_data *data)
{
	if (map->full_map[map->player_i - 1] == '1'
		|| (map->full_map[map->player_i - 1] == 'E' && map->coll_count != 0))
		return (0);
	else if (map->full_map[map->player_i - 1] == 'C')
	{
		map->full_map[map->player_i - 1] = 'P';
		map->full_map[map->player_i] = '0';
		map->player_i--;
		map->coll_count--;
	}
	else if (map->full_map[map->player_i - 1] == '0')
	{
		map->full_map[map->player_i - 1] = 'P';
		map->full_map[map->player_i] = '0';
		map->player_i--;
	}
	else if (map->full_map[map->player_i - 1] == 'E' && map->coll_count == 0)
	{
		map->full_map[map->player_i - 1] = 'P';
		map->full_map[map->player_i] = '0';
		close_game(data);
	}
	return (ft_printf("moves: %i\n", ++data->move_count), 1);
}

int	move_right(t_map *map, t_data *data)
{
	if (map->full_map[map->player_i + 1] == '1'
		|| (map->full_map[map->player_i + 1] == 'E' && map->coll_count != 0))
		return (0);
	else if (map->full_map[map->player_i + 1] == 'C')
	{
		map->full_map[map->player_i + 1] = 'P';
		map->full_map[map->player_i] = '0';
		map->player_i++;
		map->coll_count--;
	}
	else if (map->full_map[map->player_i + 1] == '0')
	{
		map->full_map[map->player_i + 1] = 'P';
		map->full_map[map->player_i] = '0';
		map->player_i++;
	}
	else if (map->full_map[map->player_i + 1] == 'E' && map->coll_count == 0)
	{
		map->full_map[map->player_i + 1] = 'P';
		map->full_map[map->player_i] = '0';
		close_game(data);
	}
	return (ft_printf("moves: %i\n", ++data->move_count), 1);
}

int	move_up(t_map *map, t_data *data)
{
	if (map->full_map[map->player_i - map->line_len - 1] == '1'
		|| (map->full_map[map->player_i - map->line_len - 1] == 'E'
			&& map->coll_count != 0))
		return (0);
	else if (map->full_map[map->player_i - map->line_len - 1] == 'C')
	{
		map->full_map[map->player_i - map->line_len - 1] = 'P';
		map->full_map[map->player_i] = '0';
		map->player_i = map->player_i - map->line_len - 1;
		map->coll_count--;
	}
	else if (map->full_map[map->player_i - map->line_len - 1] == '0')
	{
		map->full_map[map->player_i - map->line_len - 1] = 'P';
		map->full_map[map->player_i] = '0';
		map->player_i = map->player_i - map->line_len - 1;
	}
	else if (map->full_map[map->player_i - map->line_len - 1] == 'E'
		&& map->coll_count == 0)
	{
		map->full_map[map->player_i - map->line_len - 1] = 'P';
		map->full_map[map->player_i] = '0';
		close_game(data);
	}
	return (ft_printf("moves: %i\n", ++data->move_count), 1);
}
