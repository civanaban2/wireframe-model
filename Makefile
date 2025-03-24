NAME = fdf

NAME_LIBFT = ft
NAME_MINILIBX = mlx_Linux

DIR_BUILD = build
DIR_SRC = src
DIR_INC = inc
DIR_LIBFT = lib/libft
DIR_MINILIBX = lib/minilibx

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = $(DIR_SRC)/fdf.c \
	$(DIR_SRC)/draw_map.c \
	$(DIR_SRC)/error.c \
	$(DIR_SRC)/parser.c \
	$(DIR_SRC)/hooks.c \
	$(DIR_SRC)/rotation_matrix.c \
	$(DIR_SRC)/free_stuff.c \
	$(DIR_SRC)/line_utils.c \
	$(DIR_SRC)/hooks_core.c \
	$(DIR_SRC)/hooks_view.c \
	$(DIR_SRC)/colorize.c

INCLUDES_H = -I$(DIR_INC) -I$(DIR_LIBFT) -I$(DIR_MINILIBX)
INCLUDES_LIB = -L$(DIR_LIBFT) -l$(NAME_LIBFT) -L$(DIR_MINILIBX) -l$(NAME_MINILIBX) -lm -lXext -lX11

OBJ = $(SRC:.c=.o)

BUILD = $(DIR_BUILD)/$(NAME)
BUILD_LIBFT = $(DIR_LIBFT)/lib$(NAME_LIBFT).a
BUILD_MINILIBX = $(DIR_MINILIBX)/lib$(NAME_MINILIBX).a

all: $(BUILD)

$(BUILD): $(BUILD_LIBFT) $(BUILD_MINILIBX) $(OBJ)
	mkdir -p $(DIR_BUILD)
	$(CC) $(OBJ) $(INCLUDES_LIB) -o $(BUILD)

$(BUILD_LIBFT):
	make -C $(DIR_LIBFT)

$(BUILD_MINILIBX):
	make -C $(DIR_MINILIBX)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_H) -c $< -o $@ 

clean:
	rm -f $(OBJ)
	make -C $(DIR_LIBFT) clean

fclean: clean
	rm -rf $(DIR_BUILD)
	make -C $(DIR_LIBFT) fclean
	make -C $(DIR_MINILIBX) clean

re: fclean all

.PHONY: all clean fclean re