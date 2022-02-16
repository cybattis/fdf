/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:43:02 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 22:39:32 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_trim(char *str)
{
	ft_trimr(str);
	return (ft_triml(str));
}

char	*ft_trimr(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		str[i--] = 0;
	return (str);
}

char	*ft_triml(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (ft_isspace(str[i]))
		str[i++] = 0;
	return (&str[i]);
}
