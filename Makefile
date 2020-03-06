LIBFT		=	libft/libft.a
NAME		=	miniRT
SRC			=	src/miniRT.c \
				src/init.c \
				src/parsing/parse_file.c \
				src/parsing/parse_scene.c \
				src/parsing/parsing_utils.c \
				src/parsing/parse_objects.c \
				src/scene/camera.c

OBJS		=	$(SRC:.c=.o)

FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc $(FLAGS)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT) -lmlx -lXext -lX11
			$(CC) $(OBJS) $(LIBFT) -o $(NAME) -lmlx -lXext -lX11

%.o: %.c
			$(CC) -Iinclude -c $< -o $@  -lmlx -lXext -lX11

$(LIBFT):
			make -C libft

clean:
			rm -f $(OBJS)
			make -C libft clean

fclean:		clean
			rm -f $(NAME)
			rm -f $(LIBFT)

re:			fclean all

.PHONY: 	all clean fclean re
