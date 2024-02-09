/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:49:32 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/01 16:48:11 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map(char *map_file, t_map *map)
{
	if (!read_map(map_file, map) || !check_walls(map) || !check_rect(map)
		|| !check_player(map) || !check_exit(map) || !check_path(map)
		|| !check_collectible(map) || !check_size(map)
		|| !check_wrong_char(map))
		return (0);
	return (1);
}

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

int	check_walls(t_map *map)
{
	if (!check_top_wall(map) || !check_mid_walls(map) || !check_bot_wall(map))
		return (ft_printf("Error: map not surrounded by walls.\n"), 0);
	return (1);
}

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
