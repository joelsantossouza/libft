/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:25:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/06 19:50:22 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <atf-c.h>

#define RED		"\e[0;31m"
#define GREEN	"\e[0;32m"
#define RESET	"\e[0m"

size_t nbrlen(ssize_t nbr, size_t base)
{
    size_t len;

    if (base == 0)
        return (0);
    if (nbr == 0)
        return (1);
    len = 0;
    if (nbr < 0)
        nbr = -nbr;
    while (nbr != 0)
    {
        nbr /= base;
        len++;
    }
    return (len);
}

void	test(ssize_t min, ssize_t max)
{
	size_t	output;
	size_t	expected;
	char	*color;
	int		base;

	while (min <= max)
	{
		base = -1;
		while (++base <= 16)
		{
			expected = nbrlen(min, base);
			output = ft_nbrlen(min, base);
			color = expected == output ? GREEN : RED;

			printf("%s", color);
			printf("Input:   \t%ld - %d\n", min, base);
			printf("Expected:\t%lu\n", expected);
			printf("Output:  \t%lu\n", output);
			printf("%s", RESET);

			ATF_CHECK_EQ(expected, output);
			printf("----------\n");
		}
		min++;
	}
}

ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", "Recreating the ctype library");
}
ATF_TC_BODY(test00, tc)
{
	test(-395808, 58074);
}
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);

	return (atf_no_error());
}
