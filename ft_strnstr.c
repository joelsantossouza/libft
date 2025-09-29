/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:25:38 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/29 21:46:41 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (big && little)
	{
		little_len = ft_strlen(little);
		while (len-- && *big)
			if (ft_strncmp(big++, little, little_len) == 0)
				return ((char *)(big - 1));
	}
	return (0);
}
