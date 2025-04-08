/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:46:24 by mzaian            #+#    #+#             */
/*   Updated: 2024/12/21 11:40:56 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

int	read_mem(int fd, char **mem, char *buffer)
{
	int		readamount;

	readamount = read(fd, buffer, BUFFER_SIZE);
	if (readamount < 1)
		return (readamount);
	buffer[readamount] = 0;
	if (*mem)
		*mem = ft_strnjoin(*mem, buffer, readamount);
	else
		*mem = ft_substr(buffer, 0, ft_strlen(buffer));
	if (!*mem)
		return (-1);
	return (readamount);
}

int	handle_nl(char **mem, char **line)
{
	int		nl;
	char	*tempmem;

	nl = 0;
	while ((*mem)[nl] != '\n' && (*mem)[nl])
		nl++;
	if ((*mem)[nl] == '\n')
	{
		*line = ft_strnjoin(*line, *mem, nl + 1);
		tempmem = ft_substr(*mem, nl + 1, ft_strlen(*mem) - nl - 1);
		free(*mem);
		*mem = tempmem;
		if (!tempmem || !*line)
			return (-2);
		return (-1);
	}
	*line = ft_strnjoin(*line, *mem, nl);
	delchar(mem);
	*mem = NULL;
	return (nl);
}

char	*read_next_line(int fd, char **mem, char **buffer, char **line)
{
	int	nl;
	int	readamount;

	while (1)
	{
		readamount = read_mem(fd, mem, *buffer);
		if (readamount < 0)
			return ((delchar(mem), delchar(buffer), delchar(line)), NULL);
		if (!readamount && !*mem)
			return (*line);
		nl = handle_nl(mem, line);
		if (!*line || nl == -2)
			return ((delchar(mem), delchar(buffer), delchar(line)), NULL);
		if (nl == -1)
			return (*line);
		*line = ft_strnjoin(*line, *mem, nl);
		if (!*line)
			return ((delchar(mem), delchar(buffer), delchar(line)), NULL);
		delchar(mem);
		*mem = NULL;
	}
	if (!**line)
		return ((delchar(mem), delchar(buffer), delchar(line)), NULL);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*mem[1024];
	char		*buffer;
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	line = read_next_line(fd, &mem[fd], &buffer, &line);
	if (buffer)
		delchar(&buffer);
	return (line);
}

/* 

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		i = 1;
	int		fd = open("test.txt", O_RDONLY);
	int		f = 0;

	if (fd < 0 || fd > 1024)
	{
		perror("Error opening file");
		return 1;
	}
	while ((line = get_next_line(fd)))
	{
		char *e = get_next_line(f);
		printf("e%d : '%s'\n", i, e); free(e);
		printf("l%d : '%s'\n", i++, line); free(line);
	}
	close(fd);
	return 0;
}
 */