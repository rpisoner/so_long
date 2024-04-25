/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:23:03 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/25 11:26:55 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

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
	img->m_img = mlx_xpm_file_to_image(mlx->mlx_ptr, ENEMY, &size, &size);
	img->f_img = mlx_xpm_file_to_image(mlx->mlx_ptr, FLOOR, &size, &size);
	img->w_img = mlx_xpm_file_to_image(mlx->mlx_ptr, LOG, &size, &size);
	img->c_img = mlx_xpm_file_to_image(mlx->mlx_ptr, COIN, &size, &size);
	img->e_img = mlx_xpm_file_to_image(mlx->mlx_ptr, EXIT, &size, &size);
	img->b_img = mlx_xpm_file_to_image(mlx->mlx_ptr, BANNER, &size, &size);
	if (img->p_img == NULL || img->f_img == NULL || img->w_img == NULL
		|| img->c_img == NULL || img->e_img == NULL || img->b_img == NULL)
		not_images();
}

static void	animation(t_data *data, int *frames)
{
	if (*frames == 50)
		set_winter(data);
	if (*frames == 100)
		set_spring(data);
	else if (*frames == 150)
		set_summer(data);
	else if (*frames == 200)
	{
		set_autumn(data);
		*frames = 0;
	}
	(*frames)++;
}

static void	render_text(t_data *data)
{
	char	*move_num;
	int		j;

	j = 0;
	while (j < data->map.width)
	{
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
			data->imgs.b_img, j * SIZE, 0);
		j++;
	}
	move_num = ft_itoa(data->map.p_move_num);
	mlx_string_put(data->mlx.mlx_ptr,
		data->mlx.win_ptr, 105, 24,
		0xffffff, move_num);
	mlx_string_put(data->mlx.mlx_ptr,
		data->mlx.win_ptr, 10, 24,
		0xffffff, "Movements");
	free(move_num);
	move_num = NULL;
}

int	render(t_data *data)
{
	static int	frames;

	if (!frames)
		frames = 0;
	animation(data, &frames);
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	render_player(data);
	render_enemy(data);
	render_floor(data);
	render_wall(data);
	render_coin(data);
	if (data->map.coin_num == 0)
		render_exit(data);
	render_text(data);
	return (0);
}
