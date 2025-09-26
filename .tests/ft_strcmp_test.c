/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:30:13 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/26 13:16:29 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <atf-c.h>
#include <stdio.h>

#define LIBC_EXPECT	0
#define MY_EXPECT	1<<0
#define NELEM(tab) (sizeof(tab) / sizeof(t_input))
#define GREEN		"\e[0;32m"
#define RED			"\e[0;31m"
#define RESET_COLOR "\e[0m"

/*
	STRUCTURE -->
		- INPUTS struct
		- FUNCTION that compare original strcmp output with the same input as ft_strcmp
		- A INPUT, EXPECTED and OUTPUT structure of print result
*/

char	*test_titles[] = {
	"Empty strings",
	"Nulls strings",
	"Size of One",
	"Size of Five",
	"Non Printable",
	"Out of Ascii Range",
	"Long strings",
};
static int	i;

typedef struct s_input
{
	char	*s1;
	char	*s2;
	int		expected;
}	t_input;

void	test(t_input tab[], int size, int flags)
{
	int			expected;
	int			output;
	char		*color;

	printf("\n<test%02d> %s\n\n", i, test_titles[i]);
	while (size--)
	{
		if (flags & MY_EXPECT)
			expected = tab[size].expected;
		else
			expected = strcmp(tab[size].s1, tab[size].s2);

		output = ft_strcmp(tab[size].s1, tab[size].s2);
		color = output == expected ? GREEN : RED;

		printf("%s", color);
		printf("Input:   \t\"%s\"\t-\t\"%s\"\n", tab[size].s1, tab[size].s2);
		printf("Expected:\t%3d\n", expected);
		printf("Output:  \t%3d\n\n", output);
		printf("%s", RESET_COLOR);

		ATF_CHECK_EQ(expected, output);
		printf("----------\n");
	}
}

// TEST 00 --> EMPTY STRINGS
ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[0]);
}
ATF_TC_BODY(test00, tc)
{
	char	neg = -1;
	t_input tab[] = {
		{"", "", LIBC_EXPECT},
		{"", "A", LIBC_EXPECT},
		{"A", "", LIBC_EXPECT},
		{"", "", LIBC_EXPECT},
		{"", "", LIBC_EXPECT},
		{"", "\200", LIBC_EXPECT},
		{"\200", "", LIBC_EXPECT},
		{"", "\207", LIBC_EXPECT},
		{"\207", "", LIBC_EXPECT},
		{"", "\207\300", LIBC_EXPECT},
		{"\207\300", "", LIBC_EXPECT},
		{"", "\x99\x60", LIBC_EXPECT},
		{"\x99\x60", "", LIBC_EXPECT},
		{"", "\000", LIBC_EXPECT},
		{"\000", "", LIBC_EXPECT},
		{"", "\x00", LIBC_EXPECT},
		{"\x00", "", LIBC_EXPECT},
		{"", "0", LIBC_EXPECT},
		{"0", "", LIBC_EXPECT},
		{"", "dx[[e@kd9uzRJ)BqLEv9uqt!Q/P}H[", LIBC_EXPECT},
		{"dx[[e@kd9uzRJ)BqLEv9uqt!Q/P}H[", "", LIBC_EXPECT},
		{"", &neg, LIBC_EXPECT},
		{&neg, "", LIBC_EXPECT},
	};

	i = 0;
	test(tab, NELEM(tab), LIBC_EXPECT);
}

// TEST 01 --> NULL STRINGS
ATF_TC(test01);
ATF_TC_HEAD(test01, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[1]);
}
ATF_TC_BODY(test01, tc)
{
	t_input	tab[] = {
		{0, 0, 0},
	};

	i = 1;
	test(tab, NELEM(tab), MY_EXPECT);
}

// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);
	ATF_TP_ADD_TC(tp, test01);

	return (atf_no_error());
}
