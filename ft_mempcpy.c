/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:48:26 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/26 19:17:01 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_mempcpy(void *dest, const void *src, size_t n)
{
	char		*pdest;
	const char	*psrc;

	pdest = (char *) dest;
	psrc = (const char *) src;
	if (pdest && psrc)
		while (n--)
			*pdest++ = *psrc++;
	return ((void *) pdest);
}
