/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:20:43 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/17 20:12:23 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*void	leaks()
{
 	system("leaks so_long");
}*/

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
