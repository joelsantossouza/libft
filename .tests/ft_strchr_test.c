/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 07:54:21 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/29 08:37:10 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <atf-c.h>
#include <atf-c/macros.h>
#include <atf-c/tc.h>
#include <string.h>
#include <stdio.h>

#define NELEM(tab) (sizeof(tab) / sizeof(char *))
#define TEST_NULLS	1<<0
#define RED			"\e[0;31m"
#define GREEN		"\e[0;32m"
#define RESET		"\e[0m"

char	*tests_titles[] = {
	"Null Strings",
	"Empty Strings",
	"Big Strings",
};
static int	i;

typedef struct s_range
{
	int	min;
	int	max;
}	t_range;
t_range _range = {-255, 255};

void	test(char	*tab[], size_t size, t_range range, int flags)
{
	char	*expected;
	char	*output;
	char	*color;
	int		find;

	printf("\n<test%02d> %s\n", i, tests_titles[i]);
	while (size--)
	{
		find = range.min - 1;
		while (++find <= range.max)
		{
			expected = flags & TEST_NULLS ? 0 : strchr(tab[size], find);
			output = ft_strchr(tab[size], find);
			color = expected == output ? GREEN : RED;

			printf("%s", color);
			printf("Input:   \t(%p) %s\n", tab[size], tab[size]);
			printf("Expected:\t(%p) %s\n", expected, expected);
			printf("Output:  \t(%p) %s\n", output, output);
			printf("%s", RESET);

			ATF_CHECK_EQ(expected, output);
			printf("----------\n");
		}
	}
}

// TEST 00 --> NULL STRINGS
ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[0]);
}
ATF_TC_BODY(test00, tc)
{
	char	*tab[] = {
		0,
	};

	i = 0;
	test(tab, NELEM(tab), _range, TEST_NULLS);
}

// TEST 01 --> EMPTY STRINGS
ATF_TC(test01);
ATF_TC_HEAD(test01, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[1]);
}
ATF_TC_BODY(test01, tc)
{
	char	*tab[] = {
		"",
	};

	i = 1;
	test(tab, NELEM(tab), _range, 0);
}

// TEST 02 --> BIG STRINGS
ATF_TC(test02);
ATF_TC_HEAD(test02, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[2]);
}
ATF_TC_BODY(test02, tc)
{
	char	*tab[] = {
	};

	i = 2;
	test(tab, NELEM(tab), _range, 0);
}

// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);
	ATF_TP_ADD_TC(tp, test01);
	ATF_TP_ADD_TC(tp, test02);

	return (atf_no_error());
}

