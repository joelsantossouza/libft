/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:09:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/30 16:12:19 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <atf-c.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define RED			"\e[0;31m"
#define GREEN		"\e[0;32m"
#define RESET_COLOR	"\e[0m"
#define NELEM(tab) (sizeof(tab) / sizeof(char *))
#define TEST_NULLS	1<<0

char	*test_titles[] = {
	"Null strings",
	"Empty Strings",
	"Regular Strings",
	"Big Strings",
};
static int	i;

void	test(char *tab[], int size)
{
	char	*output_dst;
	char	*expected_dst;
	char	*color;

	printf("\n<test%02d> %s\n", i, test_titles[i]);
	while (size--)
	{
		if (tab[size])
			expected_dst = strdup(tab[size]);
		else
			expected_dst = 0;
		output_dst = ft_strdup(tab[size]);
		color = !ft_strncmp(expected_dst, output_dst, ft_strlen(tab[size]) + 1) ? GREEN : RED;

		printf("%s", color);
		printf("Input:   \t%s\n", tab[size]);
		printf("Expected:\t%s\n", expected_dst);
		printf("Output:  \t%s\n", output_dst);
		printf("%s", RESET_COLOR);
		
		ATF_CHECK(!ft_strncmp(expected_dst, output_dst, ft_strlen(tab[size])));
		printf("----------\n");
		free(output_dst);
		free(expected_dst);
	}
}
// TEST 00 --> NULL STRINGS
ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[0]);
}
ATF_TC_BODY(test00, tc)
{
	char	*tab[] = {
		0,
	};

	i = 0;
	test(tab, NELEM(tab));
}

// TEST 01 --> EMPTY STRINGS
ATF_TC(test01);
ATF_TC_HEAD(test01, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[1]);
}
ATF_TC_BODY(test01, tc)
{
	char	*tab[] = {
		"",
	};

	i = 1;
	test(tab, NELEM(tab));
}

// TEST 02 --> REGULAR STRINGS
ATF_TC(test02);
ATF_TC_HEAD(test02, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[2]);
}
ATF_TC_BODY(test02, tc)
{
	i = 2;
	test(tab, NELEM(tab));
}

// TEST 03 -->
ATF_TC(test03);
ATF_TC_HEAD(test03, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[3]);
}
ATF_TC_BODY(test03, tc)
{
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
