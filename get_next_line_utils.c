/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:54:08 by froussel          #+#    #+#             */
/*   Updated: 2019/10/17 17:37:32 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t i;

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
		len = ft_strclen(str1, '\0');
	if (str2)
		len += ft_strclen(str2, '\0');
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

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ps;

	i = 0;
	while (s1[i])
		i++;
	if (!(ps = malloc(sizeof(*ps) * (i + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		ps[i] = s1[i];
	ps[i] = '\0';
	return (ps);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ps;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(ps = malloc(sizeof(*ps) * (len + 1))))
		return (0);
	if (ft_strclen(s, '\0') < start)
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
