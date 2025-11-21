/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:56:31 by smenard           #+#    #+#             */
/*   Updated: 2025/11/21 08:52:34 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Counts the length of the given string unitl the first occurence of the stop character
 */
size_t	ft_strlen(char *str, int8_t stop)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != stop)
		len++;
	return (len);
}

/**
 * Extract the next line from the buffer and returns it
 */
char	*extract_line(int fd, char *buffer, ssize_t rest_len)
{
	size_t	i;
	size_t	line_len;
	char	*full_line;
	char	*current_line;
	bool	line_complete;

	full_line = NULL;
	line_complete = false;
	while (rest_len > 0 && (read_exact(fd, buffer + rest_len, BUFFER_SIZE
		- rest_len) > 0 || rest_len > 0) && !line_complete)
	{
		i = 0;
		line_len = ft_strlen(buffer, '\n');
		current_line = malloc((line_len + 1) * sizeof(char));
		if (!current_line)
			return (NULL);
		while (i < line_len)
		{
			current_line[i] = buffer[i];
			if (buffer[i++] == '\n')
				line_complete = true;
		}
		current_line[i] = '\0';
		full_line = ft_strjoin(full_line, current_line);
		if (!full_line)
			return (safe_free_return((void **) &current_line, 1, NULL));
		rest_len -= line_len;
	}
	return (full_line);
}

/**
 * Reads up to size characets into buffer from fd
 */
size_t	read_exact(int fd, char *buffer, size_t size)
{
	ssize_t	read_result;
	size_t	total_bytes_read;

	read_result = 1;
	total_bytes_read = 0;
	while (read_result > 0 && total_bytes_read < size)
	{
		read_result = read(fd, buffer + total_bytes_read,
				size - total_bytes_read);
		if (read_result > 0)
			total_bytes_read += read_result;
	}
	if (read_result == -1)
		return (read_result);
	buffer[total_bytes_read] = '\0';
	return (total_bytes_read);
}

/**
 * Allocates memory and returns a string containing s1 and s2 joined together
 * The input strings are freed
 */
char	*ft_strjoin(char *s1, char *s2)
{
	const char	*ptrs[2] = {s1, s2};
	ssize_t		i;
	size_t		s1_len;
	size_t		s2_len;
	char		*s_joined;

	i = -1;
	s1_len = 0;
	s2_len = 0;
	while (s1 && s1[s1_len])
		s1_len++;
	while (s2 && s2[s2_len])
		s2_len++;
	s_joined = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s_joined)
		return (safe_free_return ((void **) ptrs, 2, NULL));
	while (s1 && s1[++i])
		s_joined[i] = s1[i];
	while (s2 && s2[++i])
		s_joined[i - s1_len] = s2[i];
	s_joined[s1_len + s2_len] = '\0';
	return (safe_free_return((void **) ptrs, 2, s_joined));
}

/**
 * Frees all pointers in ptrs and returns value
 */
void	*safe_free_return(void **ptrs, size_t ptrs_size, void *value)
{
	size_t	i;

	i = 0;
	while (i < ptrs_size)
	{
		if (ptrs[i])
			free(ptrs[i]);
		i++;
	}
	return (value);
}
