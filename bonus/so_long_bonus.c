/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:20:43 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/13 19:19:48 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	leaks()
// {
// 	system("leaks so_long");
// }

int	main(int argc, char *argv[])
{
	t_data		data;

	errors(argv[1], argc);
	map_reader(&data.map, argv[1]);
	map_checker(&data.map);
	remove_exit(&data.map);
	init_window(&data);
	mlx_loop(data.mlx.mlx_ptr);
}
