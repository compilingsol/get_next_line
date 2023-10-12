/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-sg <maria-sg@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:37:39 by maria-sg          #+#    #+#             */
/*   Updated: 2023/10/12 20:01:23 by maria-sg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// read the file
// find where the line ends \n (or when the file ends and doesnt have \n. read() shall return 0 to indicate end-of-file.)
// create a buffer with malloc to work as a temporary save
// remember where you left off (with a counter?) The read function can recall the las position in the file
// return the line you read including the \n (add if necessary?)
// free?
// remember the nulls!
// size_t read(int fd, void *buf, size_t count)

// char	*readline(int fd, char **line, char **leftstr)
// {
// 	char	*buff;
// 	int	readbytes;
	
// 	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buff)
// 		return (NULL);
// 	readbytes = read(fd, buff, BUFFER_SIZE);
// 	if (readbytes <= 0)
// 	{
// 		free(buff);
// 		return (NULL);
// 	}
// 	buff[readbytes] = '\0';
// 	return (readbytes);
// }

char	*get_next_line(int fd)
{
	static char	*temp;
	char	buffer[BUFFER_SIZE + 1];
	int	bytesread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	
	if (temp && (ft_newline(temp) >= 0))
		return ft_printline(&temp);
	while ((bytesread = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytesread] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (ft_newline(temp) >= 0)
			break;
	}
	if (bytesread == -1)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	return (ft_printline(&temp));
}