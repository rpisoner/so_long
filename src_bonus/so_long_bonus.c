/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:20:43 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/18 18:43:59 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

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
