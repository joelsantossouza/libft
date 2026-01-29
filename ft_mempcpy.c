/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:48:26 by joesanto          #+#    #+#             */
/*   Updated: 2026/01/29 13:02:25 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	*ft_mempcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;
	const size_t		ptr_mask = sizeof(uintptr_t) - 1;

	if (!dest || !src)
		return (0);
	pdest = (unsigned char *) dest;
	psrc = (const unsigned char *) src;
	while (n > 0 && (((uintptr_t)pdest | (uintptr_t)psrc) & ptr_mask))
	{
		*pdest++ = *psrc++;
		n--;
	}
	while (n >= 8)
	{
		*(size_t *) pdest = *(size_t *) psrc;
		pdest += 8;
		psrc += 8;
		n -= 8;
	}
	while (n-- > 0)
		*pdest++ = *psrc++;
	return ((void *) pdest);
}
