/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:35:51 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/24 23:03:15 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	4096
#endif

static char	end_of_file(int fd, char buffer[BUFFER_SIZE], char **ptr,
							ssize_t *len)
{
	ssize_t	bytes_read;

	if (!**ptr)
	{
		*ptr = buffer;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			*len = -1;
			buffer[0] = 0;
		}
		else
			buffer[bytes_read] = 0;
	}
	return (**ptr == 0);
}

ssize_t	get_next_line(char **lineptr, int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*ptr = buffer;
	const char	*start;
	ssize_t		len;

	len = 0;
	*lineptr = ft_realloc(*lineptr, 0, 0);
	while (!end_of_file(fd, buffer, &ptr, &len))
	{
		start = ptr;
		ptr = ft_strchrnul(start, '\n');
		ptr += *ptr == '\n';
		*lineptr = ft_realloc(*lineptr, len, len + (ptr - start) + 1);
		ft_strlcpy(*lineptr + len, start, (ptr - start) + 1);
		len += ptr - start;
		if (*(ptr - 1) == '\n')
			break ;
	}
	return (len);
}
