/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:27:39 by joesanto          #+#    #+#             */
/*   Updated: 2025/11/03 09:52:41 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	65536
#endif

ssize_t	ft_getfile(char **fileptr, const char *path)
{
	const int	file = open(path, O_RDONLY);
	ssize_t		filelen;
	ssize_t		bytes_read;
	char		buffer[BUFFER_SIZE];

	if (file < 0)
		return (-1);
	filelen = 0;
	*fileptr = ft_realloc(*fileptr, 0, 0);
	bytes_read = read(file, buffer, BUFFER_SIZE);
	while (bytes_read != 0)
	{
		if (bytes_read < 0)
		{
			*fileptr = ft_realloc(*fileptr, 0, 0);
			return (close(file), -1);
		}
		*fileptr = ft_realloc(*fileptr, filelen, filelen + bytes_read + 1);
		if (!*fileptr)
			return (-1);
		*(char *) ft_mempcpy(*fileptr + filelen, buffer, bytes_read) = 0;
		filelen += bytes_read;
		bytes_read = read(file, buffer, BUFFER_SIZE);
	}
	return (close(file), filelen);
}
