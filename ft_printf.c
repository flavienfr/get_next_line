/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:49:20 by froussel          #+#    #+#             */
/*   Updated: 2019/10/30 18:10:05 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** Check format string
** Check args == arg de string // Pas possible ?
** Read lanceur de fonction 
** Fonction affiche ui i d..
** Fonctions flags (str appart ?) 
**
** Gerer les erreur de compilation (boucle infini ou return)????
*/

int		ft_printf(const char *format, ...)
{
	t_arg	**lst;
	int		len;
	va_list	ap;

	if (!format)
		return (0);
	if (!(lst = malloc(sizeof(*lst))))
		return (0);
	*lst = NULL;
	len = 0;
	va_start(ap, format);
	parser(format, ap, lst);
	len = writer(format, *lst, len);
	va_end(ap);
	arg_lstclear(lst);
	return (len);
}

t_arg	*argnew(char type)
{
	t_arg	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->type = type;
	new->width = 0;
	new->digit = 0;
	new->precision = 0;
	new->prec = 0;
	new->sign = 0;
	new->len = 0;
	new->arg = NULL;
	new->next = NULL;
	return (new);
}

void	arg_lstclear(t_arg **lst)
{
	t_arg	*cur;
	t_arg	*next;

	if (!*lst || !lst)
		return ;
	cur = *lst;
	while (cur)
	{
		next = cur->next;
		arg_lstdelone(cur);
		cur = next;
	}
}

void	arg_lstdelone(t_arg *lst)
{
	if (!lst)
		return ;
	if (lst->type == 'd')
		free(lst->arg);
	free(lst);
	lst = NULL;
}

void	arg_lstadd_back(t_arg **alst, t_arg *new)
{
	t_arg	*surf;

	if (!new || !*alst || !alst)
	{
		if (!*alst)
			*alst = new;
		return ;
	}
	surf = *alst;
	while (surf->next)
		surf = surf->next;
	surf->next = new;
}
