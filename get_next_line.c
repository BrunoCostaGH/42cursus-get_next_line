/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:47:19 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/23 14:24:42 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (size);
	while (str[size])
		size++;
	return (size);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != c)
	{
		if (str[i] == 0)
			return (0);
		i++;
	}
	return (str + (++i));
}

static char	*handle_stash(int fd, char *stash, char *buf, size_t read_bytes)
{
	stash = ft_strjoin(stash, buf, read_bytes);
	while (!ft_strchr(buf, '\n') && read_bytes == BUFFER_SIZE)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		stash = handle_stash(fd, stash, buf, read_bytes);
	}
	if (!stash || (!ft_strlen(stash) && read_bytes == 0)
		|| read_bytes > BUFFER_SIZE)
	{
		if (stash)
		{
			free(stash);
			stash = 0;
		}
		return (0);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;
	char		*ptr;
	size_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (0);
	read_bytes = read(fd, buf, BUFFER_SIZE);
	stash = handle_stash(fd, stash, buf, read_bytes);
	free(buf);
	if (!stash)
		return (0);
	line = ft_split(stash, '\n');
	ptr = stash;
	stash = ft_strchr(stash, '\n');
	if (stash)
		stash = ft_strdup(stash);
	free(ptr);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int fd;
	char *line;
	fd = open("41_with_n", O_RDONLY);

	line = get_next_line(1000);
	printf("%s", line);
	free(line);
	line = get_next_line(-1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}*/
