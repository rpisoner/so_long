/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:23:03 by rpisoner          #+#    #+#             */
/*   Updated: 2024/03/28 19:22:43 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_mlx *mlx, t_images *img)
{
	int	size;

	size = 64;
	img->p_img = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER, &size, &size);
}

void	render(t_mlx *mlx, t_map *map, t_images *img)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			if (map->map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					img->p_img, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}
