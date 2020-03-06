/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:47 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/06 18:51:28 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>

#include <stdio.h>

#include "../libft/libft.h"

typedef struct		s_vector3 {
	double			x;
	double			y;
	double			z;
}					t_vector3;

typedef struct		s_color {
	int				red;
	int				green;
	int				blue;
} 					t_color;

typedef struct		s_cam {
	t_vector3		*pos;
	t_vector3		*orientation;
	int				fov;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_object {
	char			*type;
	void			*object;
	struct s_object	*next;
}					t_object;

typedef struct		s_sphere {
	t_vector3		*pos;
	double			radius;
	t_color			*color;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_prog {
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	t_cam			*cams;
	t_sphere		*spheres;
	// lights
	// objects
}					t_prog;

// General
t_prog				*init_prog(void);
void				init_win(int width, int height, t_prog *prog);

// Parsing
void				parse_file(char *filename, t_prog *prog);
void				parse_resolution(char *line, t_prog *prog);
void				parse_camera(char *line, t_prog *prog);
void				parse_sphere(char *line, t_prog *prog);
t_vector3			*word_to_vector3(char *word);
t_color				*word_to_color(char *word);

// Camera
t_cam				*new_camera(void);
void				push_back_cam(t_cam **first_cam, t_cam *new_cam);

// Sphere
t_sphere			*new_sphere(void);
void				push_back_sphere(t_sphere **first_sphere, t_sphere *new_sphere);


#endif