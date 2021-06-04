#include "get_next_line.h"

int		main()
{
	char	**line;
	int		fd;

	fd = open("42TTESTERS-GNL/files/\"empty_lines\"", O_RDONLY);

	line = (char**)malloc(sizeof(char*));
	while (get_next_line(fd, line))
		printf("%s", *line);
	printf("%s", *line);
}