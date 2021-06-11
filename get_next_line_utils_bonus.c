/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:11:11 by mavinici          #+#    #+#             */
/*   Updated: 2021/06/05 18:11:11 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t				len;

	len = 0;
	while ((unsigned char)s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	i;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < lens1)
	{
		newstr[i] = s1[i];
		i++;
	}
	i = 0;
	while (lens1 < (ft_strlen(s1) + ft_strlen(s2)))
	{
		newstr[lens1] = s2[i];
		i++;
		lens1++;
	}
	newstr[lens1] = '\0';
	return (newstr);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
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

char	*ft_line(char *s, size_t len)
{
	char			*line;
	size_t			i;

	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
