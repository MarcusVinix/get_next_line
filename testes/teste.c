#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	char	*line;

	fd1 = open("testes/file1", O_RDONLY);
	int i = get_next_line(fd1, &line);
	while(i)
	{
		printf("%s\n", line);
		free(line);
		i = get_next_line(fd1, &line);
	}
	free(line);
	close(fd1);
	return (0);
}
