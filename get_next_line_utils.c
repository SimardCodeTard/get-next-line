/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:56:31 by smenard           #+#    #+#             */
/*   Updated: 2025/11/21 15:25:55 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Counts the length of the given string until the first occurence of the
 * stop character or a NULL byte
 */
size_t	ft_strlen(char *str, int8_t stop)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != stop)
		len++;
	if (str[len])
		len++;
	return (len);
}

/**
 * Extract the next line from the buffer and returns it
 */
t_line_extract_result	extract_line(char *buffer, char *line)
{
	bool	line_complete;
	size_t	i;

	line_complete = false;
	i = 0;
	while (buffer[i] && i < BUFFER_SIZE && !line_complete)
	{
		line[i] = buffer[i];
		if (buffer[i] == '\n')
			line_complete = true;
		i++;
	}
	line[i] = '\0';
	if (line_complete)
		return (COMPLETE);
	if (i == 0)
		return (NO_LINES);
	return (BUFFER_END);
}

/**
 * Reads up to size characets into buffer from fd
 */
ssize_t	read_file(int fd, char *buffer, size_t size)
{
	ssize_t	read_result;

	read_result = read(fd, buffer, size);
	if (read_result >= 0)
		buffer[read_result] = '\0';
	return (read_result);
}

/**
 * Allocates memory and returns a string containing s1 and s2 joined together
 * The input strings are freed
 */
char	*ft_strjoin_free(char *s1, char *s2)
{
	const size_t	s1_len = ft_strlen(s1, '\0');
	const size_t	s2_len = ft_strlen(s2, '\0');
	ssize_t			i;
	char			*s_joined;

	i = 0;
	s_joined = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s_joined)
		return (safe_free_return(s1, s2, NULL, NULL));
	while (s1 && s1[i])
	{
		s_joined[i] = s1[i];
		i++;
	}
	while (s2 && s2[i - s1_len])
	{
		s_joined[i] = s2[i - s1_len];
		i++;
	}
	s_joined[i] = '\0';
	free(s1);
	free(s2);
	return (s_joined);
}

/**
 * Frees all pointers in ptrs and returns value
 */
void	*safe_free_return(char *line, char *buffer, char **rest, void *value)
{
	free(line);
	free(buffer);
	if (rest)
	{
		free(*rest);
		*rest = NULL;
	}
	return (value);
}
