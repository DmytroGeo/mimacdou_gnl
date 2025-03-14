/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:46:23 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/14 15:43:20 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_strdup(const char *s)
{
	char	*sd;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	sd = (char *)malloc(sizeof(char) * (size + 1));
	while (s[i])
	{
		sd[i] = s[i];
		i++;
	}
	sd[i] = '\0';
	return (sd);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cabal;
	size_t	fleet;

	fleet = 0;
	if (s1)
		fleet += ft_strlen(s1);
	if (s2)
		fleet += ft_strlen(s2);
	cabal = (char *)malloc(sizeof(char) * (fleet + 1));
	if (!cabal)
		return (NULL);
	ft_strlcpy(cabal, s1, ft_strlen(s1));
	ft_strlcpy(cabal + ft_strlen(s1), s2, ft_strlen(s2));
	cabal[fleet] = '\0';
	return (cabal);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	uc;
	char			*p;

	uc = (unsigned char) c;
	p = (char *) s;
	i = 0;
	if (c == '\0')
		return (p + ft_strlen(p));
	while (p[i] != '\0')
	{
		if (p[i] == uc)
			return (&p[i]);
		i++;
	}
	return (NULL);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}