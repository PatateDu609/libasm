/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 00:25:29 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/16 00:42:03 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include <stdlib.h>
#include <stdio.h>

// void	*ft_create_elem(void *data)
// {
// 	t_list		*list;

// 	if (!(list = malloc(sizeof(t_list))))
// 		return (NULL);
// 	if (list)
// }

int		main()
{
	t_list		*list = NULL;
	t_list		*tmp;
	int			a = 1;
	int			b = 2;
	int			c = 3;
	int			d = 4;
	int			e = 5;
	int			f = 6;

	ft_list_push_front(&list, &f);
	ft_list_push_front(&list, &e);
	ft_list_push_front(&list, &d);
	ft_list_push_front(&list, &c);
	ft_list_push_front(&list, &b);
	ft_list_push_front(&list, &a);

	printf("size of list = %d\n", ft_list_size(list));

	while (list)
	{
		tmp = list;
		printf("value = %d\n", *((int *)tmp->data));
		list = list->next;
		free(tmp);
	}
	return (0);
}
