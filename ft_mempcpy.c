/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:48:26 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/08 11:27:31 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_mempcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	if (!dest || !src)
		return (0);
	pdest = (unsigned char *) dest;
	psrc = (const unsigned char *) src;
	while (n--)
		*pdest++ = *psrc++;
	return ((void *) pdest);
}
