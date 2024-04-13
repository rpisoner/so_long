/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:23:03 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/13 19:24:26 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_imgs(t_mlx *mlx, t_images *img)
{
	int	size;

	size = SIZE;
	img->p_img = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER, &size, &size);
	img->m_img = mlx_xpm_file_to_image(mlx->mlx_ptr, ENEMY, &size, &size);
	img->f_img = mlx_xpm_file_to_image(mlx->mlx_ptr, FLOOR, &size, &size);
	img->w_img = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL, &size, &size);
	img->c_img = mlx_xpm_file_to_image(mlx->mlx_ptr, COIN, &size, &size);
	img->e_img = mlx_xpm_file_to_image(mlx->mlx_ptr, EXIT, &size, &size);
}

int	render(t_data *data)
{
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	render_player(data);
	render_floor(data);
	render_wall(data);
	render_coin(data);
	if (data->map.coin_num == 0)
		render_exit(data);
	return (0);
}
