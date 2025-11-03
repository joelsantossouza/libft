/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:49:22 by joesanto          #+#    #+#             */
/*   Updated: 2025/11/03 18:18:05 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_swap(void *data1, void *data2, size_t size)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (!data1 || !data2)
		return ;
	ptr1 = (unsigned char *) data1;
	ptr2 = (unsigned char *) data2;
	while (size >= 8)
	{
		*(size_t *) ptr1 ^= *(size_t *) ptr2;
		*(size_t *) ptr2 ^= *(size_t *) ptr1;
		*(size_t *) ptr1 ^= *(size_t *) ptr2;
		ptr1 += 8;
		ptr2 += 8;
		size -= 8;
	}
	while (size--)
	{
		*ptr1 ^= *ptr2;
		*ptr2 ^= *ptr1;
		*ptr1++ ^= *ptr2++;
	}
}
