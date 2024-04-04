/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:23:03 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/04 19:52:03 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_mlx *mlx, t_images *img)
{
	int	size;

	size = SIZE;
	img->p_img = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER, &size, &size);
	img->f_img = mlx_xpm_file_to_image(mlx->mlx_ptr, FLOOR, &size, &size);
	img->w_img = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL, &size, &size);
	img->c_img = mlx_xpm_file_to_image(mlx->mlx_ptr, COIN, &size, &size);
	img->e_img = mlx_xpm_file_to_image(mlx->mlx_ptr, EXIT, &size, &size);
}

int	render(t_data *data)
{
	//static int	frame;

	//frame += 1;
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	render_wall(data);
	render_player(data);
	return (0);
}
