/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 00:25:29 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/17 17:12:50 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10

void	ft_print_list(t_list *list)
{
	while (list)
	{
		printf("value = %d\n", *((int *)list->data));
		list = list->next;
	}
}

void	free_fct(void *data)
{
	free(data);
}

int		cmp(void *a, void *b)
{
	return (*((int *)a) - *((int *)b));
}

int		main()
{
	srand(time(0));
	t_list		*list = NULL;
	t_list		*tmp;
	int			*value;
	int			values[SIZE];
	int			z;

	for (int i = 0; i < SIZE; i++)
	{
		if ((value = (int *)malloc(sizeof(int))))
		{
			*value = rand() % 100;
			values[i] = *value;
			ft_list_push_front(&list, value);
		}
	}

	printf("size of list = %d\n", ft_list_size(list));

	printf("first list\n");
	ft_print_list(list);

	z = values[rand() % SIZE];
	printf("\nremoving all %d with ft_list_remove_if\n", z);
	ft_list_remove_if(&list, &z, cmp, free_fct);
	ft_print_list(list);

	ft_list_sort(&list, cmp);
	printf("\nafter sorting\n");
	ft_print_list(list);

	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp->data)
			free_fct(tmp->data);
		free(tmp);
	}
	return (0);
}
