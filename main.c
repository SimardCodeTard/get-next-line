/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:46:29 by smenard           #+#    #+#             */
/*   Updated: 2025/11/22 10:29:37 by smenard          ###   ########.fr       */
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
	fd = open("giant_line_nl.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("line : %s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("\n===\n");
	close(fd);
	return (EXIT_SUCCESS);
}
