/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:46:16 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/29 09:51:22 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *) s1;
	p2 = (const unsigned char *) s2;
	if (!n || (!s1 && !s2))
		return (0);
	if (!p1)
		return (-1);
	if (!p2)
		return (1);
	while (*p1 == *p2 && *p1 && n-- > 1)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}
