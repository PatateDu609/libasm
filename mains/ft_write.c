/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:05:02 by gboucett          #+#    #+#             */
/*   Updated: 2020/07/02 18:35:07 by gboucett         ###   ########.fr       */
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
	char *str = (ac > 1) ? av[1] : "Hello world !\n";

	// int fd = open("bonjour", O_CREAT | O_WRONLY | O_TRUNC, 0000);
	int fd = 55521;
	printf("fd = %d\n", fd);
	ssize_t result = ft_write(fd, str, strlen(str));
	printf("-- ret value : %ld\n", result);
	if (result < 0)
		perror("error");
	close(fd);
	return (0);
}
