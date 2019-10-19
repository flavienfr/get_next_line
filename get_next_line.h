/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:54:47 by froussel          #+#    #+#             */
/*   Updated: 2019/10/19 11:57:50 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"
# include "unistd.h"

int		get_next_line(int fd, char **line);
int		give_line(char **str, char **line);
int		is_line(char *str);
size_t	ft_strclen(const char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
