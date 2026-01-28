/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_ultoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:09:19 by joesanto          #+#    #+#             */
/*   Updated: 2026/01/28 21:51:15 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define	DECIMAL_BASE	10

size_t	ft_buffer_ultoa(size_t nbr, size_t size, char buffer[size])
{
	const size_t	nbr_len = ft_udigit_count(nbr, DECIMAL_BASE);
	size_t			total_nbr_len;

	if (size < 2)
		return (0);
	total_nbr_len = nbr_len + 1;
	if (size > total_nbr_len)
		size = total_nbr_len;
	else
	{
		while (total_nbr_len > size)
		{
			nbr *= 0.1;
			total_nbr_len--;
		}
	}
	buffer[--size] = 0;
	while (size-- > 0)
	{
		buffer[size] = nbr % 10 + '0';
		nbr *= 0.1;
	}
	return (nbr_len);
}
