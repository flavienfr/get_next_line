/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:23:40 by froussel          #+#    #+#             */
/*   Updated: 2019/10/30 13:15:02 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fill_in(int field, char c)
{
	int i;

	i = -1;
	while (++i < field)
		ft_putchar_fd(c, 1);
	return (i);
}

int		ft_putnstr_fd(char *s, int fd, int n)
{
	int	i;

	if (!s || fd <= 0)
		return (0);
	i = -1;
	while (s[++i] && n--)
		ft_putchar_fd(s[i], fd);
	return (i);
}

int		ft_putchar_fd_len(char c, int fd)
{
	if (fd <= 0)
		return (0);
	write(fd, &c, 1);
	return (1);
}

int		ft_putstr_fd_len(char *s, int fd)
{
	int	i;

	if (!s || fd <= 0)
		return (0);
	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], fd);
	return (i);
}
