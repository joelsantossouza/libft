/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:23:30 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/29 14:36:25 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_base(const char *base)
{
	const char	*p;

	if (!base)
		return (0);
	p = base - 1;
	while (*++p)
		if (*p == '+' || *p == '-' || ft_isspace(*p) || ft_strchr(p + 1, *p))
			return (0);
	return (p - base);
}

int	ft_atoi_base(const char *nptr, const char *base)
{
	size_t	base_len;
	char	*found;
	char	sign;
	int		n;

	base_len = get_base(base);
	if (!nptr || base_len <= 1)
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = -1;
	n = 0;
	found = ft_memchr(base, *nptr, base_len);
	while (found)
	{
		n = n * base_len + (found - base);
		found = ft_memchr(base, *nptr, base_len);
	}
	return (n * sign);
}
