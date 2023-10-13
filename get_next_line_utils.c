/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-sg <maria-sg@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:08:12 by maria-sg          #+#    #+#             */
/*   Updated: 2023/10/13 14:57:48 by maria-sg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != (char)c)
// 	{
// 		if (s[i] == '\0')
// 			return (NULL);
// 		i++;
// 	}
// 	return ((char *)&s[i]);
// }

// static int ft_newline(const char *str)
// {
//     int i = 0;
//     while (str[i] != '\0' && str[i] != '\n')
//         i++;
//     return i;
// }

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1, int len)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}

int	ft_newline(char *c)
{
	int	i;

	if (!c)
		return (0);
	while (c[i])
	{
		if (c[i] == '\n')
			return (1);
	}
	return (0);
}

char	*ft_printline(char **c)
{
	int	pos;
	char	*line;
	char	*str;

	if (!*c)
		return (NULL);
	str = *c;
	pos = 0;
	while (str[pos] && str[pos] != '\n')
		pos++;
	if (str[pos] == '\n')
		pos++;
	line = ft_strdup(str, pos);
	*c = ft_strdup(str + pos, ft_strlen(str + pos));
	if (str)
		free(str);
	str = NULL;
	return (line);
}

