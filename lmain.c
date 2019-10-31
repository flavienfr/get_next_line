
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:37:54 by froussel          #+#    #+#             */
/*   Updated: 2019/10/31 18:48:36 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define R "\x1b[31m"
#define G "\x1b[32m"
#define C "\x1b[36m"
#define S "\x1b[0m"
#define Y "\x1b[33m"
#define M "\x1b[34m"
#define B "\x1b[35m"

int main ()
{
	int i = -1, j = -1;
   	char ch = 'A';
   	char *str = "abcdef";
	void *ptr = str;
   	int no = 255;
   	int hex = 0X96;
   	unsigned int ui= 123456789;
	
	printf("MON nom est%-*si\n",10, "flavien");
	ft_printf("MON nom est%-*si\n",10, "flavien");


	
	return 0;
}
