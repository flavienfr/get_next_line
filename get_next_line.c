/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:53:17 by froussel          #+#    #+#             */
/*   Updated: 2019/10/16 18:26:06 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int		get_next_line(int fd, char **line)
{
	static char *str[100];

	if (!line || fd == -1 || BUFFER_SIZE <= 0)//fd protect
		return (-1);
	if (!(str[fd] = read_content(str[fd], fd)))
		return (-1);
	return (give_line(&str[fd], line));
}

int		give_line(char **str, char **line)
{
	int		i;

	i = 0;
	if (!**str)
		*line = ft_strdup("");
	else
	{
		while ((*str)[i])
		{
			if ((*str)[i] == '\n')
			{
				*line = ft_substr(*str, 0, i);
				*str = &(*str)[i + 1];
				return (1);
			}
			i++;
		}
		*line = ft_substr(*str, 0, i);
		*str = &(*str)[i + 1];
		return (1);
	}
	//free(*str);
	return (0);
}

int		is_line(char *str)
{
	int i = 0;

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
		//printf("ici\n");
		if (str)
		{
			printf("|%s|\n", str);
			free(str);
		}
		str = new_str;
		if (is_line(str))
			break ;
	}
	return (str);
}



/*
size_t	ft_strchlen(const char *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static int	have_nl(char *s)
{
	while (*s != '\0')
		if (*s++ == '\n')
			return (1);
	return (0);
}

static int	pos_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char			*merge(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (s1)
	{
		printf("|%s|\n", s1);
		free(s1);
	}
	return (ret);
}

static char			*extract(char **cache, int idx)
{
	char	*ret;
	char	*s;

	s = *cache;
	if (idx >= 0)
	{
		ret = ft_substr(s, 0, idx);
		*cache = ft_substr(s, idx + 1, ft_strchlen(s, '\0'));
	}
	else if (idx == -1)
	{
		ret = ft_substr(s, 0, ft_strchlen(s, '\n'));
		*cache = 0;
	}
	free(s);
	return (ret);
}

int					get_next_line(int fd, char **line)
{
	ssize_t		r_size;
	char		buff[BUFFER_SIZE + 1];
	static char	*cache[100];

	if (fd < 0 || fd == 1)
		return (-1);
	while ((r_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r_size] = '\0';
		cache[fd] = merge(cache[fd], buff);
		if (have_nl(cache[fd]))
			break ;
	}
	if (r_size < 0)
		return (-1);
	if (!cache[fd])
		return (0);
	*line = extract(&cache[fd], pos_nl(cache[fd]));
	return (1);
}
*/
