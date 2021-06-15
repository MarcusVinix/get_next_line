# Get Next Line

> This is the function get_next_line, which will return a line from a file descriptor passed, this is my second project as a cadet at School 42 São Paulo.

## Description

> The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.  

> Calling the function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the EOF.

### How use the function 

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		gnl;
	char	*line;

	fd = open("file", O_RDONLY);
	gnl = get_next_line(fd, &line);
	while(gnl)
	{
		printf("%s\n", line);
		free(line);
		gnl = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	return (0);
}
```
> The function gnl make the allocation of memory for the variable line.  
> So its necessary call free after use the variable for avoid problems with leak.  
> This function has an undefined behavior if, between two calls, the same file descriptor switches to a different file before the EOF has been reached on the first fd.

> If you need read multiple files without reached the EOF, use the function bonus.
