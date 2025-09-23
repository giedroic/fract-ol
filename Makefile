CFLAGS = -Wall -Wextra -Werror -g -I libft/include -I minilibx-linux -I /usr/include -I include -O3

LDFLAGS = -L libft -L minilibx-linux -L /usr/lib

LDLIBS = -l ft -l mlx -l Xext -l X11 -l m -l z

MKDIR = mkdir -p
RMDIR = rm -rf

NAME = main
NAME := $(addprefix bin/,$(NAME))

BIN_DIR = bin/
OBJ_DIR = obj/

MAIN_SRC = main.c
UTILS_SRC = fractal_init.c fractal_render.c math_utils.c

UTILS_OBJ = $(addprefix obj/, $(UTILS_SRC:%.c=%.o))
MAIN_OBJ = $(addprefix obj/, $(MAIN_SRC:%.c=%.o))

INCLUDE = include/fractol.h

.PHONY : all libft minilibx-linux clean fclean re

all : libft minilibx-linux $(OBJ_DIR) $(BIN_DIR) $(NAME)

bin/main: $(MAIN_OBJ) $(UTILS_OBJ)
	$(CC) $< $(UTILS_OBJ) $(LDFLAGS) -o $@ $(LDLIBS)

obj/%.o : src/%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

libft :
	$(MAKE) -C libft

minilibx-linux :
	$(MAKE) -C minilibx-linux

$(OBJ_DIR) :
	$(MKDIR) $@	

$(BIN_DIR) :
	$(MKDIR) $@

clean :
	$(MAKE) -C minilibx-linux clean
	$(MAKE) -C libft clean
	$(RM) $(POLLOCK_OBJ)
	$(RMDIR) $(OBJ_DIR)

fclean :
	$(MAKE) -C minilibx-linux clean
	$(MAKE) -C libft fclean
	$(RM) $(POLLOCK_OBJ) $(NAME)
	$(RMDIR) $(OBJ_DIR) $(BIN_DIR)

re : fclean all
