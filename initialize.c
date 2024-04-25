/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:23:03 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/25 11:24:48 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	not_images(void)
{
	write(2, "Alguna de las imágenes no se cargó correctamente\n", 52);
	exit(1);
}

void	init_imgs(t_mlx *mlx, t_images *img)
{
	int	size;

	size = SIZE;
	img->p_img = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER, &size, &size);
	img->f_img = mlx_xpm_file_to_image(mlx->mlx_ptr, FLOOR, &size, &size);
	img->w_img = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL, &size, &size);
	img->c_img = mlx_xpm_file_to_image(mlx->mlx_ptr, COIN, &size, &size);
	img->e_img = mlx_xpm_file_to_image(mlx->mlx_ptr, EXIT, &size, &size);
	if (img->p_img == NULL || img->f_img == NULL || img->w_img == NULL
		|| img->c_img == NULL || img->e_img == NULL)
		not_images();
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
