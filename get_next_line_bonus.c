/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:53:17 by froussel          #+#    #+#             */
/*   Updated: 2019/10/20 15:40:30 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static char	*str[1000];
	char		buff[BUFFER_SIZE + 1];
	char		*new_str;
	int			i;

	if (!line || fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (-1);
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		new_str = ft_strjoin(str[fd], buff);
		if (str[fd])
			free(str[fd]);
		str[fd] = new_str;
		if (isline_strclen(str[fd], '\0', 1))
			break ;
	}
	if (i < 0)
	{
		(str[fd]) ? free(str[fd]) : 1;
		*line = NULL;
		return (-1);
	}
	return (give_line(&str[fd], line));
}

int		give_line(char **str, char **line)
{
	char	*s;
	size_t	i;
	size_t	len;

	i = 0;
	s = *str;
	if (!*str || !**str)
		*line = NULL;
	else
	{
		len = isline_strclen(*str, '\n', 2);
		while (len > i)
			i++;
		*line = ft_substr(*str, 0, i);
		*str = ft_substr(*str, i + 1, isline_strclen(*str, '\0', 2));
		free(s);
		return (1);
	}
	if (s)
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

size_t	isline_strclen(const char *s, char c, int who)
{
	size_t i;

	if (who == 1)
	{
		while (*s)
			if (*s++ == '\n')
				return (1);
		return (0);
	}
	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*res;
	char	*beg;
	int		len;

	if (!str1 && !str2)
		return (0);
	len = 0;
	if (str1)
		len = isline_strclen(str1, '\0', 2);
	if (str2)
		len += isline_strclen(str2, '\0', 2);
	if (!(res = malloc(sizeof(*res) * (len + 1))))
		return (0);
	beg = res;
	if (str1)
		while (*str1)
			*res++ = *str1++;
	if (str2)
		while (*str2)
			*res++ = *str2++;
	*res = '\0';
	return (beg);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ps;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(ps = malloc(sizeof(*ps) * (len + 1))))
		return (0);
	if (isline_strclen(s, '\0', 2) < start)
		*ps = '\0';
	else
	{
		i = 0;
		while (s[start + i] && len-- > 0)
		{
			ps[i] = s[start + i];
			i++;
		}
		ps[i] = '\0';
	}
	return (ps);
}
