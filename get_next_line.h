/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliver <oliver@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:28:17 by oliver            #+#    #+#             */
/*   Updated: 2021/04/03 22:41:50 by oliver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct		s_line
{
	char			*content;
	char			*excess;
	char			*temp;
	int				has_been_read;
	size_t			content_size;
}					t_line;

char				*ft_strnew(size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
void				*ft_bzero(void *b, size_t n);
char				*ft_strdup(const char *str);
int					check_for_line(char *buf);
char				*gnl_cat (char *s1, char *s2);
void				split(t_line *lines);
void				reading(int fd, char *buf, t_line *lines);
int					get_next_line(int fd, char **line);

#endif
