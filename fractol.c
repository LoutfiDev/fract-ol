/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:00:20 by yloutfi           #+#    #+#             */
/*   Updated: 2023/03/06 09:58:29 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	draw(&data->img, &data->fractal, &data->plan);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	// mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	return (0);
}

int	_reset(t_data *data)
{
	data->plan.x_min = -2;
	data->plan.y_min = -2;
	data->plan.x_max = 2;
	data->plan.y_max = 2;
	data->fractal.palette = 0;
	data->fractal.member.x = 0;
	data->fractal.member.y = 0;
	return (0);
}

int	handle_key_event(int key, t_data *data)
{
	if (key == 53)
		destroy_window(data);
	if (key == 15)
		_reset(data);
	if(key == 126 || key == 13)
		data->fractal.member.y -= HEIGHT / 20;
	if(key == 124 || key == 2)
		data->fractal.member.x += WIDTH / 20;
	if(key == 125 || key == 1)
		data->fractal.member.y += HEIGHT / 20;
	if(key == 123 || key == 0)
		data->fractal.member.x -= WIDTH / 20;
	if (key == 12 && data->fractal.palette > 0)
		data->fractal.palette--;
	if (key == 14 && data->fractal.palette < 2)
		data->fractal.palette++;
	if (key == 24)
		data->fractal.max_iteration++;
	if (key == 27 && data->fractal.max_iteration > 0)
		data->fractal.max_iteration--;
	render(data);
	return (0);
}

void _zoom_in(t_data *data, t_member *dist, t_member *mouse)
{
	t_member	length;
	
	length.x = (data->plan.x_max - data->plan.x_min) * 0.5;
	length.y = (data->plan.y_max - data->plan.y_min) * 0.5;
	data->plan.x_max = mouse->x + dist->x;
	data->plan.y_max = mouse->y + dist->y;
	data->plan.x_min = data->plan.x_max - length.x;
	data->plan.y_min = data->plan.y_max - length.y;
	return ;	
}

void _zoom_out(t_data *data, t_member *dist, t_member *mouse)
{
	t_member	length;
	
	length.x = (data->plan.x_max - data->plan.x_min) / 0.5;
	length.y = (data->plan.y_max - data->plan.y_min) / 0.5;
	data->plan.x_max = mouse->x + dist->x;
	data->plan.y_max = mouse->y + dist->y;
	data->plan.x_min = data->plan.x_max - length.x;
	data->plan.y_min = data->plan.y_max - length.y;
	return ;	
}

int	handle_mouse_event(int key, int x, int y, t_data *data)
{
	t_member	dist;
	t_member	mouse;
	
	mouse.x = (((float)x / WIDTH) * (data->plan.x_max
			- data->plan.x_min)) + data->plan.x_min;	
	mouse.y = (((float)(y * -1) / HEIGHT) * (data->plan.y_max
			- data->plan.y_min)) + data->plan.y_max;
	if (key == 4) //zoom out
	{
		dist.x = (data->plan.x_max - mouse.x) / 0.5;
		dist.y = (data->plan.y_max - mouse.y) / 0.5;
		_zoom_out(data, &dist, &mouse);
	}
	if (key == 5) // zoom in
	{
		dist.x = (data->plan.x_max - mouse.x) * 0.5;
		dist.y = (data->plan.y_max - mouse.y) * 0.5;
		_zoom_in(data, &dist, &mouse);
	}
	render(data);
	return (0);
}

int	_init(t_data *data, char **av, int ac)
{
	data->fractal.type = av[1];
	data->fractal.max_iteration = MAX_ITER;
	if (ac > 2)
		data->fractal.max_iteration = ft_atoi(av[2]);
	if (ac > 3)
		data->fractal.real = ft_fatoi(av[3]);
	if (ac > 4)
		data->fractal.imaginary = ft_fatoi(av[4]);
	data->plan.x_min = -2;
	data->plan.y_min = -2;
	data->plan.x_max = 2;
	data->plan.y_max = 2;
	data->fractal.palette = 0;
	data->fractal.member.x = 0;
	data->fractal.member.y = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_args(ac, av);
	_init(&data, av, ac);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	render(&data);
	mlx_hook(data.win_ptr, 17, 0, destroy_window, &data);
	mlx_key_hook(data.win_ptr, handle_key_event, &data);
	mlx_mouse_hook(data.win_ptr, handle_mouse_event, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
