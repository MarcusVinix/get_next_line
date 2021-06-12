#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	ssize_t			size;
	char			*buffer;
	char			*tmp;
}	t_var;

int		get_next_line(int fd, char **line);
char	*ft_line(char *s, size_t len);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);

#endif