/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_exit_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:06:18 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/13 19:20:43 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	set_exit_position_and_transform_exit(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			if (map->map[i][j] == 'E')
			{
				map->x_exit = j;
				map->y_exit = i;
				map->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	remove_exit(t_map *map)
{
	set_exit_position_and_transform_exit(map);
}
