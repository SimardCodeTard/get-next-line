/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:08:46 by smenard           #+#    #+#             */
/*   Updated: 2025/11/19 11:18:32 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# ifndef MAX_FD
#  define MAX_FD 64
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>

enum e_extract_next_line_result
{
	BUFFER_FINISHED,
	ERROR,
	LINE_COMPLETE
};

enum e_read_result
{
	READ_END = 0,
	READ_ERROR = -1,
};

typedef struct s_buffer
{
	char		*data;
	uint32_t	index;
}	t_buffer;

char	*get_next_line(int fd);

void	*ft_memmove(void *dest, void *src, size_t n);

size_t	next_line_len(char *buffer);

void	extract_next_line(int fd, char **line_buffer, t_buffer *buffer,
			size_t len);

ssize_t	read_exact(int fd, t_buffer *buffer, uint64_t size);

#endif
