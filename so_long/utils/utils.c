/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:39:35 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/01 16:08:10 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_hooks(t_data *data)
{
	data->move_count = 0;
	mlx_hook(data->win_ptr, 2, 0, &keypress, data);
	mlx_hook(data->win_ptr, 3, 0, &keyrelease, data);
	mlx_hook(data->win_ptr, 17, 0, &close_game, data);
}

int	close_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	line_loop(t_map *map)
{
	while (1)
	{
		if (map->line == NULL)
			return (1);
		map->map_cat = ft_strjoin(map->full_map, map->line);
		if (!map->map_cat)
			return (ft_printf("Error: map reading error.\n"),
				free(map->full_map), free(map->line), 0);
		free(map->full_map);
		map->full_map = map->map_cat;
		if (!map->full_map)
			return (ft_printf("Error: map reading error.\n"),
				free(map->line), 0);
		free(map->line);
		map->all_line_count++;
		map->line = get_next_line(map->fd);
	}
	return (0);
}

int	find_player_i(t_map *map)
{
	map->i = 0;
	while (map->full_map[map->i++])
	{
		if (map->full_map[map->i] == 'P')
			return (map->i);
	}
	return (0);
}

void	init_checkers(t_map *map, int index, char c, t_i *i)
{
	i->t = index - map->line_len - 1;
	i->b = index + map->line_len + 1;
	i->l = index - 1;
	i->r = index + 1;
	map->c = c;
	map->tmp_map = malloc(ft_strlen(map->full_map + 1));
	if (!map->tmp_map)
		return ;
	ft_memcpy(map->tmp_map, map->full_map, ft_strlen(map->full_map) + 1);
}
