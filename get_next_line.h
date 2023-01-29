/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:48:40 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/27 16:51:54 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct c_list
{
	char			buffer[BUFFER_SIZE + 1];
	int				i;
	int				line_size;
	struct c_list	*next;
	struct c_list	*last;
}					t_line;

char	*get_next_line(int fd);

#endif
