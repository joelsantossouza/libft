/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:50:43 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/10 20:54:58 by joesanto         ###   ########.fr       */
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

void	ft_putlong_base_fd(ssize_t nbr, const char *base, int fd)
{
	size_t	u_nbr;
	size_t	base_len;
	size_t	nbr_len;

	base_len = get_base(base);
	if (base_len < 2)
		return ;
	u_nbr = nbr;
	if (nbr < 0)
	{
		u_nbr = -nbr;
		ft_putchar_fd('-', fd);
	}
	nbr_len = ft_ipow(base_len, ft_digit_count(u_nbr, base_len) - 1);
	while (nbr_len)
	{
		ft_putchar_fd(base[u_nbr / nbr_len % base_len], fd);
		nbr_len /= base_len;
	}
}
