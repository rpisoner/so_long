/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:26:47 by rpisoner          #+#    #+#             */
/*   Updated: 2024/03/28 20:23:02 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

# include <stdio.h>
# include "get_next_line.h"
# define PLAYER "./textures/xlr8.xpm"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		coin_num;
	int		x_player;
	int		y_player;
}	t_map;

typedef struct s_images
{
	void	*p_img;
	void	*one_img;
	void	*cero_img;
	void	*c_img;
	void	*e_img;
}	t_images;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

enum
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_ESCAPE = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126
};

//ERRORS
void	print_error(void);
void	errors(char *file, int argc);
//UTILS
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
//MAP_READER
void	map_reader(t_map *map, char *file);
//MAP_CHECKER
void	map_checker(t_map *map);
void	valid_path(t_map *map);
//DISPLAY_MAP
void	init_window(t_map *map, t_mlx *mlx, t_images *imgs);
void	print_map(char **array);
//INITIALIZE
void	init_imgs(t_mlx *mlx, t_images *img);
void	render(t_mlx *mlx, t_map *map, t_images *img);
int		movements(int keycode, t_map *map);
//MOVEMENTS
void	move_up(t_map *map);
void	move_left(t_map *map);
void	move_down(t_map *map);
void	move_right(t_map *map);
#endif