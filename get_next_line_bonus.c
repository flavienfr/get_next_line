/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:25:30 by froussel          #+#    #+#             */
/*   Updated: 2019/10/26 12:08:23 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static char	*str[2048];
	char		buff[BUFFER_SIZE + 1];
	char		*new_str;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		new_str = ft_strjoin(str[fd], buff);
		if (str[fd])
			free(str[fd]);
		str[fd] = new_str;
		if (is_line(str[fd]))
			break ;
	}
	if (i < 0)
	{
		(str[fd]) ? free(str[fd]) : 1;
		str[fd] = NULL;
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
		*line = ft_strdup("\0");
	else
	{
		len = ft_strclen(*str, '\n');
		while (len > i)
			i++;
		*line = ft_substr(*str, 0, i);
		*str = ft_substr(*str, i + 1, ft_strclen(*str, '\0'));
		return (ret(s, len));
	}
	(*str) ? free(*str) : 1;
	if (*str)
		*str = NULL;
	return (0);
}

int		ret(char *s, size_t len)
{
	if (s[len] == '\n')
	{
		free(s);
		return (1);
	}
	free(s);
	return (0);
}

int		is_line(char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}
