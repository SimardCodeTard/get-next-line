/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:11:06 by smenard           #+#    #+#             */
/*   Updated: 2025/11/19 11:12:35 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buffer	*get_buffer(int fd)
{
	static t_buffer	buffers[MAX_FD];

	if (!buffers[fd].data)
		buffers[fd].data = malloc(BUFFER_SIZE * sizeof(char));
	return (&buffers[fd]);
}

char	*get_next_line(int fd)
{
	t_buffer	*buffer;
	char		*line;
	char		*previous_line;
	size_t		line_len;
	size_t		prev_line_len;

	buffer = get_buffer(fd);
	if (buffer->index && ! buffer->data)
		read_exact(fd, buffer, BUFFER_SIZE);
	line_len = next_line_len(buffer->data);
	line = malloc(line_len * sizeof(char));
	extract_next_line(fd, &line, buffer, line_len);
	return (line);
}
