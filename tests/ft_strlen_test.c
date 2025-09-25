/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:55:34 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/25 18:57:11 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <atf-c.h>
#include <stdio.h>

#define	NELEM(tab, data_type) (sizeof(tab) / sizeof(data_type))
#define RED		"\e[0;31m"
#define GREEN	"\e[0;32m"
#define RESET	"\e[0m"

void	test(char *strs[], int size, size_t expected)
{
	static int	i;
	size_t		output;
	char		*color;

	printf("---> test%02d (Expected=%lu)\n", i++, expected);
	while (size--)
	{
		output = ft_strlen(strs[size]);
		color = expected == output ? GREEN : RED;

		printf("%s", color);
		printf("Input:\t%s\t\t\t\tOutput: %lu\n", strs[size], output);
		printf("%s", RESET);

		ATF_CHECK_EQ(expected, output);
	}
	printf("\n\n");
}

// TEST 00
ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", "String of size 0");
}
ATF_TC_BODY(test00, tc)
{
	char	*test00[] = {"", 0, "\0"};
	size_t	expected = 0;

	test(test00, NELEM(test00, char *), expected);
}

// TEST 01

// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);

	return atf_no_error();
}
