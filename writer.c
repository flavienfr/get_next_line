/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:39:06 by froussel          #+#    #+#             */
/*   Updated: 2019/10/31 19:23:00 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		writer(const char *format, t_arg *narg, int len)
{
	int	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
			len += ft_putchar_fd_len(format[i++], 1);//
		else if (format[i] == '%')//%is a flag
		{
			i++;
			while (!(first_in_set(format[i], "cspdiuxX")))
				i++;
			len = write_arg(narg, len);
			narg = narg->next;
		}
		else
			len += ft_putchar_fd_len(format[i], 1);
	}
	return (len);
}

int		write_arg(t_arg *narg, int len)
{
	//printf("precision=%d=\n", narg->precision);
	//printf("sign=%d", narg->sign);
	//printf("width=%d=\n", narg->width);
	if (narg->type == 'c')
		len++;
	if (narg->digit)
	{
		len = write_digit(narg, len);
		return (len);
	}
	if (narg->width > 0 && narg->sign != -1)
		len = write_width(narg, len);
	if (narg->prec)
		len = write_precision(narg, len);
	else
		len += ft_putstr_fd_len(narg->arg, 1);
	if (narg->width > 0 && narg->sign == -1)
		len = write_width(narg, len);
	return (len);
}

int		write_digit(t_arg *narg, int len)
{
	narg->digit -= narg->len;
	if (narg->digit > 0)
		len += fill_in(narg->digit, '0');
	len += ft_putstr_fd_len(narg->arg, 1);
	return (len);
}

int		write_width(t_arg *narg, int len)
{
	if ((narg->prec && narg->precision < narg->len//
		&& (narg->type == 's')) || (narg->precision > narg->len
		&& (narg->type != 's')))
		narg->width -= narg->precision;
	else
		narg->width -= narg->len;//
	if (narg->width > 0)
		len += fill_in(narg->width, ' ');
	//printf("WIDTH=%d\n", len);
	return (len);
}

int		write_precision(t_arg *narg, int len)
{
	if (narg->type == 's')
		len += ft_putnstr_fd(narg->arg, 1, narg->precision);
	else if (narg->type == 'c' || narg->type == 'p')
		return (len += ft_putstr_fd_len(narg->arg, 1));
	else
	{
		if (narg->precision - narg->len > 0)
			len += fill_in(narg->precision - narg->len , '0');
		len += ft_putstr_fd_len(narg->arg, 1);
	}
	//printf("PRECISION=%d\n", len);
	return (len);
}
