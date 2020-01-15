/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:01:05 by oshyiata          #+#    #+#             */
/*   Updated: 2018/11/15 18:02:04 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_get_words(const char *s, char c)
{
	size_t		i;
	size_t		word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			word++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (word);
}

static	int		ft_get_size_w(const char *s, char c)
{
	size_t		letter;

	letter = 0;
	while (s[letter] != c && s[letter] != '\0')
		letter++;
	return (letter);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	size_t		words;
	size_t		i;
	int			size_w;
	int			j;

	if (!s)
		return (NULL);
	words = ft_get_words(s, c);
	if (!(res = (char **)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	res[words] = NULL;
	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c)
			j++;
		size_w = ft_get_size_w(s + j, c);
		res[i] = (char *)ft_memalloc(sizeof(char) * (size_w + 1));
		res[i] = ft_strncpy(res[i], s + j, size_w);
		j = j + size_w;
		i++;
	}
	return (res);
}
