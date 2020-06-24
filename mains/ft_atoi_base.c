/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:19:43 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/24 14:19:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*str;
	char	*base;

	str = (ac > 2) ? av[1] : "2a";
	base = (ac > 2) ? av[2] : "0123456789abcdef";
	printf("number : %s\nbase : %s\nresult : %d\n", str, base,
		ft_atoi_base(str, base));
	return (0);
}
