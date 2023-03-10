/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:00:20 by yloutfi           #+#    #+#             */
/*   Updated: 2023/03/07 16:03:03 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	free(fractal->plan);
	free(fractal);
	exit(0);
	return (0);
}

int	render(t_fractal *fractal)
{
	draw(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->img->img_ptr, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	*fractal;

	check_args(ac, av);
	fractal = set_default(av, ac);
	if (!fractal)
		return (MLX_ERROR);
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		return (MLX_ERROR);
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr,
			WIDTH, HEIGHT, "Fract-ol");
	if (!fractal->win_ptr)
		return (MLX_ERROR);
	fractal->img = init_img(fractal->mlx_ptr);
	if (!fractal->img)
		return (MLX_ERROR);
	mlx_hook(fractal->win_ptr, 17, 0, destroy_window, fractal);
	mlx_hook(fractal->win_ptr, 2, 0, handle_key_event, fractal);
	mlx_hook(fractal->win_ptr, 4, 0, handle_mouse_event, fractal);
	if (ft_strncmp(fractal->type, "j", 1) == 0)
		mlx_hook(fractal->win_ptr, 6, 0, _julia_motion, fractal);
	render(fractal);
	mlx_loop(fractal->mlx_ptr);
	return (0);
}
