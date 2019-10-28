/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:53:17 by froussel          #+#    #+#             */
/*   Updated: 2019/10/28 16:25:00 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		buff[BUFFER_SIZE + 1];
	char		*new_str;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (free_all(&str));
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		if (!(new_str = ft_strjoin(str, buff)))
			return (free_all(&str));
		if (str)
			free(str);
		str = new_str;
		if (is_line(str))
			break ;
	}
	if (i < 0)
		return (free_all(&str));
	return (give_line(&str, line));
}

int		give_line(char **str, char **line)
{
	char	*s;
	size_t	i;
	size_t	len;

	i = 0;
	s = *str;
	if (!*str || !**str)
	{
		if (!(*line = ft_strdup("\0")))
			return (free_all(str));
	}
	else
	{
		len = ft_strclen(*str, '\n');
		while (len > i)
			i++;
		if (!(*line = ft_substr(*str, 0, i)))
			return (free_all(&s));
		if (!(*str = ft_substr(*str, i + 1, ft_strclen(*str, '\0'))))
			return (free_all(&s));
		return (ret(s, len));
	}
	free_all(str);
	return (0);
}

int		free_all(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (-1);
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
