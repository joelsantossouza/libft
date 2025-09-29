/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:31:08 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/29 21:19:23 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <atf-c/tc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>
#include <atf-c.h>

#define NELEM(tab) (sizeof(tab) / sizeof(t_input))

#define RED			"\e[0;31m"
#define GREEN		"\e[0;32m"
#define RESET_COLOR	"\e[0m"
#define TEST_NULLS	1<<0

char	*tests_titles[] = {
	"Null Strings",
	"Empty Strings",
	"Big Strings",
	"Dest Bigger Than Src",
	"Src Bigger than Dest",
};
static int	i;

typedef struct s_input
{
	const char	*big;
	const char	*little;
}	t_input;

void	test(t_input tab[], size_t size)
{
	char	*expected;
	char	*output;
	char	*color;
	size_t	len;
	size_t	str_len;

	printf("\n<test%02d> %s\n", i, tests_titles[i]);
	while (size--)
	{
		str_len = ft_strlen(tab[size].big) + 2;
		len = -1;
		while (++len <= str_len)
		{
			expected = strnstr(tab[size].big, tab[size].little, len);
			output = ft_strnstr(tab[size].big, tab[size].little, len);
			color = expected == output ? GREEN : RED;

			printf("%s", color);
			printf("Input:   \t%s - %s\t(%lu)\n", tab[size].big, tab[size].little, len);
			printf("Expected:\t(%p) %s\n", expected, expected);
			printf("Output:  \t(%p) %s\n", output, output);
			printf("%s", RESET_COLOR);

			ATF_CHECK_EQ(output, expected);
			printf("----------\n");
		}
	}
}

void	test_nulls(t_input tab[], size_t size)
{
	char	*expected;
	char	*output;
	char	*color;
	size_t	len;
	size_t	str_len;

	printf("\n<test%02d> %s\n", i, tests_titles[i]);
	while (size--)
	{
		str_len = ft_strlen(tab[size].big) + 2;
		len = -1;
		while (++len <= str_len)
		{
			expected = 0;
			output = ft_strnstr(tab[size].big, tab[size].little, len);
			color = expected == output ? GREEN : RED;

			printf("%s", color);
			printf("Input:   \t%s - %s\t(%lu)\n", tab[size].big, tab[size].little, len);
			printf("Expected:\t(%p) %s\n", expected, expected);
			printf("Output:  \t(%p) %s\n", output, output);
			printf("%s", RESET_COLOR);

			ATF_CHECK_EQ(output, expected);
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
	t_input	tab1[] = {
		{0, 0},
		{"hi", 0},
		{0, "hi"},
		{"", 0},
		{"\x01", 0},
		{"", 0},
		{"29fj20f9j2", 0},
		{0, ""},
		{"\000", 0},
		{0, 0},
		{"abc", 0},
	};

	i = 0;
	test_nulls(tab1, NELEM(tab1));
}

// TEST 01 --> EMPTY STRINGS
ATF_TC(test01);
ATF_TC_HEAD(test01, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[1]);
}
ATF_TC_BODY(test01, tc)
{
	t_input	tab[] = {
		{},
	};

	i = 1;
	test(tab, NELEM(tab));
}

// TEST 02 --> BIG STRINGS
ATF_TC(test02);
ATF_TC_HEAD(test02, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[2]);
}
ATF_TC_BODY(test02, tc)
{
	t_input	tab[] = {
	};

	i = 2;
	test(tab, NELEM(tab));
}

// TEST 03 --> DEST BIGGER THAN SRC
ATF_TC(test03);
ATF_TC_HEAD(test03, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[3]);
}
ATF_TC_BODY(test03, tc)
{
	t_input	tab[] = {
	};

	i = 3;
	test(tab, NELEM(tab));
}

// TEST 04 --> SRC BIGGER THAN DEST
ATF_TC(test04);
ATF_TC_HEAD(test04, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[4]);
}
ATF_TC_BODY(test04, tc)
{
	t_input	tab[] = {
	};
	
	i = 4;
	test(tab, NELEM(tab));
}

// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);
	ATF_TP_ADD_TC(tp, test01);
	ATF_TP_ADD_TC(tp, test02);
	ATF_TP_ADD_TC(tp, test03);
	ATF_TP_ADD_TC(tp, test04);

	return (atf_no_error());
}
