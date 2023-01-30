/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:11:39 by bcastelo          #+#    #+#             */
/*   Updated: 2023/01/29 23:16:50 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_chars(t_line *list)
{
	t_line	*aux;

	while (list != NULL)
	{
		aux = list;
		list = aux->next;
		free(aux);
	}
}

t_line	*add_buffer(t_line *list)
{
	t_line	*new;

	new = malloc(sizeof(t_line));
	if (new == NULL)
	{
		if (list != NULL)
			free_chars(list);
		return (NULL);
	}
	if (list == NULL)
		list = new;
	else
		list->last->next = new;
	new->i = 0;
	new->line_size = 0;
	new->next = NULL;
	list->last = new;
	return (new);
}

t_line	*add_char(t_line *list, char c)
{
	if (list == NULL)
		list = add_buffer(list);
	if (list == NULL)
		return (NULL);
	if (list->last->i == BUFFER_SIZE && !add_buffer(list))
		return (NULL);
	list->last->buffer[list->last->i] = c;
	list->last->buffer[++list->last->i] = 0;
	list->line_size++;
	return (list);
}

char	*join_line(t_line *list)
{
	char	*line;
	t_line	*aux;
	int		i;
	int		j;

	if (list == NULL)
		return (NULL);
	line = malloc((list->line_size + 1) * sizeof(char));
	if (line == NULL)
	{
		free_chars(list);
		return (NULL);
	}
	i = 0;
	while (list != NULL)
	{
		j = 0;
		while (list->buffer[j] != 0)
			line[i++] = list->buffer[j++];
		aux = list;
		list = list->next;
		free(aux);
	}
	line[i] = 0;
	return (line);
}
