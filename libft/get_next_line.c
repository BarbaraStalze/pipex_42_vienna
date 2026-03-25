/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:43:51 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/11 16:24:31 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*remainder_from_end(char *remainder, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	j = 0;
	while (line[i + j] != 0)
	{
		remainder[j] = line[i + j];
		j++;
	}
	remainder[j] = 0;
	line[i] = 0;
	return (line);
}

char	*remainder_to_start(char *remainder)
{
	char	*line;

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = 0;
	line = ft_strjoin_get(line, remainder);
	remainder[0] = 0;
	return (line);
}

char	*find_nl(char *remainder, char *buffer, int fd)
{
	int		b_read;
	char	*line;

	line = remainder_to_start(remainder);
	if (!line)
		return (NULL);
	while (1)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read <= 0)
			break ;
		buffer[b_read] = 0;
		line = ft_strjoin_get(line, buffer);
		if (!line)
			return (NULL);
		if (ft_str_i(buffer, '\n') != 0)
			return (remainder_from_end(remainder, line));
		else if (b_read < BUFFER_SIZE)
			return (line);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	return (line);
}

char	*nl_in_remainder(char *remainder)
{
	char	*line;
	size_t	i;
	size_t	j;

	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\n';
	i++;
	line[i] = 0;
	j = 0;
	while (remainder[i + j] != 0)
	{
		remainder[j] = remainder[i + j];
		j++;
	}
	remainder[j] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	static char	buffer[BUFFER_SIZE + 1];

	buffer[0] = 0;
	if (ft_str_i(remainder, '\n') != 0)
		return (nl_in_remainder(remainder));
	else
		return (find_nl(remainder, buffer, fd));
}

/*
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *result;

	fd = open("empty1.txt", O_RDONLY);
	if (fd == -1)
		return 1;
//	result = get_next_line(fd);
//	if (result == NULL)
//		printf("NULL");
	while ((result = get_next_line(fd)))
	{
		printf("%s\n", result);
		free(result);
	}
	close(fd);
	return 0;
}
*/
/*
#include <stdio.h>

int main(void)
{
	printf("%s", (get_next_line(1)));
}
*/
