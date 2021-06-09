/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:24:44 by marcus            #+#    #+#             */
/*   Updated: 2021/06/09 16:04:38 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	int				i;
	int				len;
	unsigned char	*s_s;

	c = (unsigned char)c;
	s_s = (unsigned char *)s;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (s_s[i] == c)
			return ((void *)(s_s + i));
		i++;
	}
	if (s_s[i] == c)
		return ((void *)(s_s + i));
	return (NULL);
}

static int	add_line(char **str, char **line)
{
	int		size;
	char	*tmp;

	size = 0;
	while ((*str)[size] != '\n' && (*str)[size])
		size++;
	if ((*str)[size] == '\0')
	{
		*line = ft_strdup(*str);
		if (*str != NULL)
		{
			free(*str);
			*str = NULL;
		}
		return (0);
	}
	*line = ft_substr(*str, 0, size);
	tmp = ft_strdup((*str) + size + 1);
	free(*str);
	*str = tmp;
	return (1);
}

static int	output(char **str, char **line, ssize_t size)
{
	if (size < 0)
		return (-1);
	else if (size == 0 && *str == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (add_line(str, line));
}

static char	*check(int fd, char **line)
{
	char	*buffer;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	return (buffer);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*str[OPEN_MAX];
	ssize_t		size;

	buffer = check(fd, line);
	if (!buffer)
		return (-1);
	size = read(fd, buffer, BUFFER_SIZE);
	while (size > 0)
	{
		buffer[size] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
			str[fd] = ft_strjoin(str[fd], buffer);
		if (ft_strchr(str[fd], '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (output(&str[fd], line, size));
}
