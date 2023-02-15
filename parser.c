/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:43:26 by yloutfi           #+#    #+#             */
/*   Updated: 2023/02/13 15:57:05 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void print_msg()
{
	char	*line;
	int		fd;

	fd = open("fractol_usage.txt", O_RDONLY);
	write(1, RED, ft_strlen(RED));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		write(1, line, ft_strlen(line));			
	}
	write(1, WHITE, ft_strlen(WHITE));
	close(fd);
	free(line);
	exit(0);
	return ;
}

int check_type(char *str)
{
	if (ft_strncmp(str, "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
		return (1);
	else if (ft_strncmp(str, "Julia", ft_strlen("Julia")) == 0)
		return (1);
	return (0);
}

void	check_args(int ac, char **av)
{
	if (ac <= 1 || ac > 5)
		print_msg();
	if (!check_type(av[1]))
		print_msg();
	if (ac > 2 && (!ft_isdigit(av[2]) || ft_atoi(av[2]) <= 0))
		print_msg();
	if (ac > 3 && !ft_isdigit(av[3]))
		print_msg();
	if (ac > 4 && !ft_isdigit(av[4]))
		print_msg();
	return ;
}