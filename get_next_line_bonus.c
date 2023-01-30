/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:23:17 by bcastelo          #+#    #+#             */
/*   Updated: 2023/01/29 23:28:27 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_chars(t_line *list);

t_line	*add_buffer(t_line *list);

t_line	*add_char(t_line *list, char c);

char	*join_line(t_line *list);

char	*get_next_line(int fd)
{
	t_line	*list;
	char	c;
	int		n;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	list = NULL;
	n = read(fd, &c, 1);
	while (n == 1)
	{
		list = add_char(list, c);
		if (list == NULL)
			return (NULL);
		if (c == '\n')
			return (join_line(list));
		n = read(fd, &c, 1);
	}
	if (n < 0)
	{
		free_chars(list);
		return (NULL);
	}
	return (join_line(list));
}
