LIBFT		=	libft/libft.a
NAME		=	miniRT
SRC			=	src/miniRT.c \
				src/init.c \
				src/parsing/parse_file.c \
				src/parsing/parse_scene.c \
				src/parsing/parsing_utils.c \
				src/parsing/parse_objects.c \
				src/raytracing/raytrace.c \
				src/raytracing/ray.c \
				src/raytracing/img_utils.c \
				src/raytracing/shading.c \
				src/raytracing/light_point.c \
				src/scene/camera.c \
				src/scene/light.c \
				src/scene/object.c \
				src/scene/sphere.c \
				src/scene/sphere_maths.c \
				src/utils/color.c \
				src/utils/vector.c \
				src/utils/vector_maths.c \
				src/utils/vector_maths2.c \
				src/utils/vector_rotation.c \
				src/utils/solve_quadratic.c

OBJS		=	$(SRC:.c=.o)

FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc $(FLAGS)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT) -lmlx -lXext -lX11 -lm
			$(CC) $(OBJS) $(LIBFT) -o $(NAME) -lmlx -lXext -lX11 -lm

%.o: %.c
			$(CC) -Iinclude -c $< -o $@  -lmlx -lXext -lX11 -lm

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
