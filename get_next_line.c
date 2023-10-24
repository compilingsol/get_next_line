/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-sg <maria-sg@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:37:39 by maria-sg          #+#    #+#             */
/*   Updated: 2023/10/24 16:00:36 by maria-sg         ###   ########.fr       */
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

// char	*get_next_line(int fd)
// {
// 	static char	*temp;
// 	char	buffer[BUFFER_SIZE + 1];
// 	int	bytesread;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (0);
	
// 	if (temp && (ft_newline(temp) >= 0))
// 		return ft_printline(&temp);
// 	while ((bytesread = read(fd, buffer, BUFFER_SIZE)) > 0)
// 	{
// 		buffer[bytesread] = '\0';
// 		temp = ft_strjoin(temp, buffer);
// 		if (ft_newline(temp) >= 0)
// 			break;
// 	}
// 	if (bytesread == -1)
// 	{
// 		free(temp);
// 		temp = NULL;
// 		return (NULL);
// 	}
// 	return (ft_printline(&temp));
// }



// char	*ft_readfile(int fd, char *buffer)
// {
// 	char	*readbuffer;
// 	int	readbytes;

// 	readbuffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!readbuffer)
// 		return (NULL);
// 	readbytes = 1;
// 	while (readbytes != 0)
// 	{
// 		readbytes = read(fd, readbuffer, BUFFER_SIZE);
// 		if (readbytes == -1)
// 			return (free(readbuffer), NULL);
// 		readbuffer[readbytes] = '\0';
// 		buffer = ft_strjoin(buffer, readbuffer);
// 		if (ft_strchr(readbuffer, '\n'))
// 			break;
// 	}
// 	return (free(readbuffer), buffer);
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

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (!buffer)
// 		buffer = ft_readfile(fd, buffer);
// 	if (!buffer)
// 		return (NULL);
// 	line = ft_findline(buffer);
// 	if (!line)
// 		return (free(buffer), NULL);
// 	buffer = ft_nextline(&buffer);
// 	return (line);
// }

//reads from a file descriptor fd into a buffer until it encounters a newline character ('\n')
char	*ft_readfile(int fd, char *buffer)
{
	char	*read_buffer;
	int	read_bytes;

	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return ((free(read_buffer), (NULL)));
		read_buffer[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, read_buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (free(read_buffer), (buffer));
}

//extract a line from a given buffer
char	*ft_findline(char *buffer)
{
	char	*line;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (buffer[i] == 0)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (buffer[j] && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
	{
		line[j] = buffer[j];
		j++;
	}	
	line[j] = '\0';
	return (line);
}

//return the next line from a buffer after the current line
char	*ft_nextline(char *buffer)
{
	char	*next_line;
	int	i;
	int	j;
	
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == 0)
	{
		free(buffer);
		return (NULL);
	}
	next_line = (char *)malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	return (free(buffer), (next_line));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_readfile(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_findline(buffer);
	buffer = ft_nextline(buffer);
	return (line);
}
