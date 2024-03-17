/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:03:53 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:59:20 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
 * Function: main
 * ----------------------------
 *   The main function of the game. It checks the command line arguments, loads the game map,
 *   initializes the game window, sets up the event handlers, loads the game images, draws the
 *   initial game map, and starts the game loop.
 *
 *   argc: The number of command line arguments.
 *   argv: The array of command line arguments.
 *
 *   Returns: 0 if the game runs successfully, 1 otherwise.
 */
int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	data.map = &map;
	if (argc != 2)
		return (ft_printf("Error: wrong arguments.\n"), 0);
	if (argc == 2 && !check_map(argv[1], &map))
		return (1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, map.line_len * 64,
			map.all_line_count * 64, "so_long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	init_hooks(&data);
	load_images(&data);
	draw_map(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
