/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:05:02 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/15 19:16:50 by gboucett         ###   ########.fr       */
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

	int fd = open("bonjour", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	printf("fd = %d\n", fd);
	if (fd < 0)
	{
		perror("error : ");
		exit(1);
	}
	printf("-- ret value : %ld", ft_write(fd, str, strlen(str)));
	close(fd);
	return (0);
}
