/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:45:56 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/14 18:20:14 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

char	*last_add(char *buffer, char *str)
{
		char	*tmp;
		char	*line_to_be_returned;
		char	*pos_of_newline;

		pos_of_newline = ft_strchr(buffer, '\n');
		tmp = malloc((pos_of_newline - buffer + 2) * sizeof(char));
		if (!tmp)
			return (NULL);
		ft_strlcpy(tmp, buffer, pos_of_newline - buffer + 1);
		ft_strlcpy(buffer, pos_of_newline + 1, ft_strlen(pos_of_newline + 1) + 1);
		line_to_be_returned = ft_strjoin(str, tmp);
		free(tmp);
		free(str);
		return(line_to_be_returned);
}

void	read_and_append(char *buffer, char **str)
{
	char	*tmp;
	
	tmp = ft_strjoin(*str, buffer);
	free(*str);
	*str = tmp;
}

char	*gnl(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char        *str;
	size_t		bytes_read;
	char		*tmp;
	char		*pos_of_newline;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	pos_of_newline = ft_strchr(buffer, '\n');
	if (pos_of_newline)
	{
		str = malloc((pos_of_newline - buffer + 2) * sizeof(char));
		if (!str)
			return (NULL);
		// buffer is itself an address of the first char of buffer,
		// so we can do pointer arithmetic on it.
		// the +2 comes from the fact that we need to allocate space for '\0'
		// and copy accross the first char. 
		ft_strlcpy(str, buffer, pos_of_newline - buffer + 1);
		// copy all relvant things to the string.
		ft_strlcpy(buffer, pos_of_newline + 1, ft_strlen(pos_of_newline + 1));
		// shift contents of buffer.
		return (str);
	}
	str = ft_strdup(buffer); // this has a malloc in it. Make sure to free at some point.
	// now we do the following until we've found an EOF.
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read == BUFFER_SIZE)
	{
		if (!ft_strchr(buffer, '\n'))
			read_and_append(buffer, &str);
		else
			return (last_add(buffer, str));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	buffer[bytes_read] = '\0';
	if (ft_strchr(buffer, '\n'))
		return(last_add(buffer, str));
	tmp = ft_strjoin(str, buffer);
	ft_bzero(buffer, BUFFER_SIZE);
	free(str);
	str = tmp;
	if (ft_strlen(str) > 0)
		return(str);
	free(tmp);
	return (NULL);
}
