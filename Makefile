#########################################################################################
#       -MAKEFILE-                                                                      #
#       PROJECT: so_long                                                           #
#########################################################################################
NAME = so_long
BONUS_NAME = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/opt/X11/include -Imlx
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

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
		window_management \
		get_next_line_utils 
SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

#########################################################################################
# Bonus sources and objects
#########################################################################################
BFILES =	error_bonus \
			moves_bonus \
			errors_bonus \
			map_reader_bonus \
			valid_path_bonus \
			map_checker_bonus \
			libft_utils_bonus \
			initialize_bonus \
			render_imgs_bonus \
			get_next_line_bonus \
			window_management_bonus \
			get_next_line_utils_bonus
BSRCS = $(addprefix $(SRC_DIR)/bonus/, $(addsuffix .c, $(BFILES)))
BOBJS = $(addsuffix .o, $(BFILES))

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
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# bonus: $(BONUS_NAME)

# ./bonus/%.o: ./bonus/%.c
# 	@echo "$(Y)Compiling bonus: $<$(DEF_COLOR)"
# 	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

# $(BONUS_NAME): $(OBJS) $(BOBJS)
# 	@$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)
# 	@$(CC) $(BOBJS) $(MLX_FLAGS) -o $(BONUS_NAME)

clean:
	@$(RM) $(OBJS) $(BOBJS)
	@echo "$(R)All .o files removed$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)Executable file removed: $(NAME)$(DEF_COLOR)"

re: fclean all

.PHONY: all bonus clean fclean re
