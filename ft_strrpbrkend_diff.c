/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrpbrkend_diff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:04:02 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/04 18:18:23 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrpbrkend_diff(const char *s, const char *reject)
{
	const char	*end;

	if (!s || !reject)
		return (0);
	end = s + ft_strlen(s);
	while (end > s)
		if (!ft_strchr(reject, *--end))
			break ;
	return ((char *) end);
}
