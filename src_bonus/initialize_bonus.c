/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:23:03 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/18 14:43:31 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	init_imgs(t_mlx *mlx, t_images *img)
{
	int	size;

	size = SIZE;
	img->p_img = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER, &size, &size);
	img->m_img = mlx_xpm_file_to_image(mlx->mlx_ptr, ENEMY, &size, &size);
	img->f_img = mlx_xpm_file_to_image(mlx->mlx_ptr, FLOOR, &size, &size);
	img->w_img = mlx_xpm_file_to_image(mlx->mlx_ptr, LOG, &size, &size);
	img->c_img = mlx_xpm_file_to_image(mlx->mlx_ptr, COIN, &size, &size);
	img->e_img = mlx_xpm_file_to_image(mlx->mlx_ptr, EXIT, &size, &size);
}

int	render(t_data *data)
{
	static int	frames;

	if (!frames)
		frames = 0;
	if (frames == 50)
		set_winter(data);
	if (frames == 100)
		set_spring(data);
	else if (frames == 150)
		set_summer(data);
	else if (frames == 200)
	{
		set_autumn(data);
		frames = 0;
	}
	frames++;
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	render_player(data);
	render_enemy(data);
	render_floor(data);
	render_wall(data);
	render_coin(data);
	if (data->map.coin_num == 0)
		render_exit(data);
	return (0);
}
