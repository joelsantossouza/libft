/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:21:58 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/01 00:09:58 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_split(char const *s, const char *delim)
{
	char		**split;
	char		**psplit;
	size_t		nwords;

	if (!s)
		return (0);
	nwords = ft_words_count(s, delim);
	split = (char **) malloc(sizeof(char *) * (nwords + 1));
	if (!split)
		return (0);
	psplit = split;
	ft_strtok(s, 0);
	while (nwords--)
	{
		*psplit = ft_strtok(0, delim);
		if (!*psplit++)
			return (ft_freearray((void **) split));
	}
	*psplit = 0;
	return (split);
}
