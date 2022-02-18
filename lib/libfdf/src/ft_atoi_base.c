/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:35:55 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:13:22 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	ft_atoi_base(const char *s, const char *base)
{
	int	i;
	int	res;
	int	sign;
	int	base_size;

	i = 0;
	res = 0;
	sign = 1;
	base_size = ft_strlen(base);
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] && ft_strichr(base, s[i]) != -1)
		res = res * base_size + (ft_strichr(base, s[i++]));
	return (res * sign);
}
