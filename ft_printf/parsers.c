/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:29:12 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/21 10:07:38 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	parse_flags(const char *str, t_spec *spec, const char **endptr)
{
	*endptr = str;
	while (1)
	{
		if (**endptr == '-')
			spec->flags |= F_MINUS;
		else if (**endptr == '+')
			spec->flags |= F_PLUS;
		else if (**endptr == ' ')
			spec->flags |= F_SPACE;
		else if (**endptr == '#')
			spec->flags |= F_HASH;
		else if (**endptr == '0')
			spec->flags |= F_ZERO;
		else
			break ;
		(*endptr)++;
	}
}

void	parse_width(const char *str, va_list args, t_spec *spec,
			const char **endptr)
{
	*endptr = str;
	if (**endptr == '*')
	{
		spec->width = va_arg(args, int);
		(*endptr)++;
	}
	else
		spec->width = ft_atol_base(*endptr, (char **) endptr, DEC);
}

void	parse_precision(const char *str, va_list args, t_spec *spec,
			const char **endptr)
{
	*endptr = str;
	if (**endptr == '.')
	{
		spec->flags |= PRECISION;
		if (*++(*endptr) == '*')
		{
			spec->precision = va_arg(args, int);
			(*endptr)++;
		}
		else
			spec->precision = ft_atol_base(*endptr, (char **) endptr, DEC);
	}
}

void	parse_length(const char *str, t_spec *spec, const char **endptr)
{
	*endptr = str;
	if (!ft_strncmp(*endptr, "hh", 2) || !ft_strncmp(*endptr, "ll", 2))
	{
		ft_strlcpy(spec->length, *endptr, sizeof(spec->length));
		*endptr += 2;
	}
	else if (**endptr && ft_strchr("hl", **endptr))
	{
		ft_strlcpy(spec->length, *endptr, 2);
		(*endptr)++;
	}
}

int	parse_spec(const char *str, va_list args, t_spec *spec, const char **endptr)
{
	*endptr = str + (*str != 0);
	if (*str == 'd' || *str == 'i')
		return (int_config(args, spec));
	else if (*str == 'u')
		return (uint_config(args, spec, "", DEC));
	else if (*str == 'o')
		return (uint_config(args, spec, "0", OCT));
	else if (*str == 'x')
		return (uint_config(args, spec, "0x", LHEX));
	else if (*str == 'X')
		return (uint_config(args, spec, "0X", UHEX));
	else if (*str == 's')
		return (str_config(args, spec));
	else if (*str == 'c')
		return (chr_config(args, spec));
	else if (*str == 'p')
		return (ptr_config(args, spec));
	else if (*str == '%')
		return (perc_config(spec));
	return (0);
}
