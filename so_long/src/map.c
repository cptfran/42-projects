/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:49:32 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 14:05:06 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
int	check_map(char *map_file, t_map *map)
{
	if (!read_map(map_file, map) || !check_walls(map) || !check_rect(map)
		|| !check_player(map) || !check_exit(map) || !check_path(map)
		|| !check_collectible(map) || !check_size(map)
		|| !check_wrong_char(map))
		return (0);
	return (1);
}

/*
 * Function: read_map
 * ----------------------------
 *   Reads the game map from a file. It opens the file, checks if the file descriptor is correct, and then reads the map
 *   into a string. If any of these steps fail, it prints an error message and returns 0.
 *
 *   map_file: The file containing the game map.
 *   map: The game map.
 *
 *   Returns: 1 if the map is read successfully, 0 otherwise.
 */
int	read_map(char *map_file, t_map *map)
{
	map->fd = open(map_file, O_RDONLY);
	if (map->fd == -1)
		return (ft_printf("Error: wrong file descriptor.\n"), 0);
	map->full_map = ft_strdup("");
	if (!map->full_map)
		return (ft_printf("Error: map reading error.\n"), 0);
	map->all_line_count = 0;
	map->line = get_next_line(map->fd);
	if (!map->line)
		return (ft_printf("Error: map reading error.\n"),
			free(map->full_map), 0);
	line_loop(map);
	if (map->all_line_count < 3)
		return (ft_printf("Error: map to small.\n"), close(map->fd),
			free(map->full_map), free(map->line), 0);
	map->map_len = ft_strlen(map->full_map);
	return (close(map->fd), 1);
}

/*
 * Function: check_walls
 * ----------------------------
 *   Checks if the game map is surrounded by walls. It checks the top wall, the middle walls, and the bottom wall.
 *   If any of these checks fail, it prints an error message, frees the game map, and returns 0.
 *
 *   map: The game map.
 *
 *   Returns: 1 if the map is surrounded by walls, 0 otherwise.
 */
int	check_walls(t_map *map)
{
	if (!check_top_wall(map) || !check_mid_walls(map) || !check_bot_wall(map))
		return (ft_printf("Error: map not surrounded by walls.\n"), 0);
	return (1);
}

/*
 * Function: check_top_wall
 * ----------------------------
 *   Checks if the top wall of the game map is made entirely of wall tiles ('1'). It iterates over the
 *   tiles in the top row of the map, and if it finds a tile that is not a wall tile, it frees the game
 *   map and returns 0.
 *
 *   map: The game map.
 *
 *   Returns: 1 if the top wall is correct, 0 otherwise.
 */
int	check_top_wall(t_map *map)
{
	map->i = 0;
	while (map->full_map[map->i] != '\n')
	{
		if (map->full_map[map->i++] != '1')
			return (free(map->full_map), 0);
	}
	if (map->full_map[map->i] == '\n')
		return (map->i++, 1);
	else
		return (free(map->full_map), 0);
}

/*
 * Function: check_mid_walls
 * ----------------------------
 *   Checks if the middle walls of the game map are correct. It iterates over the tiles in the middle rows of the map,
 *   and if it finds a row that does not start and end with a wall tile ('1'), it frees the game map and returns 0.
 *
 *   map: The game map.
 *
 *   Returns: 1 if the middle walls are correct, 0 otherwise.
 */
int	check_mid_walls(t_map *map)
{
	if (map->full_map[map->i] != '1')
		return (free(map->full_map), 0);
	map->mid_line_count = 0;
	while (map->mid_line_count < map->all_line_count - 2
		&& map->full_map[map->i++])
	{
		if (map->full_map[map->i] == '\n')
			map->mid_line_count++;
		if ((map->full_map[map->i + 1] == '\n'
				&& map->full_map[map->i] != '1')
			|| ((map->full_map[map->i - 1] == '\n'
					&& map->full_map[map->i] != '1')))
			return (free(map->full_map), 0);
	}
	if (map->full_map[map->i] == '\n')
		return (1);
	else
		return (free(map->full_map), 0);
}
