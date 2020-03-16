/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 00:25:29 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/16 23:25:11 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int		cmp(void *a, void *b)
{
	return (*((int *)a) - *((int *)b));
}

int		main()
{
	srand(time(0));
	t_list		*list = NULL;
	t_list		*tmp;
	int *value;

	for (int i = 0; i < 1000; i++)
	{
		if ((value = (int *)malloc(sizeof(int))))
		{
			*value = rand() % 1000;
			ft_list_push_front(&list, value);
		}
	}

	printf("size of list = %d\n", ft_list_size(list));

	printf("before sorting\n");
	tmp = list;
	while (tmp)
	{
		printf("value = %d\n", *((int *)tmp->data));
		tmp = tmp->next;
	}
	ft_list_sort(&list, cmp);

	printf("\nafter sorting\n");
	while (list)
	{
		tmp = list;
		printf("value = %d\n", *((int *)tmp->data));
		list = list->next;
		if (tmp->data)
			free(tmp->data);
		free(tmp);
	}
	return (0);
}
