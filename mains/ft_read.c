/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:05:02 by gboucett          #+#    #+#             */
/*   Updated: 2020/07/02 18:25:59 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	char *str = (char *)malloc(100 * sizeof(char));

	if (!str)
		return (1);
	int fd = open("bonjour", O_RDONLY);
	printf("fd = %d\n", fd);
	ssize_t value = ft_read(fd, str, 100);
	printf("%ld\n", value);
	if (value < 0)
		perror("error");
	write(1, str, value);
	free(str);
	if (fd > 2)
		close(fd);
	return (0);
}
