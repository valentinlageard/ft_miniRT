/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:47 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/13 16:32:40 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

#include <stdio.h>

#include "../libft/libft.h"

#define PI 3.141592  

typedef struct		s_vec3 {
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct		s_color {
	int				red;
	int				green;
	int				blue;
} 					t_color;

typedef struct		s_ray {
	t_vec3			*orig;
	t_vec3			*dir;
}					t_ray;

typedef struct		s_cam {
	t_vec3			*pos;
	t_vec3			*orientation;
	int				fov;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_object {
	char			type;
	void			*object;
	struct s_object	*next;
}					t_object;

typedef struct		s_sphere {
	t_vec3			*pos;
	double			radius;
	t_color			*color;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_prog {
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	void			*img_ptr;
	char			*img_pixels;
	t_cam			*cams;
	t_cam			*current_cam;
	t_object		*objects;
	t_sphere		*spheres;
	// lights
	// other objects : planes, triangles, etc...
}					t_prog;

// General
t_prog				*init_prog(void);
void				init_win(int width, int height, t_prog *prog);

// Raytrace

void				compute_image(t_prog *prog);

// Parsing
void				parse_file(char *filename, t_prog *prog);
void				parse_resolution(char *line, t_prog *prog);
void				parse_camera(char *line, t_prog *prog);
void				parse_sphere(char *line, t_prog *prog);
t_vec3				*word_to_vector3(char *word);
t_color				*word_to_color(char *word);

// Vectors
t_vec3				*new_vec3(double x, double y, double z);
int					vec3_is_equal(t_vec3 *vec1, t_vec3 *vec2);
t_vec3				*vec3_add(t_vec3 *vec1, t_vec3 *vec2);
t_vec3				*vec3_sub(t_vec3 *vec1, t_vec3 *vec2);
t_vec3				*vec3_mul(t_vec3 *vec1, t_vec3 *vec2);
t_vec3				*vec3_div(t_vec3 *vec1, t_vec3 *vec2);
double				vec3_dot(t_vec3 *vec1, t_vec3 *vec2);

// Rays
t_ray				*new_ray(t_vec3 *origin, t_vec3 *dir);
void				free_ray(t_ray *ray);

// Camera
t_cam				*new_camera(void);
void				push_back_cam(t_cam **first_cam, t_cam *new_cam);

// Object
t_object			*new_object(void);
void				push_back_object(t_object **first_object, t_object *new_object);

// Sphere
t_sphere			*new_sphere(void);
void				push_back_sphere(t_sphere **first_sphere, t_sphere *new_sphere);
double				intersect_sphere(t_ray *ray, t_sphere *sphere);

// Utils
double				get_min_quadratic_solution(double a, double b, double c);

#endif