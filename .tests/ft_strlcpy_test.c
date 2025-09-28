/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:31:08 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/28 13:39:09 by joesanto         ###   ########.fr       */
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

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if ((!s1 && !s2) || !n)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while (*s1 == *s2 && *s1 && n-- > 1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	test_nulls(t_input tab[], size_t size, int flags)
{
	char	*expected_dst;
	char	*myown_dst;
	size_t	expected_ret;
	size_t	myown_ret;
	char	*color;

	printf("{My Own Test}\n");
	while (size--)
	{
		if (flags & TEST_NULLS)
			expected_dst = myown_dst = 0;
		else
		{
			expected_dst = malloc(tab[size].dst_size);
			if (!expected_dst)
				return ;
			myown_dst = malloc(tab[size].dst_size);
			if (!myown_dst)
				return (free(expected_dst));
		}
		ft_memcpy(expected_dst, myown_dst, tab[size].dst_size);
		expected_ret = ft_strlen(tab[size].src);
		myown_ret = ft_strlcpy(myown_dst, tab[size].src, tab[size].size);
		color = expected_ret == myown_ret && !ft_strncmp(expected_dst, myown_dst, tab[size].dst_size) ? GREEN : RED;

		printf("%s", color);
		printf("Input:   \t%s\n", tab[size].src);
		printf("Expected:\t(%lu) %.*s\n", expected_ret, (int)tab[size].dst_size, expected_dst);
		printf("Output:  \t(%lu) %.*s\n", myown_ret, (int)tab[size].dst_size, myown_dst);
		printf("%s", RESET_COLOR);

		ATF_CHECK(expected_ret == myown_ret && !ft_strncmp(expected_dst, myown_dst, tab[size].dst_size));
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
	t_input	tab1[] = {
		{0, 0, 0},
		{1, 0, 0},
		{0, 0, 1},
		{1, 0, 1},
		{1, 0, 10},
		{10, 0, 10},
		{10, 0, 1},
		{100, 0, 10},
		{10, 0, 100},
		{100, 0, 100},
	};
	t_input	tab2[] = {
		{0, "f8&KqZpL#9", 0},
		{1, "TgY7w^pLk@2zR", 0},
		{0, "aP3$LmNzX!qRvT1oJ", 1},
		{1, "xV8m#QwErTzYpLd9FhGjK", 1},
		{1, "Zr7@qLpXyNwVt8sBmCkJdHf", 10},
		{10, "mP2&nXvLqWtR9zYgFhJbCsTk4o", 10},
		{10, "cL8$XpQzNrVwTgHfYjMkSaBdUiKo", 1},
		{100, "hT1@qLpXyNwVt8sBmCkJdHfZr7pRvGjF", 10},
		{10, "pR4#nXvLqWtR9zYgFhJbCsTkLmQaWmZoXt", 100},
		{100, "jK9^xLpQwErTzYpLd9FhGjKmNaSbDcVtYwXr", 100},
	};

	i = 0;
	printf("\n<test%02d> %s\n", i, tests_titles[i]);
	test_nulls(tab1, NELEM(tab1), 0);
	test_nulls(tab1, NELEM(tab1), TEST_NULLS);
	test_nulls(tab2, NELEM(tab2), TEST_NULLS);
}

// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);
	
	return (atf_no_error());
}
