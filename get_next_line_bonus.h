/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:29:37 by smenard           #+#    #+#             */
/*   Updated: 2025/11/22 10:33:26 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>

typedef enum e_extract_line_result
{
	INCOMPLETE,
	COMPLETE,
	BUFFER_END,
	NO_LINES
}						t_line_extract_result;

/* ===== get_next_line_bonus.c ===== */

char					*get_next_line(int fd);

char					**get_rest(int fd);

void					extract_rest(char **rest, char *buffer,
							size_t last_line_len);

char					*ft_strcpy(char *src, char *dest);

/* ===== get_next_line_utils_bonus.c ===== */

size_t					ft_strlen(char *str, int8_t stop);

t_line_extract_result	extract_line(char *buffer, char *line);

ssize_t					read_file(int fd, char *buffer, size_t size);

char					*ft_strjoin_free(char *s1, char *s2);

void					*safe_free_return(char *line, char *buffer,
							char **rest, void *value);

#endif
