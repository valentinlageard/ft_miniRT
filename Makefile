LIBFT		=	libft/libft.a
NAME		=	miniRT
SRC			=	src/miniRT.c \
				src/init.c \
				src/interactions/callbacks.c \
				src/interactions/user_actions.c \
				src/parsing/check_file.c \
				src/parsing/check_objects.c \
				src/parsing/check_utils.c \
				src/parsing/parse_file.c \
				src/parsing/parse_objects.c \
				src/parsing/parse_scene.c \
				src/parsing/parsing_utils.c \
				src/raytracing/img_utils.c \
				src/raytracing/light_point.c \
				src/raytracing/ray.c \
				src/raytracing/raytrace.c \
				src/raytracing/shading.c \
				src/scene/camera.c \
				src/scene/cylinder_maths.c \
				src/scene/cylinder.c \
				src/scene/light.c \
				src/scene/object.c \
				src/scene/plane_maths.c \
				src/scene/plane.c \
				src/scene/sphere_maths.c \
				src/scene/sphere.c \
				src/scene/square_maths.c \
				src/scene/square.c \
				src/scene/triangle_maths.c \
				src/scene/triangle.c \
				src/utils/bitmap.c \
				src/utils/color.c \
				src/utils/free_objects.c \
				src/utils/quit.c \
				src/utils/solve_quadratic.c \
				src/utils/vector_maths.c \
				src/utils/vector_maths2.c \
				src/utils/vector_rotation.c \
				src/utils/vector.c

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
