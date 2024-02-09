/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:03:53 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/27 15:58:14 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
