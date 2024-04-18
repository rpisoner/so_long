/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:22:57 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/18 17:52:23 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	close_window(void)
{
	exit(0);
}

int	movements(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(&data->map);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		set_player_img_left(data);
		move_left(&data->map);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(&data->map);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		set_player_img_right(data);
		move_right(&data->map);
	}
	else if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

void	init_window(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, data->map.width
			* SIZE, (data->map.height + 1) * SIZE, "So_Long by: rpisoner");
	data->map.p_move_num = 0;
	init_imgs(&data->mlx, &data->imgs);
	mlx_hook(data->mlx.win_ptr, 17, KEY_PRESS_MASK, close_window, 0);
	mlx_hook(data->mlx.win_ptr, 2, KEY_PRESS_MASK, movements, data);
	mlx_loop_hook(data->mlx.mlx_ptr, render, data);
}
