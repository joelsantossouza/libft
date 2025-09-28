/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:07:54 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/28 14:14:27 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*ptr;

	ptr = src;
	if (ptr)
	{
		if (dst && size)
		{
			while (size-- > 1 && *ptr)
				*dst++ = *ptr++;
			*dst = 0;
		}
		while (*ptr)
			ptr++;
	}
	return (ptr - src);
}
