/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:35:29 by froussel          #+#    #+#             */
/*   Updated: 2019/10/25 13:44:49 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/*
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	print(const char *str, ...)
{
	va_list	p;
	t_list	lst;

	va_start(p, str);
	lst = ft_lstnew(va_arg(p, void *));
	while (lst)
	{
		lst->next = ft_lstnew(va_arg(p, int));
		lst = lst->next;
	}
	va_end(p);
	return 0;
}
*/

void	ttest(va_list ap)
{
	char cp;
	cp = va_arg(ap, unsigned int);
	printf("%c\n", (char)va_arg(ap, int));
	va_end(ap);
	printf("%c\n", cp);
}

void	print(char *str, ...)
{
	va_list ap;
	int i;

	i = -1;
	va_start(ap, str);
	ttest(ap);
	/*
	while (str[++i])
	{
		//printf("%d", va_arg(ap, int));
		ttest(ap);
	}
	*/
}

char	*dec_to_hex(int dec, char c)
{
	char	shex[10];
	char	*dhex;
	int		i;
	int		j;

	i = 0;
	while (dec)
	{
		if ((dec % 16) < 10)
			shex[i++] = (dec % 16) + '0';
		else
			shex[i++] = (dec % 16) - 10 + c;
		dec = dec / 16;
	}
	if (!(dhex = malloc(sizeof(*dhex) * (i + 1))))
		return (NULL);
	dhex[i] = '\0';
	j = 0;
	while (--i >= 0)
		dhex[j++] = shex[i];
	return (dhex);
}

int		main(void)
{
	char o = 'u';
	char *l = "p";
	char hex[17];

	int i = 8;
	int j = 9;
	//print("123", o, l);
	//printf("%p\n", (void*)l);
	hex = (char *)&l;
	printf("%p\n", l);
	printf("%d\n", la);
	printf("%s\n", dec_to_hex(la, 'a'));

}
