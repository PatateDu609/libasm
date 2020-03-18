/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:19:43 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/18 01:12:03 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*str = (ac > 2) ? av[1] : "";
	char	*base = (ac > 2) ? av[2] : "0123456789abcdef";

	printf("%d\n", ft_atoi_base(str, base));
	return (0);
}
