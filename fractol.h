/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:00:35 by yloutfi           #+#    #+#             */
/*   Updated: 2023/02/14 16:37:21 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
//only for test
# include <stdio.h>

//BUFFER_SIZE used to read buffer from stdin
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//Define some colors
#  define RED "\033[1;31m"
#  define GREEN "\033[1;32m"
#  define WHITE "\033[1;00m"
#  define YELLOW "\033[1;33m"
#  define BLUE "\033[1;34m"
#  define PURPLE "\033[1;35m"
#  define CYAN "\033[1;36m"

//Libft_functions 
int			ft_strlen(char *str);
int			ft_isdigit(char *str);
int			ft_strncmp(const char *s1, const char *s2, int n);
long long	ft_atoi(char *str);

//get_next_line function
char		*get_next_line(int fd);
int			ft_memchr(char *str, int c, int n);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *str, int start, int len);

//parsing_functions
void		check_args(int ac, char **av);

#endif