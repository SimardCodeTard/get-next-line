/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:46:29 by smenard           #+#    #+#             */
/*   Updated: 2025/11/19 11:08:12 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("line : %s", line);
	close(fd);
	return (EXIT_SUCCESS);
}
