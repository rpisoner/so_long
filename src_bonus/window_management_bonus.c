/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:22:57 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/13 18:10:04 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	close_window(void)
{
	exit(0);
}

int	movements(int keycode, t_map *map)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(map);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(map);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(map);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(map);
	else if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

void	init_window(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, data->map.width
			* SIZE, data->map.height * SIZE, "So_Long by: rpisoner");
	data->map.p_move_num = 0;
	init_imgs(&data->mlx, &data->imgs);
	mlx_hook(data->mlx.win_ptr, 17, KEY_PRESS_MASK, close_window, 0);
	mlx_hook(data->mlx.win_ptr, 2, KEY_PRESS_MASK, movements, &data->map);
	mlx_loop_hook(data->mlx.mlx_ptr, render, data);
}
