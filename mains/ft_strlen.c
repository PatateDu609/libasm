/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:33:47 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/15 20:16:50 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"

int		main(int ac, char **av)
{
	char *str = (ac > 1) ? av[1] : "Hello";

	printf("length of \"%s\" : %ld\n", str, ft_strlen(str));
	return (0);
}
