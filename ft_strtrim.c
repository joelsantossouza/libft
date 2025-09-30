/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:03:22 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/30 19:19:54 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*end;

	if (!s1)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = s1 + ft_strlen(s1);
	while (end > s1 && ft_strchr(set, *end))
		end--;
	return (ft_strndup(s1, end - s1 + 1));
}
