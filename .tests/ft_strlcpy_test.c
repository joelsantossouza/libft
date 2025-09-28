/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:31:08 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/28 12:16:16 by joesanto         ###   ########.fr       */
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

char	*tests_titles[] = {
	"Null Strings",
	"Empty Strings",
	"Big Strings",
	"Dest Bigger Than Src",
	"Src Bigger than Dest",
	"Size bigger Than Dest",
	"Dest bigger Than Size",
};
static int	i;

typedef struct s_input
{
	size_t		dst_size;
	const char	*src;
	size_t		size;
}	t_input;

void	test(t_input tab[], size_t size)
{
	char	*expected_dst;
	char	*myown_dst;
	size_t	expected_ret;
	size_t	myown_ret;
	char	*color;

	printf("\n<test%02d> %s\n", i, tests_titles[i]);
	while (size--)
	{
		expected_dst = malloc(tab[size].dst_size);
		if (!expected_dst)
			return ;
		myown_dst = malloc(tab[size].dst_size);
		if (!myown_dst)
			return (free(expected_dst));
		expected_ret = strlcpy(expected_dst, tab[size].src, tab[size].size);
		myown_ret = ft_strlcpy(myown_dst, tab[size].src, tab[size].size);
		color = expected_ret == myown_ret && strcmp(expected_dst, myown_dst) ? GREEN : RED;

		printf("%s", color);
		printf("Input:   \t%s\n", tab[size].src);
		printf("Expected:\t(%lu) %s\n", expected_ret, expected_dst);
		printf("Output:  \t(%lu) %s\n", myown_ret, myown_dst);
		printf("%s", RESET_COLOR);

		ATF_CHECK(expected_ret == myown_ret && strcmp(expected_dst, myown_dst));
		printf("----------\n");

		free(expected_dst);
		free(myown_dst);
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
	t_input	tab[] = {
		{0, 0, 0},
	};

	i = 0;
	test(tab, NELEM(tab));
}

// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);
	
	return (atf_no_error());
}
