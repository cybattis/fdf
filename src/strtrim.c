/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:43:02 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/12 11:39:07 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	strtrim(char *str)
{
	str = strtriml(str);
	strtrimr(str);
}

void	strtrimr(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		str[i--] = 0;
}

char	*strtriml(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (&str[i]);
}
