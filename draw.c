/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:51:05 by yloutfi           #+#    #+#             */
/*   Updated: 2023/03/06 09:51:54 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color; 
}

int	get_color(t_fractal *fractal, int color)
{
	int	palettes[3][4];

	palettes[0][0] = 0x29339B;
	palettes[0][1] = 0x74A4BC;
	palettes[0][2] = 0xB6D6CC;
	palettes[0][3] = 0xF1FEC6;
	palettes[1][0] = 0x00B9AE;
	palettes[1][1] = 0x03312E;
	palettes[1][2] = 0x037171;
	palettes[1][3] = 0xFF3A20;
	palettes[2][0] = 0x009F93;
	palettes[2][1] = 0x02C3BD;
	palettes[2][2] = 0x33658A;
	palettes[2][3] = 0x55DDE0;
	if (color == 0)
		return (0);
	return (palettes[fractal->palette][color % 4]);
}

void	draw(t_img *img, t_fractal *fractal, t_plan *plan_c)
{
	t_member 	mem;
	t_member 	plan;
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
			if (ft_strncmp(fractal->type, "Mandelbrot", 10) == 0)
				color = mandelbrot_set(&mem, fractal, plan_c);
			if (ft_strncmp(fractal->type, "Julia", 5) == 0)
				color = julia_set(&mem, fractal, plan_c);
			if (ft_strncmp(fractal->type, "Mandelbar", 9) == 0)
				color = mandelbar_set(&mem, fractal, plan_c);
			my_mlx_pixel_put(img, plan.x++, plan.y, get_color(fractal, color));
			mem.x++;
		}
		plan.y++;
		mem.y++;
	}
}
