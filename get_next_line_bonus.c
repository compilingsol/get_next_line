/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-sg <maria-sg@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:34:46 by maria-sg          #+#    #+#             */
/*   Updated: 2023/10/26 16:37:02 by maria-sg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
// #include <stdio.h>
// #include <fcntl.h>

//reads from a file descriptor fd into a buffer
//until it encounters a newline character ('\n')
char	*ft_readfile(int fd, char *buffer)
{
	char	*read_buffer;
	int		read_bytes;

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
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (free(read_buffer), (buffer));
}

//extract a line from a given buffer
char	*ft_findline(char *buffer)
{
	char	*line;
	int		i;
	int		j;

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
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == 0)
		return (free(buffer), (NULL));
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
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_readfile(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_findline(buffer[fd]);
	buffer[fd] = ft_nextline(buffer[fd]);
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("Under.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return 1;
// 	}

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}

// 	close(fd);

// 	return 0;
// }

// int main(int argc, char *argv[])
// {
//     if (argc != 2)
//     {
//         printf("Usage: %s <file_path>\n", argv[0]);
//         return 1;
//     }

//     int fd;
//     char *line;

//     fd = open(argv[1], O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return 1;
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
//     }

//     close(fd);

//     return 0;
// }

// int main(int argc, char *argv[])
// {
//     if (argc != 3)
//     {
//         printf("Usage: %s <file_path> <line_limit>\n", argv[0]);
//         return 1;
//     }

//     int fd;
//     char *line;
//		Convert the limit from a command line argument
//     int lineLimit = atoi(argv[2]);

//     // Open the file specified by the command line argument
//     fd = open(argv[1], O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return 1;
//     }

//     int linesPrinted = 0;

//     // Read and print lines from the file, respecting the line limit
//     while (linesPrinted < lineLimit && (line = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
//         linesPrinted++;
//     }

//     // Close the file
//     close(fd);

//     return 0;
// }