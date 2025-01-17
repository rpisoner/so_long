/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:39:56 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/13 18:42:00 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	move_up(t_map *map)
{
	if (map->map[map->y_player - 1][map->x_player] == 'M')
		exit(0);
	else if (map->map[map->y_player - 1][map->x_player] == '1' ||
		(map->map[map->y_player - 1][map->x_player] == 'E' &&
		map->coin_num > 0))
		return ;
	else if (map->map[map->y_player - 1][map->x_player] == 'C')
		map->coin_num--;
	else if (map->map[map->y_player - 1][map->x_player] == 'E')
		exit(0);
	map->map[map->y_player - 1][map->x_player] = 'P';
	map->map[map->y_player][map->x_player] = '0';
	map->p_move_num++;
	map->y_player--;
	ft_putnbr(map->p_move_num);
	write(1, "\n", 1);
}

void	move_left(t_map *map)
{
	if (map->map[map->y_player][map->x_player - 1] == 'M')
		exit(0);
	else if (map->map[map->y_player][map->x_player - 1] == '1' ||
		(map->map[map->y_player][map->x_player - 1] == 'E' &&
		map->coin_num > 0))
		return ;
	else if (map->map[map->y_player][map->x_player - 1] == 'C')
		map->coin_num--;
	else if (map->map[map->y_player][map->x_player - 1] == 'E')
		exit(0);
	map->map[map->y_player][map->x_player - 1] = 'P';
	map->map[map->y_player][map->x_player] = '0';
	map->p_move_num++;
	map->x_player--;
	ft_putnbr(map->p_move_num);
	write(1, "\n", 1);
}

void	move_down(t_map *map)
{
	if (map->map[map->y_player + 1][map->x_player] == 'M')
		exit(0);
	else if (map->map[map->y_player + 1][map->x_player] == '1' ||
		(map->map[map->y_player + 1][map->x_player] == 'E' &&
		map->coin_num > 0))
		return ;
	else if (map->map[map->y_player + 1][map->x_player] == 'C')
		map->coin_num--;
	else if (map->map[map->y_player + 1][map->x_player] == 'E')
		exit(0);
	map->map[map->y_player + 1][map->x_player] = 'P';
	map->map[map->y_player][map->x_player] = '0';
	map->p_move_num++;
	map->y_player++;
	ft_putnbr(map->p_move_num);
	write(1, "\n", 1);
}

void	move_right(t_map *map)
{
	if (map->map[map->y_player][map->x_player + 1] == 'M')
		exit(0);
	else if (map->map[map->y_player][map->x_player + 1] == '1' ||
		(map->map[map->y_player][map->x_player + 1] == 'E' &&
		map->coin_num > 0))
		return ;
	else if (map->map[map->y_player][map->x_player + 1] == 'C')
		map->coin_num--;
	else if (map->map[map->y_player][map->x_player + 1] == 'E')
		exit(0);
	map->map[map->y_player][map->x_player + 1] = 'P';
	map->map[map->y_player][map->x_player] = '0';
	map->p_move_num++;
	map->x_player++;
	ft_putnbr(map->p_move_num);
	write(1, "\n", 1);
}
