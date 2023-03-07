/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:00:40 by yloutfi           #+#    #+#             */
/*   Updated: 2023/03/06 16:42:05 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_isdigit(char *str)
{
	int	i;
	int	dot;
	int	sign;

	dot = 0;
	sign = 0;
	i = 1;
	if (str[0] == '-' || str[0] == '+')
		sign++;
	if ((str[0] < 48 || str[0] > 57) && !sign)
		return (0);
	while (str[i])
	{
		if (str[i] == 46)
		{
			dot++;
			i++;
		}
		if (str[i] < 48 || str[i] > 57 || dot > 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp(char *s1, const char *s2, int n)
{	
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			s1[i] += 32;
		i++;
	}
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

long long	ft_atoi(char *str)
{
	int			i;
	long long	sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] && str[i] >= '0' && str[i] <= '9'))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}
