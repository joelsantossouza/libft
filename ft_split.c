/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:21:58 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/08 01:25:29 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

ssize_t	ft_split(char ***split, char const *s, char c)
{
	char const	*start;
	char		**psplit;
	size_t		nwords;

	if (!s)
		return (-1);
	nwords = ft_word_count(s, c);
	ft_freearray((void **) *split, free);
	*split = (char **) malloc(sizeof(char *) * (nwords + 1));
	if (!*split)
		return (-1);
	psplit = *split;
	while (nwords--)
	{
		start = ft_strchrnul_diff(s, c);
		s = ft_strchrnul(start, c);
		*psplit = ft_strndup(start, s - start);
		if (!*psplit++)
		{
			ft_freearray((void **) *split, free);
			return (-1);
		}
	}
	*psplit = 0;
	return (psplit - *split);
}
