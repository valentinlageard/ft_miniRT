/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:47 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/09 21:54:55 by vlageard         ###   ########.fr       */
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
#include <unistd.h>

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

typedef struct		s_object {
	char			type;
	void			*object;
	struct s_object	*next;
}					t_object;

typedef struct		s_ray {
	t_vec3			*orig;
	t_vec3			*dir;
}					t_ray;

typedef struct		s_light_p {
	t_vec3			*hit_p;
	t_vec3			*normal;
	t_vec3			*vcolor;
	t_object		*object;
}					t_light_p;

typedef struct		s_cam {
	t_vec3			*pos;
	t_vec3			*orientation;
	int				fov;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_light {
	t_vec3			*pos;
	double			intensity;
	t_color			*color;
	struct s_light	*next;
}					t_light;

typedef struct		s_sphere {
	t_vec3			*pos;
	double			radius;
	t_color			*color;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_plane {
	t_vec3			*pos;
	t_vec3			*orientation;
	t_color			*color;
	struct s_plane	*next;
}					t_plane;

typedef struct		s_tri {
	t_vec3			*a;
	t_vec3			*b;
	t_vec3			*c;
	t_color			*color;
	struct s_tri	*next;
}					t_tri;

typedef struct		s_square {
	t_vec3			*pos;
	t_vec3			*orientation;
	double			size;
	t_color			*color;
	struct s_square	*next;
}					t_square;

typedef struct		s_cyl {
	t_vec3			*pos;
	t_vec3			*orientation;
	double			diameter;
	double			size;
	t_color			*color;
	struct s_cyl	*next;
}					t_cyl;

typedef struct		s_prog {
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	void			*img_ptr;
	char			*img_pixels;
	t_cam			*cams;
	t_cam			*current_cam;
	double			half_width;
	double			half_height;
	double			ambient_intensity;
	t_color			*ambient_color;
	t_light			*lights;
	t_object		*objects;
	t_sphere		*spheres;
	t_plane			*planes;
	t_tri			*triangles;
	t_square		*squares;
	t_cyl			*cylinders;
}					t_prog;

// General
t_prog			*init_prog(void);
void			init_win(int width, int height, t_prog *prog);
void			init_img(t_prog *prog);

// Raytrace

void			compute_image(t_prog *prog);
t_vec3			*get_shading_point(t_ray *ray, t_object *object, t_prog *prog);

// Parsing
void			parse_file(char *filename, t_prog *prog);
void			parse_resolution(char *line, t_prog *prog);
void			parse_ambient(char *line, t_prog *prog);
void			parse_camera(char *line, t_prog *prog);
void			parse_light(char *line, t_prog *prog);
void			parse_sphere(char *line, t_prog *prog);
void			parse_plane(char *line, t_prog *prog);
void			parse_triangle(char *line, t_prog *prog);
void			parse_square(char *line, t_prog *prog);
void			parse_cyl(char *line, t_prog *prog);
t_vec3			*word_to_vector3(char *word);
t_color			*word_to_color(char *word);

// Vectors
t_vec3			*new_vec3(double x, double y, double z);
t_vec3			*vec3_cpy(t_vec3 *vec3);
t_vec3			*vec3_add(t_vec3 *vec1, t_vec3 *vec2);
t_vec3			*vec3_sub(t_vec3 *vec1, t_vec3 *vec2);
t_vec3			*vec3_mul(t_vec3 *vec1, t_vec3 *vec2);
t_vec3			*vec3_div(t_vec3 *vec1, t_vec3 *vec2);
t_vec3			*vec3_normalize(t_vec3 *vec3);
t_vec3			*vec3_rotateXYZ(t_vec3 *vec3, t_vec3 *ovec3);
t_vec3			*vec3_clamp(t_vec3 *vec, double max);
t_vec3			*vec3_get_nvec3_between(t_vec3 *vec1, t_vec3 *vec2);
t_vec3			*vec3_cross(t_vec3 *vec1, t_vec3 *vec2);
int				vec3_is_equal(t_vec3 *vec1, t_vec3 *vec2);
double			vec3_dot(t_vec3 *vec1, t_vec3 *vec2);
double			vec3_magnitude(t_vec3 *vec3);
double			vec3_cos_angle(t_vec3 *vec1, t_vec3 *vec2);
double			vec3_get_distance(t_vec3 *vec1, t_vec3 *vec2);
void			print_vec3(t_vec3 *vec3); // To remove

// Light points
t_light_p		*new_light_p(t_vec3 *hit_p, t_vec3 *normal, t_vec3 *vcolor, t_object *object);

// Lights
t_light			*new_light(void);
void			push_back_light(t_light **first_light, t_light *new_light);
int				len_lights(t_light *first_light);

// Rays
t_ray			*new_ray(t_vec3 *origin, t_vec3 *dir);
void			free_ray(t_ray *ray);
t_ray			*get_ray(int x, int y, t_prog *prog);

// Camera
t_cam			*new_camera(void);
void			push_back_cam(t_cam **first_cam, t_cam *new_cam);
void			compute_camera_projection(t_prog *prog);

// Object
t_object		*new_object(void);
void			push_back_object(t_object **first_object, t_object *new_object);
double			intersect_object(t_ray *ray, t_object *object);
t_light_p		*get_light_p_object(t_ray *ray, t_object *object);

// Sphere
t_sphere		*new_sphere(void);
void			push_back_sphere(t_sphere **first_sphere, t_sphere *new_sphere);
double			intersect_sphere(t_ray *ray, t_sphere *sphere);
t_light_p		*get_light_p_sphere(t_ray *ray, t_object *object);

// Plane
t_plane			*new_pl(void);
void			push_back_plane(t_plane **first_plane, t_plane *new_plane);
double			intersect_plane(t_ray *ray, t_plane *plane);
t_light_p		*get_light_p_plane(t_ray *ray, t_object *object);

// Triangles
t_tri			*new_tri(void);
void			push_back_tri(t_tri **first_tri, t_tri *new_tri);
double			intersect_tri(t_ray *ray, t_tri *tri);
t_light_p		*get_light_p_tri(t_ray *ray, t_object *obj);

// Squares
t_square		*new_sq(void);
void			push_back_square(t_square **first_square, t_square *new_square);
double			intersect_square(t_ray *ray, t_square *square);
t_light_p		*get_light_p_square(t_ray *ray, t_object *obj);

// Cylinders
t_cyl			*new_cyl(void);
void			push_back_cyl(t_cyl **first_cyl, t_cyl *new_cyl);
double			intersect_cyl(t_ray *ray, t_cyl *cyl);
t_light_p		*get_light_p_cyl(t_ray *ray, t_object *obj);
t_vec3			*get_cyl_axis(t_cyl *cyl);

// Utils
double			get_min_quadratic_solution(double a, double b, double c);

// Colors
t_vec3			*coltovec3(t_color *color);
t_vec3			*get_ambient(t_color *color, double intensity);

// Callbacks
int				key_callback(int k, int *param);

// User actions
void			change_camera(t_prog *prog);

#endif