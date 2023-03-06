/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:51:05 by yloutfi           #+#    #+#             */
/*   Updated: 2023/03/06 11:42:24 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, t_color color)
{
	int	i;

	i = (x * data->img.bpp / 8)
		+ (y * data->img.line_len);
	data->img.addr[i] = color.channel[3];
	data->img.addr[++i] = color.channel[2];
	data->img.addr[++i] = color.channel[1];
	data->img.addr[++i] = color.channel[0];
}

t_color	get_color(int iteration, t_fractal *fractol)
{
	t_color	color;
	double	t;

	t = (double)iteration / fractol->max_iteration;
	color.channel[0] = 0;
	color.channel[(0 + fractol->color_shift) % 3 + 1] =
		(int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(1 + fractol->color_shift) % 3 + 1] =
		(int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2 + fractol->color_shift) % 3 + 1] =
		(int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

void	draw(t_data *data)
{
	t_member 	mem;
	t_member 	plan;
	int			color;

	color = 0;
	mem.y = data->fractal.member.y;
	plan.y = 0;
	while (plan.y < HEIGHT)
	{
		plan.x = 0;
		mem.x = data->fractal.member.x;
		while (plan.x < WIDTH)
		{
			if (ft_strncmp(data->fractal.type, "Mandelbrot", 10) == 0)
				color = mandelbrot_set(&mem, &data->fractal, &data->plan);
			if (ft_strncmp(data->fractal.type, "Julia", 5) == 0)
				color = julia_set(&mem, &data->fractal, &data->plan);
			if (ft_strncmp(data->fractal.type, "Mandelbar", 9) == 0)
				color = mandelbar_set(&mem, &data->fractal, &data->plan);
			put_pixel(data, plan.x++, plan.y, get_color(color, &data->fractal));
			mem.x++;
		}
		plan.y++;
		mem.y++;
	}
}
