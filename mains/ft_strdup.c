/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:32:46 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/15 22:31:08 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char *str = (ac > 1) ? av[1] : "Hello world !";
	char *strduped = ft_strdup(str);

	printf("strduped from \"%s\" : %s\n", str, strduped);
	free(strduped);
	return (0);
}
