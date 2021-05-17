/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliver <oliver@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:28:30 by oliver            #+#    #+#             */
/*   Updated: 2021/05/14 17:33:16 by oliver           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*sub;

	count = 0;
	if (!(sub = ft_strnew(len + 1)))
		return (NULL);
	while (count < len)
	{
		sub[count] = s[start];
		count++;
		start++;
	}
	sub[count] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_bzero(void *b, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
	return (b);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s2;

	if (!(s2 = (char*)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	len = -1;
	while (s1[++len])
		s2[len] = s1[len];
	s2[len] = '\0';
	return (s2);
}
