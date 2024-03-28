/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:39:56 by rpisoner          #+#    #+#             */
/*   Updated: 2024/03/28 20:27:30 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	if (map->map[map->y_player - 1][map->x_player] == '1')
		return ;
	else if (map->map[map->y_player - 1][map->x_player] == 'C')
		map->coin_num--;
	map->map[map->y_player - 1][map->x_player] = 'P';
	map->map[map->y_player][map->x_player] = '0';
	//FALTA CASO QUE SEA E
	map->y_player--;
}

void	move_left(t_map *map)
{
	if (map->map[map->y_player][map->x_player - 1] == '1')
		return ;
	else if (map->map[map->y_player][map->x_player - 1] == 'C')
		map->coin_num--;
	map->map[map->y_player][map->x_player - 1] = 'P';
	map->map[map->y_player][map->x_player] = '0';
	map->x_player--;
}

void	move_down(t_map *map)
{
	if (map->map[map->y_player + 1][map->x_player] == '1')
		return ;
	else if (map->map[map->y_player + 1][map->x_player] == 'C')
		map->coin_num--;
	map->map[map->y_player + 1][map->x_player] = 'P';
	map->map[map->y_player][map->x_player] = '0';
	map->y_player++;
}

void	move_right(t_map *map)
{
	if (map->map[map->y_player][map->x_player + 1] == '1')
		return ;
	else if (map->map[map->y_player][map->x_player + 1] == 'C')
		map->coin_num--;
	map->map[map->y_player][map->x_player + 1] = 'P';
	map->map[map->y_player][map->x_player] = '0';
	map->x_player++;
}
