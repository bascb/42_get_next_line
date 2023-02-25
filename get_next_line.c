/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:48:06 by bcastelo          #+#    #+#             */
/*   Updated: 2023/02/25 17:28:22 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *str, int c);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size);

char	*ft_strjoin(char const *s1, char const *s2);

/* Returns a pointer to a new string,
   duplicated from str */
char	*ft_strdup(const char *str)
{
	char	*new;
	int		i;

	new = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	*move_buffer(char *buffer, char *ptr)
{
	size_t	step;
	size_t	i;

	step = (ptr - buffer);
	i = step;
	while (i <= BUFFER_SIZE)
	{
		buffer[i - step] = buffer[i];
		buffer[i] = 0;
		i++;
	}
	i = BUFFER_SIZE + 1 - step;
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
	return (NULL);
}

char	*return_line(char *line, char *buffer, char *nlf_ptr)
{
	char	*new;
	size_t	needed;

	needed = nlf_ptr - buffer + 1;
	if (line)
		needed += ft_strlen(line);
	new = malloc((needed + 1) * sizeof(char));
	if (!new || needed < 1)
	{
		free(new);
		free(line);
		return (NULL);
	}
	new[0] = 0;
	if (line && ft_strlen(line) > 0)
		ft_strlcpy(new, line, needed + 1);
	ft_strlcat(new, buffer, needed + 1);
	move_buffer(buffer, nlf_ptr + 1);
	free(line);
	return (new);
}

char	*append_to_line(char *buffer, char *line)
{
	char	*aux;

	if (!line)
	{
		line = ft_strdup(buffer);
	}
	else
	{
		aux = line;
		line = ft_strjoin(aux, buffer);
		free(aux);
	}
	move_buffer(buffer, buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*c;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (move_buffer(buffer, buffer));
	line = NULL;
	c = ft_strchr(buffer, '\n');
	if (c != NULL)
		return (return_line(line, buffer, c));
	if (ft_strlen(buffer) > 0)
		line = append_to_line(buffer, line);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		c = ft_strchr(buffer, '\n');
		if (c != NULL)
			return (return_line(line, buffer, c));
		line = append_to_line(buffer, line);
	}
	if (line && ft_strlen(line) > 0)
		return (line);
	free(line);
	return (NULL);
}
