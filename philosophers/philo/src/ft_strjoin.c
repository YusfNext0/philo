/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:17:24 by ynachat           #+#    #+#             */
/*   Updated: 2024/08/03 12:16:45 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static char	*ft_strxcpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	len1;
	size_t	len2;

	if (!s1)
		return (free(s1), s1 = NULL, ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = malloc(((sizeof(char)) * (len1 + len2 + 1)));
	if (!p)
		return (free(s1), s1 = NULL, NULL);
	ft_strxcpy(p, s1, len1);
	ft_strxcpy(p + len1, s2, len2);
	s1 = NULL;
	return (p);
}