/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:15:24 by yloutfi           #+#    #+#             */
/*   Updated: 2023/03/07 13:45:16 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	*init_img(void *mlx_ptr)
{
	t_img	*image;

	image = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!image)
		return (NULL);
	image->img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img_ptr,
			&image->bpp, &image->line_len, &image->endian);
	return (image);
}

t_plan	*init_plan(void)
{
	t_plan	*plan;

	plan = (t_plan *)ft_calloc(1, sizeof(t_plan));
	if (!plan)
		return (NULL);
	plan->x_min = -2;
	plan->y_min = -2;
	plan->x_max = 2;
	plan->y_max = 2;
	return (plan);
}

int	set_default(t_fractal *fractal, char **av, int ac)
{
	if (av && ac > 0)
	{
		fractal->type = av[1];
		fractal->max_iteration = MAX_ITER;
		if (ac > 2)
			fractal->max_iteration = ft_atoi(av[2]);
		if (ac > 3)
			fractal->real = ft_fatoi(av[3]);
		if (ac > 4)
			fractal->imaginary = ft_fatoi(av[4]);
	}
	fractal->color_shift = 0;
	fractal->julia_motion = 0;
	fractal->member.x = 0;
	fractal->member.y = 0;
	fractal->plan = init_plan();
	return (0);
}
