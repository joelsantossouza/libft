/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:15:03 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/28 17:16:52 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	const char	*ptr;

	if (!s)
		return (0);
	ptr = s;
	while (maxlen-- && *ptr)
		ptr++;
	return (ptr - s);
}
