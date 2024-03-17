/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:42:39 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:58:52 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
 * Function: keypress
 * ----------------------------
 *   Handles key press events. If the ESC key is pressed, the game is closed. If the A, D, W, or S key is pressed,
 *   the player moves in the corresponding direction if possible. After each move, the player's image is updated
 *   and the game map is redrawn.
 *
 *   keysymbol: The key that was pressed.
 *   data: The game data.
 *
 *   Returns: 0 in all cases.
 */
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

/*
 * Function: keyrelease
 * ----------------------------
 *   Handles key release events. When the A, D, W, or S key is released, the player's image
 *   is updated to face in the corresponding direction and the game map is redrawn.
 *
 *   keysymbol: The key that was released.
 *   data: The game data.
 *
 *   Returns: 0 in all cases.
 */
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

/*
 * Function: keyrelease
 * ----------------------------
 *   Handles key release events. When the A, D, W, or S key is released, the player's image
 *   is updated to face in the corresponding direction and the game map is redrawn.
 *
 *   keysymbol: The key that was released.
 *   data: The game data.
 *
 *   Returns: 0 in all cases.
 */
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

/*
 * Function: move_right
 * ----------------------------
 *   Moves the player right in the game map. If the tile to the right of the player is a wall ('1')
 *   or an exit ('E') and there are still collectibles left, the player doesn't move.
 *   If the tile is a collectible ('C'), the player moves to the tile, the collectible
 *   is removed, and the collectible count is decreased. If the tile is empty ('0'),
 *   the player moves to the tile.
 *
 *   map: The game map.
 *   data: The game data.
 *
 *   Returns: 0 if the player doesn't move, 1 otherwise.
 */
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

/*
 * Function: move_up
 * ----------------------------
 *   Moves the player up in the game map. If the tile above the player is a wall ('1')
 *   or an exit ('E') and there are still collectibles left, the player doesn't move.
 *   If the tile is a collectible ('C'), the player moves to the tile, the collectible
 *   is removed, and the collectible count is decreased. If the tile is empty ('0'),
 *   the player moves to the tile.
 *
 *   map: The game map.
 *   data: The game data.
 *
 *   Returns: 0 if the player doesn't move, 1 otherwise.
 */
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
