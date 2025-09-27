/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:09:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/27 17:58:27 by joesanto         ###   ########.fr       */
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
		{"", 1000},
		{"", 100000},
		{"", 10000000},
	};

	i = 1;
	test(tab, NELEM(tab));
}

// TEST 02 --> SIZE OF ONE
ATF_TC(test02);
ATF_TC_HEAD(test02, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[2]);
}
ATF_TC_BODY(test02, tc)
{
	char	neg = -1;
	t_input	tab[] = {
		{"A", 0},
		{"A", 1},
		{"A", 2},
		{"A", 4},
		{"A", 10},
		{"A", 100},
		{"A", 1000},
		{"", 0},
		{"", 1},
		{"", 2},
		{"", 4},
		{"", 10},
		{"", 100},
		{"", 1000},
		{"\232", 0},
		{"\232", 1},
		{"\232", 2},
		{"\232", 4},
		{"\232", 10},
		{"\232", 100},
		{"\232", 1000},
		{&neg, 0},
		{&neg, 1},
		{&neg, 2},
		{&neg, 4},
		{&neg, 10},
		{&neg, 100},
		{&neg, 1000},
	};

	i = 2;
	test(tab, NELEM(tab));
}

// TEST 03 --> SIZE OF FIVE
ATF_TC(test03);
ATF_TC_HEAD(test03, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[3]);
}
ATF_TC_BODY(test03, tc)
{
	t_input	tab[] = {
		{"N#r{)", 0},
		{"f(90W", 1},
		{"Xw=!m", 2},
		{"b8/Z/", 4},
		{"Rm_;6", 10},
		{"qgRW_", 100},
		{"y9:rJ", 1000},
		{"%wjqG", 100000},
		{"]uE$e", 0},
		{".r]$E", 1},
		{"9q]w&", 2},
		{"KF#[]", 4},
		{"*ei1%", 10},
		{"hrA&a", 100},
		{"B!W7[", 1000},
		{"Xv!rt", 100000},
		{"Ud&Ug", 0},
		{"Sh]5+", 1},
		{"3u=L$", 2},
		{"cDj4v", 4},
		{"S4R;E", 10},
		{"BT__=", 100},
		{"e#CSM", 1000},
		{"8L;6{", 100000},
	};

	i = 3;
	test(tab, NELEM(tab));
}

// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);
	ATF_TP_ADD_TC(tp, test01);
	ATF_TP_ADD_TC(tp, test02);
	ATF_TP_ADD_TC(tp, test03);

	return (atf_no_error());
}
