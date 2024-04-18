/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:26:02 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/18 14:32:24 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	set_winter(t_data *data)
{
	int	size;

	size = SIZE;
	data->imgs.w_img = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			WINTER, &size, &size);
}

void	set_autumn(t_data *data)
{
	int	size;

	size = SIZE;
	data->imgs.w_img = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			AUTUMN, &size, &size);
}

void	set_spring(t_data *data)
{
	int	size;

	size = SIZE;
	data->imgs.w_img = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			WALL, &size, &size);
}

void	set_summer(t_data *data)
{
	int	size;

	size = SIZE;
	data->imgs.w_img = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			SUMMER, &size, &size);
}
