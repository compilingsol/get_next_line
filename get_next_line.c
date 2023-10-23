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

// char	*ft_readfile(int fd, char *buffer)
// {
// 	char	*readbuffer;
// 	int	readbytes;

// 	readbuffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!readbuffer)
// 		return (NULL);
// 	while ((readbytes = read(fd, readbuffer, BUFFER_SIZE)) != 0)
// 	{
// 		if (readbytes == -1)
// 		{
// 			free (readbuffer);
// 			return (NULL);
// 		}
// 		readbuffer[readbytes] = '\0';
// 		buffer = ft_strjoin(buffer, readbuffer);
// 		if (ft_strchr(readbuffer, '\n'))
// 			break;
// 	}
// 	free (readbuffer);
// 	return (buffer);
// }

// char	*ft_findline(char *buffer)
// {
// 	int	length;
// 	int	i;
// 	char	*line;

// 	length = 0;
// 	i = 0;
// 	if (buffer[i] == 0)
// 		return (NULL);
// 	while (buffer[i] && buffer[i] != '\n')
// 	{
// 		i++;
// 		length++;
// 	}
// 	line = (char *)malloc((length + 2) * sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	ft_strlcpy(line, buffer, length);
// 	line[length] = '\n';
// 	line[length + 1] = '\0';
// 	return (line);
// }

// char	*ft_nextline(char **buffer)
// {
// 	char	*currentline;
// 	char	*nextline;
// 	char	*line;
// 	size_t	length;
	
// 	if (!*buffer || **buffer == '\0')
// 		return (NULL);
// 	currentline = *buffer;
// 	nextline = ft_strchr(currentline, '\n');
// 	if (nextline == NULL)
// 	{
// 		*buffer = NULL;
// 		return (ft_strdup(currentline));
// 	}
// 	length = nextline - currentline;
// 	line = (char *)malloc((length + 2) * sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	ft_strlcpy(line, currentline, length);
// 	line[length] = '\n';
// 	line[length + 1] = '\0';
// 	*buffer = nextline + 1;
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char	*line;

// 	buffer = NULL;
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (!buffer)
// 		buffer = ft_readfile(fd, buffer);
// 	if (!buffer)
// 		return (NULL);
// 	line = ft_findline(buffer);
// 	if (!line)
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	buffer = ft_nextline(&buffer);
// 	return (line);
// }

char	*ft_next(char *buffer)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == 0)
	{
		free(buffer);
		return (NULL);
	}
	next_line = (char *)malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (next_line == 0)
		return (0);
	i++;
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	return (next_line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (buffer[i] == 0)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (line == 0)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	char	*read_buffer;
	int		bytes_read;

	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (read_buffer == 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, read_buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (read_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (buffer == 0)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}