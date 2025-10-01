/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrknul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:44:58 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/01 12:27:23 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrknul(const char *s, const char *accept)
{
	if (s)
		while (*s)
			if (ft_strchr(accept, *s++))
				return ((char *)(s - 1));
	return ((char *) s);
}
