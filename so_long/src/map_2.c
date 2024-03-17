/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:53:54 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 14:01:13 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
 * Function: check_bot_wall
 * ----------------------------
 *   Checks if the bottom wall of the game map is made entirely of wall tiles ('1'). It iterates over the
 *   tiles in the bottom row of the map, and if it finds a tile that is not a wall tile, it frees the game
 *   map and returns 0.
 *
 *   map: The game map.
 *
 *   Returns: 1 if the bottom wall is correct, 0 otherwise.
 */
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

/*
 * Function: check_rect
 * ----------------------------
 *   Checks if the game map is a rectangle. It calculates the length of the first row and then compares it
 *   with the length of each subsequent row. If it finds a row that is not the same length as the first row,
 *   it returns 0.
 *
 *   map: The game map.
 *
 *   Returns: 1 if the map is a rectangle, 0 otherwise.
 */
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

/*
 * Function: check_player
 * ----------------------------
 *   Checks the number of players in the game map. It iterates over the tiles in the map, and if it finds a player tile ('P'),
 *   it increases the player count. If the player count is not exactly 1, it prints an error message, frees the game map,
 *   and returns 0.
 *
 *   map: The game map.
 *
 *   Returns: 1 if the number of players is correct, 0 otherwise.
 */
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

/*
 * Function: check_exit
 * ----------------------------
 *   Checks the number of exits in the game map. If there is not exactly one exit, it prints an error message,
 *   frees the game map, and returns 0.
 *
 *   map: The game map.
 *
 *   Returns: 1 if the number of exits is correct, 0 otherwise.
 */
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

/*
 * Function: check_path
 * ----------------------------
 *   Checks if there is a path from the player to the exit in the game map. If there is no path, it prints an error message,
 *   frees the game map and the temporary map, and returns 0.
 *
 *   map: The game map.
 *
 *   Returns: 1 if there is a path from the player to the exit, 0 otherwise.
 */
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
