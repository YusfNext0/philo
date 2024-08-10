/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:17:09 by ynachat           #+#    #+#             */
/*   Updated: 2024/08/03 12:16:38 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static size_t	c_words(char const *s, char c)
{
	size_t	i;
	size_t	cp;

	i = 0;
	cp = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			cp++;
		i++;
	}
	return (cp);
}

static char	**fre(char **ptr, int a)
{
	while (a)
	{
		free(ptr[a - 1]);
		a--;
	}
	free(ptr);
	return (NULL);
}

static char	**c_char(char **p, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	x;

	(1) && (i = 0, x = 0);
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j > 0)
		{
			p[x] = ft_substr(s, i, j);
			if (p[x++] == NULL)
				return (fre(p, x));
		}
		i += j;
	}
	return (p[x] = NULL, p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	count;

	if (!s)
		return (NULL);
	count = c_words(s, c);
	p = (char **)malloc((count + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	p = c_char(p, s, c);
	return (p);
}
