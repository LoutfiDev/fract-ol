/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:00:35 by yloutfi           #+#    #+#             */
/*   Updated: 2023/02/13 16:40:42 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//Libft_functions 
int	ft_strlen(char *str);
int	ft_isdigit(char *str);
int	ft_strncmp(const char *s1, const char *s2, int n);
long long	ft_atoi(char *str);

//parsing_functions
void	check_args(int ac, char **av);