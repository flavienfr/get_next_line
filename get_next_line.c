/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:53:17 by froussel          #+#    #+#             */
/*   Updated: 2019/10/17 17:36:39 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char *str[100];

	if (!line || fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(str[fd] = read_content(str[fd], fd)))
		return (-1);
	return (give_line(&str[fd], line));
}

int		give_line(char **str, char **line)
{
	int		i;
	char	*s;

	i = 0;
	s = *str;
	if (!**str)
		*line = ft_strdup("");
	else
	{
		while (ft_strclen(*str, '\n') > i)
			i++;
		*line = ft_substr(*str, 0, i);
		*str = ft_substr(*str, i + 1, ft_strclen(*str, '\n'));
		free(s);
		return (1);
	}
	free(s);
	return (0);
}

int		is_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_content(char *str, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*new_str;
	int		i;

	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		new_str = ft_strjoin(str, buff);
		if (str)
			free(str);
		str = new_str;
		if (is_line(str))
			break ;
	}
	return (str);
}
