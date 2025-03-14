/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:47:09 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/14 18:17:24 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GNL_H
# define GNL_H

//////////////////////////LIBRARIES START//////////////////////

# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>

//////////////////////////LIBRARIES END////////////////////////

//////////////////////////TOOLS START//////////////////////////

//# define BASE16 "0123456789abcdef"

//# define FD_SIZE 10

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

//////////////////////////TOOLS END////////////////////////////

/////////////////////////STRUCTS START/////////////////////////
/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}					t_list;
*/
/////////////////////////STRUCTS END///////////////////////////

//GET_NEXT_LINE
char				*gnl(int fd);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);

#endif