/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:29:05 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/29 09:36:09 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	char		find;

	ptr = s + ft_strlen(s);
	find = (char) c;
	if (ptr)
		while (ptr >= s)
			if (*ptr-- == find)
				return ((char *)(ptr + 1));
	return (0);
}
