/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:21:58 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/30 20:40:19 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_words_count(char const *s, char c)
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
		while (*s && *s != c)
			s++;
	}
	return (nwords);
}

char	**ft_split(char const *s, char c)
{
	char const	*start;
	char		**split;
	char		**psplit;
	size_t		nwords;

	nwords = ft_words_count(s, c);
	if (!s || !nwords)
		return (0);
	split = (char **) malloc(sizeof(char *) * (nwords + 1));
	if (!split)
		return (0);
	psplit = split;
	while (nwords--)
	{
		while (*s == c)
			s++;
		start = s;
		s = ft_strchrnul(start, c);
		*psplit = ft_strndup(start, s - start);
		if (!*psplit)
			return (ft_freearray((void **) split));
	}
	*psplit = 0;
	return (split);
}
