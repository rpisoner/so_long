#########################################################################################
#       -MAKEFILE-                                                                      #
#       PROJECT: so_long                                                                #
#########################################################################################
NAME = so_long
BONUS_NAME = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INCLUDES = -I/opt/X11/include -Imlx
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
KEY_FLAG = -D KEY_A=0 -D KEY_S=1 -D KEY_D=2 -D KEY_W=13 -D KEY_ESCAPE=53 -D KEY_LEFT=123 -D KEY_RIGHT=124 -D KEY_DOWN=125 -D KEY_UP=126 -D KEY_PRESS_MASK=0

# Linux detection
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	INCLUDES = -I/usr/include -Imlx
	MLX_FLAGS = -Lmlx -lmlx -lXext -lX11
	KEY_FLAG = -D KEY_A=97 -D KEY_S=115 -D KEY_D=100 -D KEY_W=119 -D KEY_ESCAPE=65307 -D KEY_LEFT=65361 -D KEY_RIGHT=65363 -D KEY_DOWN=65364 -D KEY_UP=65362 -D KEY_PRESS_MASK=1L<<0
endif

#########################################################################################
# Directories
#########################################################################################
HDR_DIR = .
SRC_DIR = .

#########################################################################################
# Sources & objects
#########################################################################################
FILES = so_long \
		moves \
		errors \
		map_reader \
		valid_path \
		remove_exit \
		map_checker \
		libft_utils \
		initialize \
		render_imgs \
		get_next_line \
		explicit_errors \
		explicit_errors2 \
		explicit_errors3 \
		window_management \
		get_next_line_utils
SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix src/, $(addsuffix .o, $(FILES)))

#########################################################################################
# Bonus sources and objects
#########################################################################################
BFILES =	so_long_bonus \
			moves_bonus \
			errors_bonus \
			ft_itoa_bonus \
			map_reader_bonus \
			valid_path_bonus \
			map_checker_bonus \
			remove_exit_bonus \
			libft_utils_bonus \
			animations_bonus \
			initialize_bonus \
			render_imgs_bonus \
			render_enemy_bonus \
			get_next_line_bonus \
			explicit_errors_bonus \
			explicit_errors2_bonus \
			explicit_errors3_bonus \
			window_management_bonus \
			get_next_line_utils_bonus
BSRCS = $(addprefix src_bonus/, $(addsuffix .c, $(BFILES)))
BOBJS = $(addprefix src_bonus/, $(addsuffix .o, $(BFILES)))

#########################################################################################
# Colors
#########################################################################################
DEF_COLOR = \033[0;39m
CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

#########################################################################################
# Rules
#########################################################################################
all: $(NAME)

%.o: %.c
	@echo "$(Y)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(KEY_FLAG) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BOBJS)
	@$(CC) $(BOBJS) $(MLX_FLAGS) -o $(BONUS_NAME)

clean:
	@$(RM) $(OBJS) $(BOBJS)
	@echo "$(R)All .o files removed$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(R)Executable files removed$(DEF_COLOR)"

re: fclean all

.PHONY: all bonus clean fclean re
