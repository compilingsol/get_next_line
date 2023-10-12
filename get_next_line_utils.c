/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-sg <maria-sg@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:08:12 by maria-sg          #+#    #+#             */
/*   Updated: 2023/10/12 20:01:43 by maria-sg         ###   ########.fr       */
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

static int ft_newline(const char *str)
{
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    return i;
}