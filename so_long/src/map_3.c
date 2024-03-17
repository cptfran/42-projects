/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:55:49 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 14:03:11 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
 * Function: check_floor_p
 * ----------------------------
 *   Checks if there is a path from the player to the floor in the game map. It uses a recursive depth-first search
 *   algorithm to explore the map. If it finds a floor tile ('C'), it returns 1. If it finds a wall tile ('1'), it
 *   doesn't continue in that direction.
 *
 *   map: The game map.
 *   i: The current tile indices.
 *
 *   Returns: 1 if there is a path from the player to the floor, 0 otherwise.
 */
int	check_floor_p(t_map *map, t_i i)
{
	if (map->tmp_map[i.t] == map->c || map->tmp_map[i.b] == map->c
		|| map->tmp_map[i.l] == map->c || map->tmp_map[i.r] == map->c)
		return (1);
	if (not_wall(map, i.t))
		if (check_floor_p(map, init_i(i.t - map->line_len - 1, 0, i.t - 1,
					i.t + 1)))
			return (1);
	if (not_wall(map, i.b))
		if (check_floor_p(map, init_i(0, i.b + map->line_len + 1,
					i.b - 1, i.b + 1)))
			return (1);
	if (not_wall(map, i.l))
		if (check_floor_p(map, init_i(i.l - map->line_len - 1,
					i.l + map->line_len + 1, i.l - 1, 0)))
			return (1);
	if (not_wall(map, i.r))
		if (check_floor_p(map, init_i(i.r - map->line_len - 1,
					i.r + map->line_len + 1, 0, i.r + 1)))
			return (1);
	return (0);
}

/*
 * Function: check_floor_c
 * ----------------------------
 *   Checks if there is a path from the collectible to the floor in the game map. It uses a recursive depth-first search
 *   algorithm to explore the map. If it finds a floor tile ('C'), it returns 1. If it finds a wall tile ('1'), it
 *   doesn't continue in that direction.
 *
 *   map: The game map.
 *   i: The current tile indices.
 *
 *   Returns: 1 if there is a path from the collectible to the floor, 0 otherwise.
 */
int	check_floor_c(t_map *map, t_i i)
{
	if (map->tmp_map[i.t] == map->c || map->tmp_map[i.b] == map->c
		|| map->tmp_map[i.l] == map->c || map->tmp_map[i.r] == map->c)
		return (1);
	if (not_wall_or_exit(map, i.t))
		if (check_floor_c(map, init_i(i.t - map->line_len - 1, 0, i.t - 1,
					i.t + 1)))
			return (1);
	if (not_wall_or_exit(map, i.b))
		if (check_floor_c(map, init_i(0, i.b + map->line_len + 1,
					i.b - 1, i.b + 1)))
			return (1);
	if (not_wall_or_exit(map, i.l))
		if (check_floor_c(map, init_i(i.l - map->line_len - 1,
					i.l + map->line_len + 1, i.l - 1, 0)))
			return (1);
	if (not_wall_or_exit(map, i.r))
		if (check_floor_c(map, init_i(i.r - map->line_len - 1,
					i.r + map->line_len + 1, 0, i.r + 1)))
			return (1);
	return (0);
}

/*
 * Function: check_collectible
 * ----------------------------
 *   Checks the number of collectibles in the game map. If there are no collectibles, it prints an error message,
 *   frees the game map, and returns 0.
 *
 *   map: The game map.
 *
 *   Returns: 1 if the number of collectibles is correct, 0 otherwise.
 */
int	check_collectible(t_map *map)
{
	if (map->coll_count == 0)
		return (ft_printf("Error: no collectibles.\n"), free(map->full_map), 0);
	return (1);
}

/*
 * Function: check_size
 * ----------------------------
 *   Checks the size of the game map. If the map is larger than 40 tiles wide or 20 tiles high, it prints an error message,
 *   frees the game map, and returns 0.
 *
 *   map: The game map.
 *
 *   Returns: 1 if the size of the map is correct, 0 otherwise.
 */
int	check_size(t_map *map)
{
	if (map->line_len <= 40 && map->all_line_count <= 20)
		return (1);
	return (ft_printf("Error: map too big.\n"), free(map->full_map), 0);
}

/*
 * Function: check_wrong_char
 * ----------------------------
 *   Checks the characters in the game map. It iterates over the tiles in the map, and if it finds a tile that is not a wall ('1'),
 *   a player ('P'), a collectible ('C'), an exit ('E'), or a floor ('0'), it returns 0.
 *
 *   map: The game map.
 *
 *   Returns: 1 if all characters in the map are correct, 0 otherwise.
 */
int	check_wrong_char(t_map *map)
{
	map->i = 0;
	while (map->full_map[map->i++])
	{
		if (map->full_map[map->i] == 0)
			break ;
		if (map->full_map[map->i] != '1' && map->full_map[map->i] != '0'
			&& map->full_map[map->i] != '\n' && map->full_map[map->i] != 'P'
			&& map->full_map[map->i] != 'P' && map->full_map[map->i] != 'E'
			&& map->full_map[map->i] != 'C')
			return (ft_printf("Error: wrong map element.\n"),
				free(map->full_map), 0);
	}
	return (1);
}
