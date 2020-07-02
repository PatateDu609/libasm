/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:53:53 by gboucett          #+#    #+#             */
/*   Updated: 2020/07/02 23:02:02 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>

int		main(int ac, char **av)
{
	char	*s1 = (ac > 1) ? av[1] : "a";
	char	*s2 = (ac > 2) ? av[2] : "bonjour";

	printf("strcmp \"%s\" \"%s\" : %d\n", s1, s2, strcmp(s2, s1));
	printf("ft_strcmp \"%s\" \"%s\" : %d\n", s1, s2, ft_strcmp(s2, s1));
	return (0);
}
