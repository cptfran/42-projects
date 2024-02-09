/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:53:54 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/01 16:22:05 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_bot_wall(t_map *map)
{
	if (map->full_map[map->i] == '\n')
		map->i++;
	while (map->full_map[map->i] != '\n' && map->full_map[map->i])
	{
		if (map->full_map[map->i++] != '1')
			return (free(map->full_map), 0);
	}
	return (1);
}

int	check_rect(t_map *map)
{
	map->i = 0;
	map->first_line_len = 0;
	while (map->full_map[map->i] != '\n' && map->full_map[map->i++])
		map->first_line_len++;
	if (map->full_map[map->i] == '\n')
		map->i++;
	map->line_len = 0;
	while (map->full_map[map->i])
	{
		if (map->full_map[map->i] == '\n')
		{
			if (map->line_len != map->first_line_len)
				return (ft_printf("Error: map not rectangular.\n"),
					free(map->full_map), 0);
			map->line_len = 0;
		}
		else
			map->line_len++;
		map->i++;
	}
	if (map->line_len != map->first_line_len)
		return (ft_printf("Error: map not rectangular.\n"),
			free(map->full_map), 0);
	return (1);
}

int	check_player(t_map *map)
{
	map->i = 0;
	map->player_count = 0;
	while (map->full_map[map->i++])
	{
		if (map->full_map[map->i] == 'P')
			map->player_count++;
	}
	if (map->player_count != 1)
		return (ft_printf("Error: number of players not correct.\n"),
			free(map->full_map), 0);
	return (1);
}

int	check_exit(t_map *map)
{
	map->i = 0;
	map->exit_count = 0;
	while (map->full_map[map->i++])
	{
		if (map->full_map[map->i] == 'E')
			map->exit_count++;
	}
	if (map->exit_count != 1)
		return (ft_printf("Error: number of exits not correct.\n"),
			free(map->full_map), 0);
	return (1);
}

int	check_path(t_map *map)
{
	t_i	indexes;

	map->player_i = find_player_i(map);
	init_checkers(map, map->player_i, 'E', &indexes);
	if (surrounded(map, indexes) || !check_floor_p(map, indexes))
		return (ft_printf("Error: wrong path.\n"), free(map->full_map),
			free(map->tmp_map), 0);
	free(map->tmp_map);
	map->coll_i = 0;
	map->coll_count = 0;
	while (map->full_map[map->coll_i++])
	{
		if (map->full_map[map->coll_i] == 'C')
		{
			init_checkers(map, map->coll_i, 'P', &indexes);
			if (surrounded(map, indexes) || !check_floor_c(map, indexes))
				return (free(map->tmp_map),
					ft_printf("Error: wrong path.\n"), free(map->full_map), 0);
			map->coll_count++;
			free(map->tmp_map);
		}
	}
	return (1);
}
