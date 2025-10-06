/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:22:41 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/06 20:02:39 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

size_t	ft_nbrlen(ssize_t nbr, int base)
{
	size_t	len;

	if (base < 2)
		return (0);
	len = 1;
	while (nbr / base)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
