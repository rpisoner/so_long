/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:20:43 by rpisoner          #+#    #+#             */
/*   Updated: 2024/03/28 20:20:40 by rpisoner         ###   ########.fr       */
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
	t_map		map_struct;
	t_images	imgs;
	t_mlx		mlx;

	errors(argv[1], argc);
	map_reader(&map_struct, argv[1]);
	map_checker(&map_struct);
	init_window(&map_struct, &mlx, &imgs);
	// mlx_loop_hook(mlx.mlx_ptr, (void *)render, &map_struct);
	//print_map(map_struct.map);
	//atexit(leaks);
	mlx_loop(mlx.mlx_ptr);
}
