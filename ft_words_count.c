/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:42:40 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/30 21:12:19 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_words_count(char const *s, char c)
{
	size_t	nwords;

	if (!s)
		return (0);
	nwords = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		nwords += *s != 0;
		s = ft_strchrnul(s, c);
	}
	return (nwords);
}
