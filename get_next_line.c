/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:53:17 by froussel          #+#    #+#             */
/*   Updated: 2019/11/01 17:58:34 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_all(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (-1);
}

static int	ret(char *s, size_t len)
{
	if (s[len] == '\n')
	{
		free(s);
		return (1);
	}
	free(s);
	return (0);
}

static int	is_line(char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

static int	give_line(char **str, char **line)
{
	char	*s;
	size_t	len;

	s = *str;
	if (!*str || !**str)
		*line = ft_strdup("\0");
	else
	{
		len = ft_strclen(*str, '\n');
		if (!(*line = ft_substr(*str, 0, len)))
			return (free_all(&s));
		if (!(*str = ft_substr(*str, len + 1, ft_strlen(*str))))
			return (free_all(&s));
		return (ret(s, len));
	}
	free_all(str);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*str;
	char		buff[BUFFER_SIZE + 1];
	char		*new_str;
	int			i;

	if (!line || fd < 0)
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
