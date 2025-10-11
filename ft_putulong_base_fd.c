/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulong_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:49:19 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/11 09:12:21 by joesanto         ###   ########.fr       */
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

void	ft_putulong_base_fd(size_t nbr, const char *base, int fd)
{
	size_t	base_len;
	size_t	nbr_len;

	base_len = get_base(base);
	if (base_len < 2)
		return ;
	nbr_len = ft_ipow(base_len, ft_udigit_count(nbr, base_len) - 1);
	while (nbr_len)
	{
		ft_putchar_fd(base[nbr / nbr_len % base_len], fd);
		nbr_len /= base_len;
	}
}
