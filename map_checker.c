/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:41:24 by rpisoner          #+#    #+#             */
/*   Updated: 2024/03/28 20:19:09 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	surrounded_by_walls(t_map map)
{
	int	i;

	i = 0;
	while (map.map[0][i] && map.map[map.height - 1][i])
	{
		if (map.map[0][i] != '1' || map.map[map.height - 1][i] != '1')
			print_error();
		i++;
	}
	i = 1;
	while (i < map.height - 1)
	{
		if (map.map[i][0] != '1' || map.map[i][map.width - 1] != '1')
			print_error();
		i++;
	}
}

static void	check_minimum_element(char element, int *e, int *p, int *c)
{
	if (element == 'E')
		*e += 1;
	else if (element == 'P')
		*p += 1;
	else if (element == 'C')
		*c = 1;
}

static void	minimum_elements(t_map *map)
{
	int		e;
	int		p;
	int		c;
	int		i;
	int		j;

	e = 0;
	p = 0;
	c = 0;
	i = 1;
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			check_minimum_element(map->map[i][j], &e, &p, &c);
			j++;
		}
		i++;
	}
	map->coin_num = c;
	if (e != 1 || p != 1 || c == 0)
		print_error();
}

static void	correct_elements(t_map *map)
{
	int		i;
	int		j;

	minimum_elements(map);
	i = 1;
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
			&& map->map[i][j] != 'E' && map->map[i][j] != 'P'
			&& map->map[i][j] != 'C')
				print_error();
			j++;
		}
		i++;
	}
}

void	map_checker(t_map *map)
{
	surrounded_by_walls(*map);
	correct_elements(map);
	valid_path(map);
}
