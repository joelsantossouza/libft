/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:21:58 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/01 13:12:44 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	char const	*start;
	char		**split;
	char		**psplit;
	size_t		nwords;

	if (!s)
		return (0);
	nwords = ft_words_count(s, c);
	split = (char **) malloc(sizeof(char *) * (nwords + 1));
	if (!split)
		return (0);
	psplit = split;
	while (nwords--)
	{
		start = ft_strchrnul_diff(s, c);
		s = ft_strchrnul(start, c);
		*psplit = ft_strndup(start, s - start);
		if (!*psplit++)
			return (ft_freearray((void **) split));
	}
	*psplit = 0;
	return (split);
}
