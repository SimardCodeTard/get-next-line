/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:46:29 by smenard           #+#    #+#             */
/*   Updated: 2025/11/21 13:17:59 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;

	// Norminette flag me :3
	fd = open("read-error.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		close(fd);
		printf("line : %s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("\n===");
	close(fd);
	return (EXIT_SUCCESS);
}
