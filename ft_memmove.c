/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:08:13 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/30 14:05:48 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*pdest;
	const char	*psrc;

	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	pdest = (char *) dest;
	psrc = (const char *) src;
	if (pdest && psrc)
		while (n--)
			pdest[n] = psrc[n];
	return (dest);
}
