/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:53:41 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/29 11:58:01 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_mempset(void *s, int c, size_t n)
{
	char	*ptr;
	char	set;

	ptr = (char *) s;
	set = (char) c;
	if (ptr)
		while (n--)
			*ptr++ = set;
	return ((void *) ptr);
}
