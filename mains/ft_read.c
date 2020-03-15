/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:05:02 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/15 19:31:21 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int		main(int ac, char **av)
{
	char *str = (char *)malloc(15 * sizeof(char));

	if (!str)
		return (1);
	int fd = open("bonjour", O_RDONLY);
	printf("fd = %d\n", fd);
	if (fd < 0)
	{
		perror("error : ");
		exit(1);
	}
	unsigned long value = ft_read(fd, str, 100);
	printf("%s-- ret value : %ld", str, value);
	close(fd);
	return (0);
}
