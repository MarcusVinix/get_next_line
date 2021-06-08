/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:24:44 by marcus            #+#    #+#             */
/*   Updated: 2021/06/08 20:18:50 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static void	boom(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

static int add_line(char **str, char **line)
{
	int		size;
	char	*tmp;

	size = 0;
	while ((*str)[size] != '\n' && (*str)[size])
		size++;
	if ((*str)[size] == '\0')
	{
		*line = ft_strdup(*str);
		boom(str);
		return (0);//end of file
	}
	*line = ft_substr(*str, 0, size);
	tmp = ft_strdup((*str) + size + 1);
	free(*str);
	*str = tmp;
	return (1);//new line
}

static int	output(char **str, char **line, ssize_t size)
{
	if (size == -1)
		return (-1);//error
	else if (size == 0 && *str == NULL)
	{
		*line = ft_strdup("");
		return (0);//end of file
	}
	return (add_line(str, line));
}

int			get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*str;
	ssize_t		size;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);//error
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer)
		return (-1);
	size = read(fd, buffer, BUFFER_SIZE);
	while (size > 0)
	{
		buffer[size] = '\0';
		if (str == NULL)
			str = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str, buffer);
			free(str);
			str = tmp;
		}
		if (ft_strchr(str, '\n'))
			break;
		size = read(fd, buffer, BUFFER_SIZE);
	}
	return (output(&str, line, size));
}
