/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:22:41 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/06 18:16:01 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

size_t	ft_nbrlen(ssize_t nbr)
{
	size_t	len;

	len = 1;
	while (nbr / 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
