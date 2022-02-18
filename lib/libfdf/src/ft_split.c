/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:21:25 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:13:24 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static size_t	word_count(const char *s, char c);
static void		*get_word(char **strs, const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!strs)
		return (NULL);
	if (get_word(strs, s, c))
		return (NULL);
	return (strs);
}

static void	*get_word(char **strs, const char *s, char c)
{
	char	*start;
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = (char *)s;
		while (*s && *s != c)
			s++;
		if (start != s)
		{
			strs[i] = malloc(sizeof(char) * (s - start + 1));
			if (!strs[i])
				return (ft_free_all(strs, i));
			ft_strlcpy(strs[i], start, (s - start) + 1);
			i++;
		}
	}
	strs[i] = 0;
	return (0);
}

static size_t	word_count(const char *s, char c)
{
	int	i;
	int	words;
	int	is_word;

	i = 0;
	is_word = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			i++;
			is_word = 0;
		}
		while (s[i] && s[i] != c)
		{
			i++;
			is_word = 1;
		}
		if (is_word == 1)
			words++;
	}
	return (words);
}
