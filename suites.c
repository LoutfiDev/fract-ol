/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suites.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:50:32 by yloutfi           #+#    #+#             */
/*   Updated: 2023/03/06 10:40:03 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	module(float x, float y)
{
	return (pow(x, 2) + pow(y, 2));
}

int	julia_set(t_member *pos, t_fractal *fractal, t_plan *plan_c)
{
	t_member 	mem;
	t_member 	tmp;
	int			i;

	mem.x = ((pos->x / WIDTH) * (plan_c->x_max
			- plan_c->x_min)) + plan_c->x_min;	
	mem.y = (((pos->y * -1) / HEIGHT) * (plan_c->y_max
			- plan_c->y_min)) + plan_c->y_max;
	i = 0;
	while (module(mem.x, mem.y) < 4 && i < fractal->max_iteration)
	{
		tmp.x = mem.x;
		tmp.y = mem.y;
		mem.x = pow(tmp.x, 2) - pow(tmp.y, 2) + fractal->real;
		mem.y = (2 * tmp.x * tmp.y) + fractal->imaginary;
		i++;
	}
	if (i == fractal->max_iteration)
		return (0);
	return (i);
}

int	mandelbar_set(t_member *pos, t_fractal *fractal, t_plan *plan_c)
{
	t_member 	mem;
	t_member 	tmp;
	t_member	c;
	int			i;

	c.x = ((pos->x / WIDTH) * (plan_c->x_max
			- plan_c->x_min)) + plan_c->x_min;	
	c.y = (((pos->y * -1) / HEIGHT) * (plan_c->y_max
			- plan_c->y_min)) + plan_c->y_max;
	i = 0;
	mem.x = 0;
	mem.y = 0;
	while (module(mem.x, mem.y) < 4 && i < fractal->max_iteration)
	{
		tmp.x = mem.x;
		tmp.y = mem.y;
		mem.x = pow(tmp.x, 2) - pow(tmp.y, 2) + c.x;
		mem.y = (2 * tmp.x * tmp.y * -1) + c.y;
		i++;
	}
	if (i == fractal->max_iteration)
		return (0);
	return (i);
}

int	mandelbrot_set(t_member *pos, t_fractal *fractal, t_plan *plan_c)
{
	t_member 	mem;
	t_member 	tmp;
	t_member	c;
	int			i;

	c.x = ((pos->x / WIDTH) * (plan_c->x_max
			- plan_c->x_min)) + plan_c->x_min;	
	c.y = (((pos->y * -1) / HEIGHT) * (plan_c->y_max
			- plan_c->y_min)) + plan_c->y_max;
	i = 0;
	mem.x = 0;
	mem.y = 0;
	while (module(mem.x, mem.y) < 4 && i < fractal->max_iteration)
	{
		tmp.x = mem.x;
		tmp.y = mem.y;
		mem.x = pow(tmp.x, 2) - pow(tmp.y, 2) + c.x;
		mem.y = (2 * tmp.x * tmp.y) + c.y;
		i++;
	}
	if (i == fractal->max_iteration)
		return (0);
	return (i);
}

