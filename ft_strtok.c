/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:29:31 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/01 00:41:38 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(const char *str, const char *delim)
{
	static const char	*ptr;

	if (!delim)
	{
		ptr = str;
		return (0);
	}
	if (str)
		str = ft_strpbrk_diff(str, delim);
	else
		str = ft_strpbrk_diff(ptr, delim);
	ptr = ft_strpbrk(str, delim);
	return (ft_strndup(str, ptr - str));
}
