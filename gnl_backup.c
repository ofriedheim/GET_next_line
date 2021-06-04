/*		proposed algorithm for reading file
	>open file
	>read BUFF_SIZE to temporary string
	>check for new line
		>if new line, split the string
			>string 1 is full line
			>string 2 is excess; will be used later
		>if no new line, read BUFF_SIZE again until new line is found
	>Return string 1 (full line)

	return values:
	>1: A line has been read
	>0: EOF has been reached
	>-1: Error
*/
#include "get_next_line.h"

#define TRUE 1
#define FALSE 0

int		check_for_line(char *buf)
{
	int		i;

	i = -1;
	//printf("inside check for line but before loop\n\n");
	while (buf[++i])
	{
		if (buf[i] == '\n')
			return (TRUE);
	}
	//printf("inside CFL after loop \n\n");
	return (FALSE);
}

char	*gnl_cat(char *s1, char *s2)
{
	char	*cat;
	int		i;
	int		j;

	//printf("s1_size == %d\nstrlen(s2) == %ld\n\n", s1_size, ft_strlen(s2));
	//printf("cat function has been entered\n\n");
	//printf("s2 = %s \n\n", s2);
	//printf("s1 = %s\n\n", s1);
	cat = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	//printf("cat string has been allocated\n\n");
	i = 0;
	j = 0;
	//printf("post initial return inside gnl_cat\n\n");
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		cat[i] = s2[j];
		i++;
		j++;
	}
	cat[i] = '\0';
	//printf("post cat stuff\n\n");
	//printf("cat = %s\n\n", cat);
	free(s1);
	return (cat);
}

void	split(t_line *lines)
{
	int		i;
	char	*ptr;

	i = -1;
	ptr = lines->temp;
	while (ptr[++i])
		if (ptr[i] == '\n')
			break ;
	lines->content = ft_substr(lines->temp, 0, i);
	lines->excess = ft_substr(lines->temp, i + 1, ft_strlen(lines->temp));
}

void	reading(int fd, char* buf, t_line *lines)
{
	int		read_ret;

	read_ret = 0;
	lines->has_been_read = TRUE;
	while ((read_ret = (read(fd, buf, BUFFER_SIZE))))
	{
		buf[read_ret] = '\0';
		if (lines->temp[0])
			lines->temp = gnl_cat(lines->temp, buf);
		else
			lines->temp = ft_strdup(buf);
		if (check_for_line(lines->temp) == TRUE)
			break ;
	}
	if (read_ret == 0)
		lines->content = ft_strdup(lines->excess);
}

int		get_next_line(int fd, char **line)
{
	static t_line	*lines[1000];
	char			buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (-1);
	if (!lines[fd])
	{
		lines[fd] = (t_line*)malloc(sizeof(t_line));
		lines[fd]->content = (char*)malloc(sizeof(char*));
		lines[fd]->content[0] = '\0';
		lines[fd]->excess = (char*)malloc(sizeof(char*));
		lines[fd]->excess[0] = '\0';
		lines[fd]->temp = (char*)malloc(sizeof(char*));
		lines[fd]->temp[0] = '\0';
		lines[fd]->has_been_read = FALSE;
	}
	if (lines[fd]->has_been_read == TRUE)
	{
		ft_bzero(lines[fd]->temp, ft_strlen(lines[fd]->temp));
		lines[fd]->temp = ft_strdup(lines[fd]->excess);
		ft_bzero(lines[fd]->excess, ft_strlen(lines[fd]->excess));
		reading(fd, buf, lines[fd]);
	}
	else
		reading(fd, buf, lines[fd]);
	split(lines[fd]);
	*line = lines[fd]->content;
	if (lines[fd]->excess[0] == '\0')
		return (0);
	return (1);
}

int		main()
{
	int		fd;
	int		fd2;
	char	**line;

	line = (char**)malloc(sizeof(char*));
	fd = open("navy_seals.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	get_next_line(fd, line);
	printf("%s\n", *line);
	get_next_line(fd2, line);
	printf("%s\n", *line);
	get_next_line(fd, line);
	printf("%s\n", *line);
	close(fd);
}