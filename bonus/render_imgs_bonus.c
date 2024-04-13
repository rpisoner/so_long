/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_imgs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:50:13 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/13 19:25:17 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_player(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->map.height - 1)
	{
		j = 1;
		while (j < data->map.width - 1)
		{
			if (data->map.map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->imgs.p_img, j * SIZE, i * SIZE);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	render_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.map[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->imgs.w_img, j * SIZE, i * SIZE);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	render_floor(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->map.height - 1)
	{
		j = 1;
		while (j < data->map.width - 1)
		{
			if (data->map.map[i][j] == '0')
			{
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->imgs.f_img, j * SIZE, i * SIZE);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	render_coin(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->map.height - 1)
	{
		j = 1;
		while (j < data->map.width - 1)
		{
			if (data->map.map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->imgs.c_img, j * SIZE, i * SIZE);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	render_exit(t_data *data)
{
	data->map.map[data->map.y_exit][data->map.x_exit] = 'E';
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->imgs.e_img, data->map.x_exit * SIZE, data->map.y_exit * SIZE);
	return (0);
}
