/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-sg <maria-sg@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:38:41 by maria-sg          #+#    #+#             */
/*   Updated: 2023/10/24 15:03:24 by maria-sg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 50
// #endif

// # include <unistd.h>
// # include <stdlib.h>

// char	*get_next_line(int fd);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strchr(const char *s, int c);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// char	*ft_strdup(const char *s1);
// size_t	ft_strlen(const char *s);

// #endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
//char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s1);

char	*ft_strjoin(char *s1, char *s2);

#endif