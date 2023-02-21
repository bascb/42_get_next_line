/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:11:39 by bcastelo          #+#    #+#             */
/*   Updated: 2023/02/19 09:52:13 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Calculates the length of the string str
*
* Returns the number of chars in thw string
*
*/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* Copy str to dest in a safe mode */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	i = 0;
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

/* concatenates src to dest in a safe mode */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len >= size)
		return (size + src_len);
	i = 0;
	while (i + dest_len + 1 < size && src[i])
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	if (i < size)
		dest[i + dest_len] = '\0';
	return (dest_len + src_len);
}

/* Returns a pointer to the first occurence 
   of char c in string str */
char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (c > 255)
		c = c % 256;
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *) &str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *) &str[i]);
	return (NULL);
}

/* Join s1 with s2 and returns a pointer to the new string */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	new_len;

	new_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(new_len * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, new_len);
	ft_strlcat(new, s2, new_len);
	return (new);
}
