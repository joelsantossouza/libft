/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:21:58 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/30 19:32:46 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}
