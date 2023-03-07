/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:01:07 by yloutfi           #+#    #+#             */
/*   Updated: 2023/03/07 13:40:23 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	_zoom_in(t_fractal *fractal, t_member *dist, t_member *mouse)
{
	t_member	length;

	length.x = (fractal->plan->x_max - fractal->plan->x_min) * 0.5;
	length.y = (fractal->plan->y_max - fractal->plan->y_min) * 0.5;
	fractal->plan->x_max = mouse->x + dist->x;
	fractal->plan->y_max = mouse->y + dist->y;
	fractal->plan->x_min = fractal->plan->x_max - length.x;
	fractal->plan->y_min = fractal->plan->y_max - length.y;
	return ;
}

void	_zoom_out(t_fractal *data, t_member *dist, t_member *mouse)
{
	t_member	length;

	length.x = (data->plan->x_max - data->plan->x_min) / 0.5;
	length.y = (data->plan->y_max - data->plan->y_min) / 0.5;
	data->plan->x_max = mouse->x + dist->x;
	data->plan->y_max = mouse->y + dist->y;
	data->plan->x_min = data->plan->x_max - length.x;
	data->plan->y_min = data->plan->y_max - length.y;
	return ;
}

int	handle_mouse_event(int key, int x, int y, t_fractal *fractal)
{
	t_member	dist;
	t_member	mouse;

	mouse.x = (((float)x / WIDTH) * (fractal->plan->x_max
				- fractal->plan->x_min)) + fractal->plan->x_min;
	mouse.y = (((float)(y * -1) / HEIGHT) * (fractal->plan->y_max
				- fractal->plan->y_min)) + fractal->plan->y_max;
	if (key == 4)
	{
		dist.x = (fractal->plan->x_max - mouse.x) / 0.5;
		dist.y = (fractal->plan->y_max - mouse.y) / 0.5;
		_zoom_out(fractal, &dist, &mouse);
	}
	if (key == 5)
	{
		dist.x = (fractal->plan->x_max - mouse.x) * 0.5;
		dist.y = (fractal->plan->y_max - mouse.y) * 0.5;
		_zoom_in(fractal, &dist, &mouse);
	}
	render(fractal);
	return (0);
}

int	handle_key_event(int key, t_fractal *fractal)
{
	if (key == 53)
		destroy_window(fractal);
	if (key == 15)
		set_default(fractal, NULL, 0);
	if (key == 126 || key == 13)
		fractal->member.y -= HEIGHT / 20;
	if (key == 124 || key == 2)
		fractal->member.x += WIDTH / 20;
	if (key == 125 || key == 1)
		fractal->member.y += HEIGHT / 20;
	if (key == 123 || key == 0)
		fractal->member.x -= WIDTH / 20;
	if (key == 8)
		fractal->color_shift = (fractal->color_shift + 1) % 3;
	if (key == 24)
		fractal->max_iteration++;
	if (key == 27 && fractal->max_iteration > 0)
		fractal->max_iteration--;
	if (key == 49 && fractal->julia_motion == 0)
			fractal->julia_motion = 1;
	else if (key == 49 && fractal->julia_motion == 1)
			fractal->julia_motion = 0;
	render(fractal);
	return (0);
}

int	_julia_motion(int x, int y, t_fractal *fractal)
{
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{	
		if (fractal->julia_motion == 1)
		{
			fractal->real = (((float)x / WIDTH) * (fractal->plan->x_max
						- fractal->plan->x_min)) + fractal->plan->x_min;
			fractal->imaginary = ((((float)y * -1) / HEIGHT)
					* (fractal->plan->y_max - fractal->plan->y_min))
				+ fractal->plan->y_max;
		}
	}
	render(fractal);
	return (0);
}
