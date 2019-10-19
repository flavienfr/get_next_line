/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:53:17 by froussel          #+#    #+#             */
/*   Updated: 2019/10/19 17:34:28 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*str[100];
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
		if (is_line(str[fd]))
			break ;
	}
	if (i < 0)
	{
		(str[fd]) ? free(str[fd]) : 1;
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
		len = ft_strclen(*str, '\n');
		while (len > i)
			i++;
		*line = ft_substr(*str, 0, i);
		*str = ft_substr(*str, i + 1, ft_strclen(*str, '\0'));
		free(s);
		return (1);
	}
	if (s)
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
