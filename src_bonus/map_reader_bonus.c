/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:38:01 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/17 19:50:07 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

static void	set_height(t_map *map, char *file)
{
	size_t	i;
	char	*line;
	int		file_fd;

	i = 0;
	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
		not_valid_file();
	line = get_next_line(file_fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(file_fd);
	}
	free(line);
	if (i < 3)
		not_playable_map();
	map->height = i;
	close (file_fd);
}

static void	set_width_and_check_lines_length(t_map	*map)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = ft_strlen(map->map[map->height - 1]);
	while ((int)i < map->height - 1)
	{
		if (j != ft_strlen(map->map[i]) - 1)
			not_rectangular_map();
		i++;
	}
	map->width = j;
}

void	map_reader(t_map *map, char *file)
{
	size_t	i;
	int		file_fd;

	i = 0;
	set_height(map, file);
	file_fd = open(file, O_RDONLY);
	map->map = (char **)malloc((map->height + 1) * sizeof(char *));
	if (!map->map)
		malloc_error();
	map->map[i] = get_next_line(file_fd);
	while (map->map[i])
	{
		i++;
		map->map[i] = get_next_line(file_fd);
	}
	set_width_and_check_lines_length(map);
	close(file_fd);
}
