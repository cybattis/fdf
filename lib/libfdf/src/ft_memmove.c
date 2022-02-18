/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:57:13 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:19:38 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libfdf.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!dst && !src)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst < src)
		return (ft_memcpy(dst, src, n));
	while (n-- > 0)
		d[n] = s[n];
	return (dst);
}
