/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:58:20 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/23 14:59:27 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_down(t_map *map, t_data *data)
{
	if (map->full_map[map->player_i + map->line_len + 1] == '1'
		|| (map->full_map[map->player_i + map->line_len + 1] == 'E'
			&& map->coll_count != 0))
		return (0);
	else if (map->full_map[map->player_i + map->line_len + 1] == 'C')
	{
		map->full_map[map->player_i + map->line_len + 1] = 'P';
		map->full_map[map->player_i] = '0';
		map->player_i = map->player_i + map->line_len + 1;
		map->coll_count--;
	}
	else if (map->full_map[map->player_i + map->line_len + 1] == '0')
	{
		map->full_map[map->player_i + map->line_len + 1] = 'P';
		map->full_map[map->player_i] = '0';
		map->player_i = map->player_i + map->line_len + 1;
	}
	else if (map->full_map[map->player_i + map->line_len + 1] == 'E'
		&& map->coll_count == 0)
	{
		map->full_map[map->player_i + map->line_len + 1] = 'P';
		map->full_map[map->player_i] = '0';
		close_game(data);
	}
	return (ft_printf("moves: %i\n", ++data->move_count), 1);
}
