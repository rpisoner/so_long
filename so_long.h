/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:26:47 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/04 20:04:10 by rpisoner         ###   ########.fr       */
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
# define PLAYER "./textures/player.xpm"
# define FLOOR "./textures/floor.xpm"
# define WALL "./textures/wall.xpm"
# define COIN "./textures/coin.xpm"
# define EXIT "./textures/exit.xpm"
# define SIZE 64

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		coin_num;
	int		x_player;
	int		y_player;
	int		p_move_num;
}	t_map;

typedef struct s_images
{
	void	*p_img;
	void	*w_img;
	void	*f_img;
	void	*c_img;
	void	*e_img;
}	t_images;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_data
{
	t_mlx		mlx;
	t_images	imgs;	
	t_map		map;
}	t_data;

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
void	init_window(t_data *data);
void	print_map(char **array);
//INITIALIZE
void	init_imgs(t_mlx *mlx, t_images *img);
int		render(t_data *data);
//RENDER
void	render_player(t_data *data);
void	render_floor(t_data *data);
void	render_wall(t_data *data);
void	render_coin(t_data *data);
void	render_exit(t_data *data);
//MOVEMENTS
int		movements(int keycode, t_map *map);
void	move_up(t_map *map);
void	move_left(t_map *map);
void	move_down(t_map *map);
void	move_right(t_map *map);
//WINDOW MANAGEMENT
int		close_window(void);
#endif