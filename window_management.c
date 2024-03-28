/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:22:57 by rpisoner          #+#    #+#             */
/*   Updated: 2024/03/28 20:25:07 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit(0);
}

int	movements(int keycode, t_map *map)
{
	if (keycode == KEY_W)
		move_up(map);
	else if (keycode == KEY_A)
		move_left(map);
	else if (keycode == KEY_S)
		move_down(map);
	else if (keycode == KEY_D)
		move_right(map);
	else if (keycode == KEY_ESCAPE)
		close_window();
	printf("\nCN: %d\n", map->coin_num);
	print_map(map->map);
	printf("\n");
	return (0);
}

void	init_window(t_map *map, t_mlx *mlx, t_images *imgs)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, map->width * 64,
			map->height * 64, "So_Long by: rpisoner");
	init_imgs(mlx, imgs);
	render(mlx, map, imgs);
	mlx_hook(mlx->win_ptr, 17, 0, close_window, 0);
	mlx_hook(mlx->win_ptr, 2, 0, movements, map);
}

