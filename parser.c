/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:26:27 by froussel          #+#    #+#             */
/*   Updated: 2019/10/31 19:21:08 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	parse_flag(char *str, t_arg *narg, va_list ap);
void	parser(const char *format, va_list ap, t_arg **lst)
{
	int 	i;
	int 	start;
	t_arg	*narg;
	char	*str;
	
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
		else if (format[i] == '%')
		{
			start = ++i;
			while (!(first_in_set(format[i], "cspdiuxX")))//flag %
				i++;
			str = ft_substr(format, start, i);
			narg = argnew(format[i]);
			printf("---------|%s|et|i=%d|et|str=%d|\n", str, i, start);
			//parse_width_sign(str, narg, ap);
			//parse_digit(str, narg, ap);
			parse_flag(str, narg, ap);
			parse_precision(str, narg, ap);
			
			parse_arg(narg, ap);
			arg_lstadd_back(lst, narg);
			free(str);
		}
	}
}
//RIP
void	parse_flag(char *str, t_arg *narg, va_list ap)
{
	int i;
	int var;
	int start;

	i = 0;
	printf("LLLLLA%s\n", str);
	while(str[i] && str[i] != '.')
	{
		if (str[i] == '*')
			var = va_arg(ap, int);
		if (str[i] == '-' || var < 0)
			narg->sign = -1;
		if (ft_isdigit(str[i]))//sauf si commence par 0 en i=0
		{
			start = i;
			while (ft_isdigit(str[i]))
				i++;
			var = ft_atoi(ft_substr(str, start, i));
			i--;
		}
		i++;
		//printf("iic\n");
	}
	printf("var=%d\n",var);
	if (str[0] == '0' && narg->sign != -1)
		narg->digit = var;
	else
	{
		if (var > 0)
			var *= -1;
		narg->width = var;
	}
}
//RIP
/*
void	parse_width_sign(char *str, t_arg *narg, va_list ap)
{
	int	i;
	int start;

	i = 0;
	if (str[i] == '0')
		return ;
	while (str[i] == '-')
	{
		narg->sign = -1;
		i++;
	}
	if (str[i] == '*')
	{
		narg->width = va_arg(ap, int);
		if (narg->width < 0)
			narg->sign = -1;
	}
	else if (ft_isdigit(str[i]))
	{
		start = i;
		while (ft_isdigit(str[i]))
			i++;
		narg->width = ft_atoi(ft_substr(str, start, i));
	}
}

void	parse_digit(char *str, t_arg *narg, va_list ap)
{
	int i;

	i = 0;
	if (!(str[i++] == '0'))
		return ;
	if (str[i] == '*')
		narg->digit = va_arg(ap, int);
	else
	{
		while (ft_isdigit(str[i]))
			i++;
		narg->digit = ft_atoi(ft_substr(str, 1, i));
	}
}
*/
void	parse_precision(char *str, t_arg *narg, va_list ap)
{
	int i;
	int start;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')//boucle tant aue .
		{
			narg->prec = 1;
			if (str[++i] == '*')
				narg->precision = va_arg(ap, int);
			else
			{
				start = i;
				while (ft_isdigit(str[i]))
					i++;
				narg->precision = ft_atoi(ft_substr(str, start, i));
			}
			return ;
		}
		//printf("la\n");
		i++;
	}
}

char	*address_ptr(void *ptr)
{
	char *p;
	long int add;

	add = (long int)&*ptr;
	p = ft_strjoin("0x",dec_to_hex(add, 'a'));
	return (p);
}

void	parse_arg(t_arg *narg, va_list ap)
{
	if (narg->type == 'c')
		narg->arg = chr_to_str((char)va_arg(ap, int));
	else if (narg->type == 's')
		narg->arg = ft_strdup(va_arg(ap, char *));
	else if (narg->type == 'p')
		narg->arg = address_ptr(va_arg(ap, void *));
	else if (narg->type == 'd' || narg->type == 'i')
		narg->arg = ft_itoa(va_arg(ap, int));
	else if (narg->type == 'u')
		narg->arg = ft_itoa_long(va_arg(ap, unsigned int));
	else if (narg->type == 'x')
		narg->arg = dec_to_hex(va_arg(ap, unsigned int), 'a');
	else if (narg->type == 'X')
		narg->arg = dec_to_hex(va_arg(ap, unsigned int), 'A');
	if (narg->arg == NULL)
		narg->arg = ft_strdup("(null)");
	if (narg->type == 'c')
		narg->len = 1;
	else
		narg->len = ft_strlen(narg->arg);
//	if (narg->precision < 0)
//		narg->precision *= -1; 
}
