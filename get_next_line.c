/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:24:44 by marcus            #+#    #+#             */
/*   Updated: 2021/06/11 11:11:22 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (size < 0 || !line)
		return (-1);
	else if (BUFFER_SIZE <= 0)
		return (-1);
	else if (size == 0 && *str == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (add_line(str, line));
}

int	get_next_line(int fd, char **line)
{
	static char		*str;
	t_var			var;

	var.buffer = malloc(BUFFER_SIZE + 1);
	if (!var.buffer)
		return (-1);
	var.size = read(fd, var.buffer, BUFFER_SIZE);
	while (var.size > 0)
	{
		var.buffer[var.size] = '\0';
		if (str == NULL)
			str = ft_strdup(var.buffer);
		else
		{
			var.tmp = ft_strjoin(str, var.buffer);
			free(str);
			str = var.tmp;
		}
		if (ft_strchr(str, '\n'))
			break ;
		var.size = read(fd, var.buffer, BUFFER_SIZE);
	}
	free(var.buffer);
	return (output(&str, line, var.size));
}
