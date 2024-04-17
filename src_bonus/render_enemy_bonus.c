/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:35:58 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/13 18:36:48 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	render_enemy(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->map.height - 1)
	{
		j = 1;
		while (j < data->map.width - 1)
		{
			if (data->map.map[i][j] == 'M')
			{
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->imgs.m_img, j * SIZE, i * SIZE);
			}
			j++;
		}
		i++;
	}
	return (0);
}
