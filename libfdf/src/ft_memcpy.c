/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:32:39 by cybattis          #+#    #+#             */
/*   Updated: 2021/11/12 13:47:57 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (!src && !dst)
		return (NULL);
	i = 0;
	s = (unsigned char *)src;
	d = dst;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
