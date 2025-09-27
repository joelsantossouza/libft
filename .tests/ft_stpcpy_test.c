/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:09:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/27 17:12:27 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <atf-c.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define RED			"\e[0;31m"
#define GREEN		"\e[0;32m"
#define RESET_COLOR	"\e[0m"
#define NELEM(tab) (sizeof(tab) / sizeof(t_input))
#define TEST_NULLS	1<<0

char	*test_titles[] = {
	"Null Data",
	"Empty strings",
	"Size of One",
	"Size of Five",
	"Dest bigger than src",
	"Src bigger than dest",
};
static int	i;

typedef struct s_input
{
	const char	*src;
	size_t		size;
}	t_input;

void	test(t_input tab[], int size)
{
	char	*output;
	char	*output_dst;
	char	*expected;
	char	*expected_dst;
	char	*color;

	printf("\n<test%02d> %s\n", i, test_titles[i]);
	while (size--)
	{
		output_dst = malloc(tab[size].size);
		if (!output_dst)
			return ;
		expected_dst = malloc(tab[size].size);
		if (!expected_dst)
		{
			free(output_dst);
			return ;
		}
		expected = stpcpy(expected_dst, tab[size].src) - expected_dst + output_dst;
		output = ft_stpcpy(output_dst, tab[size].src);
		color = expected == output && !strcmp(output_dst, expected_dst) ? GREEN : RED;

		printf("%s", color);
		printf("Input:   \t(%p) %s\n", output_dst, tab[size].src);
		printf("Expected:\t(%p) %s\n", expected, expected_dst);
		printf("Output:  \t(%p) %s\n", output, output_dst);
		printf("%s", RESET_COLOR);

		ATF_CHECK(expected == output && !strcmp(output_dst, expected_dst));
		printf("----------\n");
		free(output_dst);
		free(expected_dst);
	}
}

void	test_expect(t_input tab[], int size, int flags)
{
	char	*output;
	char	*output_dst;
	char	*expected;
	char	*color;

	printf("\n-- My own Cases --\n");
	while (size--)
	{
		if (flags & TEST_NULLS)
			output_dst = 0;
		else
		{
			output_dst = malloc(tab[size].size);
			if (!output_dst)
				return ;
		}
		expected = output_dst;
		output = ft_stpcpy(output_dst, tab[size].src);
		color = expected == output ? GREEN : RED;

		printf("%s", color);
		printf("Input:    \t%p\n", tab[size].src);
		printf("Expected: \t%p\n", expected);
		printf("Output:   \t%p\n", output);
		printf("%s", RESET_COLOR);

		ATF_CHECK(expected == output);
		printf("----------\n");
		free(output_dst);
	}
}

// TEST 00 --> NULL DATA
ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[0]);
}
ATF_TC_BODY(test00, tc)
{
	t_input	tab1[] = {
		{0, 0},
		{0, 1},
		{0, 10},
		{0, 100},
		{0, 2000},
		{0, 10000},
	};

	t_input	tab2[] = {
		{"This is a test", 0},
		{"This is a test", 1},
		{"This is a test", 10},
		{"This is a test", 100},
		{"This is a test", 2000},
	};

	i = 0;
	printf("\n<test%02d> %s\n", i, test_titles[i]);
	test_expect(tab1, NELEM(tab1), 0);
	test_expect(tab1, NELEM(tab1), TEST_NULLS);
	test_expect(tab2, NELEM(tab2), TEST_NULLS);
}

// TEST 01 --> EMPTY STRINGS
ATF_TC(test01);
ATF_TC_HEAD(test01, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[1]);
}
ATF_TC_BODY(test01, tc)
{
	t_input	tab[] = {
		{"", 0},
		{"", 1},
		{"", 2},
		{"", 50},
		{"", 100},
	};

	i = 1;
	test(tab, NELEM(tab));
}

// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);
	ATF_TP_ADD_TC(tp, test01);

	return (atf_no_error());
}
