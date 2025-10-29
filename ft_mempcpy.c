/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:48:26 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/29 09:52:40 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_mempcpy(void *dest, const void *src, size_t n)
{
	size_t			*pdest;
	const size_t	*psrc;

	if (!dest || !src)
		return (0);
	pdest = (size_t *) dest;
	psrc = (const size_t *) src;
	while (n >= 8)
	{
		*pdest++ = *psrc++;
		n -= 8;
	}
	while (n--)
		*(unsigned char *) pdest++ = *(unsigned char *) psrc++;
	return ((void *) pdest);
}
