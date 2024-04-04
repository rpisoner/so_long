/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:20:43 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/04 19:31:29 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks()
{
	system("leaks so_long");
}

void	print_map(char **array)
{
	if (!array)
		print_error();
	while (*array != NULL)
	{
		printf("%s", *array);
		array++;
	}
}

int	main(int argc, char *argv[])
{
	t_data		data;

	errors(argv[1], argc);
	map_reader(&data.map, argv[1]);
	map_checker(&data.map);
	init_window(&data);
	//print_map(map_struct.map);
	//atexit(leaks);
	mlx_loop(data.mlx.mlx_ptr);
}
