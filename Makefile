NAME = cub3D
OBJ_DIR		=	obj/
SRCS_DIR	=	src/
SRCS		=	main.c \
				mini_map.c \
				init_all_strcts.c \
				parsing.c \
				prs_utils.c	\
				strct_map.c	\
				strct_map_insd.c \
				get_txtr.c \
				move.c \
				move_bis.c  \
				rcasting.c \
				ray_txtr.c \
				utils.c \

				
OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
MLX		= libmlx.a
LIBFT	= libft.a
LFLAGS	= -I include/
CFLAGS = -Wall -Wextra -Werror -g
DEBUGGING = -ggdb
CC = gcc
RM = rm -rf
AR = ar rc

all: objects libft minilibx $(NAME)

minilibx:
	make -C mlx/ && make -C libft/

objects:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/pars
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/init
	@mkdir -p $(OBJ_DIR)/raycasting



$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
		$(CC) -c $(CFLAGS) $(DEBUGGING) $(LFLAGS) $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) libft/$(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -g

clean:
		make -C mlx clean
		make -C libft clean
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

leak:	all
	leaks -atExit -- ./$(NAME) testing_files/small.cub

.PHONY: all clean re fclean

