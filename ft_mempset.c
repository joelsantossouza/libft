/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:53:41 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/08 11:37:35 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_mempset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	set;

	ptr = (unsigned char *) s;
	set = (unsigned char) c;
	if (ptr)
		while (n--)
			*ptr++ = set;
	return ((void *) ptr);
}
