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
	write(1, "ERROR\n", 6);
	exit(1);
	return ;
}

int check_type(char *str)
{
	if (ft_strncmp(str, "Mandelbrot", ft_strlen(str)) == 0)
		return (1);
	else if (ft_strncmp(str, "Julia", ft_strlen(str)) == 0)
		return (1);
	return (0);
}

void	check_args(int ac, char **av)
{
	int	valid;
	
	valid = 0;
	if (ac > 1 && ac < 6)
	{
		if (check_type(av[1]))
			valid = 1;
		else if (ac > 2 && ft_isdigit(av[2]) && ft_atoi(av[2]) > 0)
			valid = 1;
		else if (ac > 3 && ft_isdigit(av[3]))
			valid = 1;
		else if (ac > 4 && ft_isdigit(av[4]))
			valid = 1;
	}
	if (!valid)
		print_msg();
	return ;
}