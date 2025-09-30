/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:29:44 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/30 12:49:54 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;

	if (size && nmemb > SIZE_MAX / size)
		return (0);
	bytes = nmemb * size;
	return (ft_memset(malloc(bytes), 0, bytes));
}
