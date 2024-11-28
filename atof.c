/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:48:49 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/11/28 16:25:49 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	int		sign;
	double	result;
	int		i;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || (*str >= 9 && *str <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		result = ft_atof_decimal(&str[++i], result);
	return (sign * result);
}

double	ft_atof_decimal(const char *str, double result)
{
	int		i;
	double	factor;

	i = 0;
	factor = 1.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		factor *= 10.0;
		i++;
	}
	result = result / factor;
	return (result);
}

void	ft_init(t_f *f)
{
	f->size = SIZE;
	f->zoom = SIZE;
	f->max_iterations = 60;
	f->offset_x = -2.0;
	f->offset_y = -1.5;
	f->axis_range = 3.0;
}
