/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:29:31 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/01 12:55:51 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char **token_orig, const char *str, const char *delim)
{
	static const char	*ptr;

	if (str)
		str = ft_strpbrk_diff(str, delim);
	else
		str = ft_strpbrk_diff(ptr, delim);
	ptr = ft_strpbrknul(str, delim);
	if (token_orig)
		*token_orig = (char *) str;
	return (ft_strndup(str, ptr - str));
}
