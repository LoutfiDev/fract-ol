/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:51:05 by yloutfi           #+#    #+#             */
/*   Updated: 2023/03/07 13:38:40 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractal *fractal, int x, int y, t_color color)
{
	int	i;

	i = (x * fractal->img->bpp / 8)
		+ (y * fractal->img->line_len);
	fractal->img->addr[i] = color.channel[3];
	fractal->img->addr[++i] = color.channel[2];
	fractal->img->addr[++i] = color.channel[1];
	fractal->img->addr[++i] = color.channel[0];
}

t_color	get_color(int iteration, t_fractal *fractol)
{
	t_color	color;
	double	t;

	t = (double)iteration / fractol->max_iteration;
	color.channel[0] = 0;
	color.channel[(0 + fractol->color_shift) % 3 + 1]
		= (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(1 + fractol->color_shift) % 3 + 1]
		= (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2 + fractol->color_shift) % 3 + 1]
		= (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

void	draw(t_fractal *fractal)
{
	t_member	mem;
	t_member	plan;
	int			color;

	color = 0;
	mem.y = fractal->member.y;
	plan.y = 0;
	while (plan.y < HEIGHT)
	{
		plan.x = 0;
		mem.x = fractal->member.x;
		while (plan.x < WIDTH)
		{
			if (ft_strncmp(fractal->type, "m", 1) == 0)
				color = mandelbrot_set(&mem, fractal, fractal->plan);
			if (ft_strncmp(fractal->type, "j", 1) == 0)
				color = julia_set(&mem, fractal, fractal->plan);
			if (ft_strncmp(fractal->type, "ma", 2) == 0)
				color = mandelbar_set(&mem, fractal, fractal->plan);
			put_pixel(fractal, plan.x++, plan.y, get_color(color, fractal));
			mem.x++;
		}
		plan.y++;
		mem.y++;
	}
}
