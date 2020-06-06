/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:21:46 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/15 20:51:52 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char *src = (ac > 1) ? av[1] : "Hello";
	char dest[100];

	printf("src = %p\n", src);
	printf("dest = %p\n", dest);
	printf("result : %s\n", ft_strcpy(dest, src));
	printf("dest : %s\n", dest);
	return (0);
}
