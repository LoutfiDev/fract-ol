/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:59:57 by yloutfi           #+#    #+#             */
/*   Updated: 2023/03/07 13:42:29 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_spacex(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	return (i);
}

int	ft_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		*i += 1;
	}
	return (sign);
}

int	_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (i);
		i++;
	}
	return (i);
}

void	_add(char *str, int *i, float *nbr)
{
	*nbr *= 10;
	*nbr += str[*i] - '0';
	*i += 1;
}

float	ft_fatoi(char *str)
{
	int		i;
	int		sign;
	float	res;
	float	tmp;
	int		dot_index;

	i = ft_spacex(str);
	sign = ft_sign(str, &i);
	dot_index = _index(str);
	res = 0;
	tmp = 0;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
	{
		if (str[i] == '.')
			i++;
		if (i >= dot_index)
			_add(str, &i, &tmp);
		else
			_add(str, &i, &res);
	}
	while ((int)tmp >= 1)
		tmp = tmp * 0.1;
	res += tmp;
	return (res * sign);
}
