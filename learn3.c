/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:28:45 by froussel          #+#    #+#             */
/*   Updated: 2019/10/31 19:00:42 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	//printf("mon nom est |%000*0010*s|\n",-5,20,  "42");
	//printf("mon nom est |%000*0010d|\n",-5, 42);

	//printf("mon nom est |%000*0010s|\n",5, "42");
	//printf("mon nom est |%000*0010d|\n",5, 42);

//	printf("mon nom est |%000*0010.1s|\n",5, "42");
//	printf("mon nom est |%000*0010.3d|\n",5, 42);

	//printf("mon nom est |%-0-00*s|\n",-5, "42");
	//printf("mon nom est |%-0-000d|\n", 42);
	printf("%............................5d", 3);
}
