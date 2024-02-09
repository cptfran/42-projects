/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:55:49 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/01 16:20:58 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	check_collectible(t_map *map)
{
	if (map->coll_count == 0)
		return (ft_printf("Error: no collectibles.\n"), free(map->full_map), 0);
	return (1);
}

int	check_size(t_map *map)
{
	if (map->line_len <= 40 && map->all_line_count <= 20)
		return (1);
	return (ft_printf("Error: map too big.\n"), free(map->full_map), 0);
}

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
