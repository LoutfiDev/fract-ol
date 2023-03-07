/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:00:35 by yloutfi           #+#    #+#             */
/*   Updated: 2023/03/07 13:41:36 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
//only for test
# include <stdio.h>

//Globab macros
# define WIDTH 960
# define HEIGHT 900
# define MLX_ERROR 1
# define MAX_ITER 50

//BUFFER_SIZE used to read buffer from stdin
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//Define some colors
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define WHITE "\033[1;00m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"

//Define structs
typedef struct s_color
{
	int8_t	channel[4];
}	t_color;

typedef struct s_member
{
	float	x;
	float	y;
}	t_member;

typedef struct s_img
{	
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_plan
{
	float	x_min;
	float	y_min;
	float	x_max;
	float	y_max;
}	t_plan;

typedef struct s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_plan		*plan;
	char		*type;
	int			max_iteration;
	float		real;
	float		imaginary;
	int			color_shift;
	int			julia_motion;
	t_member	member;
}	t_fractal;

//Libft_functions 
int			ft_strlen(char *str);
int			ft_isdigit(char *str);
int			ft_strncmp(char *s1, const char *s2, int n);
long long	ft_atoi(char *str);
float		ft_fatoi(char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);

//get_next_line function
char		*get_next_line(int fd);
int			ft_memchr(char *str, int c, int n);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *str, int start, int len);

//parsing_functions
void		check_args(int ac, char **av);

//initialize functions
int			set_default(t_fractal *fractal, char **av, int ac);
t_img		*init_img(void *mlx_ptr);
t_plan		*init_plan(void);

//drawing function
void		draw(t_fractal *fractal);
int			mandelbrot_set(t_member *pos, t_fractal *fractal, t_plan *plan_c);
int			julia_set(t_member *pos, t_fractal *fractal, t_plan *plan_c);
int			mandelbar_set(t_member *pos, t_fractal *fractal, t_plan *plan_c);
t_color		get_color(int iteration, t_fractal *fractol);
void		put_pixel(t_fractal *fractal, int x, int y, t_color color);

//Events functions
int			render(t_fractal *fractal);
int			handle_mouse_event(int key, int x, int y, t_fractal *fratal);
int			handle_key_event(int key, t_fractal *fractal);
int			_julia_motion(int x, int y, t_fractal *fratal);
int			destroy_window(t_fractal *fractal);

#endif