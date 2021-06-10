#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("testes/file1", O_RDONLY);
	fd2 = open("testes/file2", O_RDONLY);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	close(fd1);
	close(fd2);
	return (0);
}
