/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:36:27 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/17 20:10:41 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

static void	free_aux(char **aux, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(aux[i]);
		i++;
	}
	free(aux);
}

static void	flood_fill(int row, int column, char **map)
{
	map[column][row] = '1';
	if (map[column + 1][row] != '1' &&
		map[column + 1][row] != 'M')
		flood_fill(row, column + 1, map);
	if (map[column - 1][row] != '1' &&
		map[column - 1][row] != 'M')
		flood_fill(row, column - 1, map);
	if (map[column][row - 1] != '1' &&
		map[column][row - 1] != 'M')
		flood_fill(row - 1, column, map);
	if (map[column][row + 1] != '1' &&
		map[column][row + 1] != 'M')
		flood_fill(row + 1, column, map);
}

static void	set_player_position(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map->map[i])
	{
		j = 1;
		while (map->map[i][j] && map->map[i][j] != 'P')
			j++;
		if (map->map[i][j] == 'P')
		{
			map->x_player = j;
			map->y_player = i;
			return ;
		}
		i++;
	}
}

static void	check_valid_map(char **aux, int width, int height)
{
	int	i;
	int	j;

	i = 1;
	while (i < height - 1)
	{
		j = 1;
		while (j < width - 1)
		{
			if (aux[i][j] != '1' && aux[i][j] != '0' && aux[i][j] != 'M')
				not_playable_map();
			j++;
		}
		i++;
	}
}

void	valid_path(t_map *map)
{
	char	**aux;
	int		i;

	i = 0;
	aux = (char **)malloc((map->height + 1) * sizeof(char *));
	while (map->map[i] && i < map->height)
	{
		aux[i] = ft_strdup(map->map[i]);
		i++;
	}
	aux[i] = NULL;
	set_player_position(map);
	flood_fill(map->x_player, map->y_player, aux);
	check_valid_map(aux, map->width, map->height);
	free_aux(aux, map->height);
}
