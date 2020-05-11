/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:06:22 by vlageard          #+#    #+#             */
/*   Updated: 2020/05/11 15:29:07 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	*get_lambertian(t_light_p *lp, t_light *light)
{
	t_vec3	*lv;
	double	illum;

	lv = vec3_get_nvec3_between(light->pos, lp->hit_p);
	illum = vec3_dot(lv, lp->normal) > 0.0 ? vec3_dot(lv, lp->normal) : 0.0;
	illum = illum * light->intensity;
	free(lv);
	return (new_vec3(illum, illum, illum));
}

int		check_shadow(t_ray *shadow_ray, t_light *light, t_object *object, t_prog *prog)
{
	t_object	*tmp;
	double		dist;
	double		new_dist;

	tmp = prog->objects;
	dist = vec3_get_distance(shadow_ray->orig, light->pos);
	while (tmp)
	{
		if (tmp != object)
		{
			new_dist = intersect_object(shadow_ray, tmp);
			if (new_dist < dist && !(new_dist < 0))
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void fill_diffuse_color(t_light_p *lp, t_light *light, t_vec3 **cumu_r_vcolor, t_vec3 **previous_vcolor)
{
    t_vec3	*lambertian;
    t_vec3	*light_vcolor;
    t_vec3	*r_vcolor;

    lambertian = get_lambertian(lp, light);
    light_vcolor = coltovec3(light->color);
    r_vcolor = vec3_mul(lambertian, light_vcolor);
    if (!(*(cumu_r_vcolor)))
        *cumu_r_vcolor = r_vcolor;
    else
    {
        free(*previous_vcolor);
        *previous_vcolor = *cumu_r_vcolor;	
        *cumu_r_vcolor = vec3_add(*previous_vcolor, r_vcolor);
        free(r_vcolor);
    }
    free(lambertian);
    free(light_vcolor);
}

t_vec3	*get_diffuse_shading(t_light_p *lp, t_prog *prog)
{
    t_light *light;
	t_vec3	*cumu_r_vcolor;
	t_vec3	*previous_vcolor;
	t_ray	*shadow_ray;

    light = prog->lights;
	previous_vcolor = NULL;
	cumu_r_vcolor = NULL;
	while (light)
	{
		shadow_ray = new_ray(vec3_cpy(lp->hit_p), vec3_get_nvec3_between(light->pos, lp->hit_p));
		if (!check_shadow(shadow_ray, light, lp->object, prog))
			fill_diffuse_color(lp, light, &cumu_r_vcolor, &previous_vcolor);
		free_ray(shadow_ray);
		light = light->next;
	}
	free(previous_vcolor);
	if (!cumu_r_vcolor)
		cumu_r_vcolor = new_vec3(0, 0, 0);
	return (cumu_r_vcolor);
}

t_vec3	*get_shading_point(t_ray *ray, t_object *object, t_prog *prog)
{
	t_light_p	*lp;
	t_vec3		*cumu_r_vcolor;
	t_vec3		*previous_vcolor;
	t_vec3		*ambient_vcolor;

	cumu_r_vcolor = NULL;
	previous_vcolor = NULL;
	ambient_vcolor = NULL;
	lp = get_light_p_object(ray, object);
	previous_vcolor = get_diffuse_shading(lp, prog);
	ambient_vcolor = get_ambient(prog->ambient_color, prog->ambient_intensity);
	// Ambient + Diffuse
	cumu_r_vcolor = vec3_add(previous_vcolor, ambient_vcolor);
	free(previous_vcolor);
	free(ambient_vcolor);
	previous_vcolor = cumu_r_vcolor;
	// Illumination × object color
	cumu_r_vcolor = vec3_mul(previous_vcolor, lp->vcolor);
	free (previous_vcolor);
	previous_vcolor = cumu_r_vcolor;
	// Clamp to avoid artifacts
	cumu_r_vcolor = vec3_clamp(previous_vcolor, 1.0);
	free(previous_vcolor);
	return (cumu_r_vcolor);
}
