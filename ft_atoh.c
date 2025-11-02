/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:23:30 by joesanto          #+#    #+#             */
/*   Updated: 2025/11/02 00:19:22 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static
int	get_hex_value(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

long	ft_atoh(const char *nptr, char **endptr)
{
	char	sign;
	int		value;
	long	n;

	n = 0;
	sign = 1;
	if (nptr)
	{
		while (ft_isspace(*nptr))
			nptr++;
		if (*nptr == '+' || *nptr == '-')
			if (*nptr++ == '-')
				sign = -1;
		if (!ft_strncmp(nptr, "0x", 2) || !ft_strncmp(nptr, "0X", 2))
			nptr += 2;
		value = get_hex_value(*nptr);
		while (value >= 0)
		{
			n = n * 16 + value;
			value = get_hex_value(*++nptr);
		}
	}
	if (endptr)
		*endptr = (char *) nptr;
	return (n * sign);
}
