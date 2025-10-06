/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:25:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/06 18:07:21 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <atf-c.h>

#define RED		"\e[0;31m"
#define GREEN	"\e[0;32m"
#define RESET	"\e[0m"

size_t nbrlen(size_t nbr)
{
    size_t len;

    if (nbr == 0)
        return (1);
    len = 0;
    while (nbr > 0)
    {
        nbr /= 10;
        len++;
    }
    return (len);
}

void	test(ssize_t min, ssize_t max)
{
	size_t	output;
	size_t	expected;
	char	*color;

	while (min <= max)
	{
		expected = nbrlen(min);
		output = ft_nbrlen(min);
		color = expected == output ? GREEN : RED;

		printf("%s", color);
		printf("Input:   \t%ld\n", min);
		printf("Expected:\t%lu\n", expected);
		printf("Output:  \t%lu\n", output);
		printf("%s", RESET);

		ATF_CHECK_EQ(expected, output);
		printf("----------\n");
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
	test(-9223372036854775808LU, 9223372036854775807);
}
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);

	return (atf_no_error());
}
