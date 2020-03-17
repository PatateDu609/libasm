/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 00:25:29 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/17 16:40:39 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
// {
// 	t_list	*tmp;

// 	if (!begin_list)
// 		return ;
// 	if (!*begin_list)
// 		return ;
// 	if (cmp((*begin_list)->data, data_ref) == 0)
// 	{
// 		tmp = *begin_list;
// 		*begin_list = (*begin_list)->next;
// 		free_fct(tmp->data);
// 		free(tmp);
// 		ft_list_remove_if(begin_list, data_ref, cmp, free_fct);
// 	}
// 	else
// 		ft_list_remove_if(&(*begin_list)->next, data_ref, cmp, free_fct);
// }

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
	int *value;

	for (int i = 0; i < 10; i++)
	{
		if ((value = (int *)malloc(sizeof(int))))
		{
			*value = rand() % 2;
			ft_list_push_front(&list, value);
		}
	}

	printf("size of list = %d\n", ft_list_size(list));

	printf("first list\n");
	ft_print_list(list);

	// ft_list_sort(&list, cmp);
	// printf("\nafter sorting\n");
	// ft_print_list(list);

	printf("\nremoving elements with ft_list_remove_if\n");
	int		z = 0;
	ft_list_remove_if(&list, &z, cmp, free_fct);
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
