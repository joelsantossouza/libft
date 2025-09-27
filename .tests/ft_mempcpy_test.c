/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:09:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/27 11:35:48 by joesanto         ###   ########.fr       */
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
	"Char Data",
	"String Data",
	"Integer Data",
	"Float Data",
	"Struct Data",
};
static int	i;

typedef struct s_input
{
	const void	*src;
	size_t		n;
}	t_input;

typedef struct s_expect
{
	const void	*src;
	size_t		n;
	void		*expect;
}	t_expect;

void	ft_put_row(char *type, void *ptr, const char *buf, size_t size)
{
	printf("%s\t", type);
	if (ptr)
		printf("(%p) ", ptr);
	while (size--)
		printf("\\%02X", *buf++);
	printf("\n");
}

void	test(t_input tab[], int size)
{
	void	*output;
	void	*output_dst;
	void	*expected;
	void	*expected_dst;
	char	*color;

	printf("\n<test%02d> %s\n", i, test_titles[i]);
	while (size--)
	{
		output_dst = malloc(tab[size].n);
		if (!output_dst)
			return ;
		expected_dst = malloc(tab[size].n);
		if (!expected_dst)
		{
			free(output_dst);
			return ;
		}
		expected = mempcpy(expected_dst, tab[size].src, tab[size].n) - expected_dst + output_dst;
		output = ft_mempcpy(output_dst, tab[size].src, tab[size].n);
		color = expected == output && !memcmp(output_dst, expected_dst, tab[size].n) ? GREEN : RED;

		printf("%s", color);
		ft_put_row("Input:   ", output_dst, (char *) tab[size].src, tab[size].n);
		ft_put_row("Expected:", expected, (char *) expected_dst, tab[size].n);
		ft_put_row("Output:  ", output, (char *) output_dst, tab[size].n);
		printf("%s", RESET_COLOR);

		ATF_CHECK(expected == output && !memcmp(output_dst, expected_dst, tab[size].n));
		printf("----------\n");
		free(output_dst);
		free(expected_dst);
	}
}

void	test_expect(t_input tab[], int size, int flags)
{
	void	*output;
	void	*output_dst;
	void	*expected;
	char	*color;

	printf("\n-- My own Cases --\n");
	while (size--)
	{
		if (flags & TEST_NULLS)
			output_dst = 0;
		else
		{
			output_dst = malloc(tab[size].n);
			if (!output_dst)
				return ;
		}
		expected = output_dst;
		output = ft_mempcpy(output_dst, tab[size].src, tab[size].n);
		color = expected == output ? GREEN : RED;

		printf("%s", color);
		printf("Input:    \t%p\n", tab[size].src);
		printf("Expected: \t%p\n", expected);
		printf("Output:   \t%p\n", output);
		printf("%s", RESET_COLOR);

		ATF_CHECK(expected == output);
		printf("----------\n");
		free(output_dst);
		output_dst = 0;
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
	t_input	tab[] = {
		{0, 0},
		{0, 1},
		{0, 10},
		{0, 100},
		{0, 2000},
		{0, 10000},
	};

	i = 0;
	test_expect(tab, NELEM(tab), 0);
	test_expect(tab, NELEM(tab), TEST_NULLS);
}

// TEST 01 --> CHAR DATA
ATF_TC(test01);
ATF_TC_HEAD(test01, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[1]);
}
ATF_TC_BODY(test01, tc)
{
	char	neg = -1;
	t_input	tab[] = {
		{"A", sizeof(char) - 1},
		{"A", sizeof(char)},
		{"", sizeof(char)},
		{"\123", sizeof(char)},
		{"\223", sizeof(char)},
		{&neg, sizeof(char)},
	};

	i = 1;
	test(tab, NELEM(tab));
}

// TEST 02 --> STRING DATA
ATF_TC(test02);
ATF_TC_HEAD(test02, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[2]);
}
ATF_TC_BODY(test02, tc)
{
	char	*s1 = "";
	char	*s2 = "\233\221\000\x0a";
	char	*s3 = "";
	char	*s4 = "\0\0\0\0";
	char	*s5 = "2if2-fj23-8rj-2398fj3-98rfj-98jh-dof8hij8q-erjy=-ej4-ty3q8tj=-q38u45t5=305u8587owetjo23ifj2o3ijojojjjol";
	char	*s6 = "T";
	char	neg = -1;
	t_input	tab[] = {
		{s1, ft_strlen(s1)},
		{s2, ft_strlen(s2)},
		{s3, ft_strlen(s3)},
		{s4, ft_strlen(s4)},
		{s5, ft_strlen(s5) - 10},
		{s6, ft_strlen(s6) + 10},
		{&neg, ft_strlen(&neg)},
	};

	i = 2;
	test(tab, NELEM(tab));
}

// TEST 03 --> INTEGER DATA
ATF_TC(test03);
ATF_TC_HEAD(test03, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[3]);
}
ATF_TC_BODY(test03, tc)
{
	int	n1 = 0;
	int	n2 = 1;
	int	n3 = -1;
	int	n4 = -2147483648;
	int	n5 = (int) -2147483649;
	int	n6 = 2147483648;
	int	n7 = 2147483647;
	int	n8 = 2147483649;
	int	n9 = (int) 872309587230598LU;

	t_input	tab[] = {
		{&n1, sizeof(int)},
		{&n2, sizeof(int) - 3},
		{&n3, sizeof(int) - 2},
		{&n4, sizeof(int) + 30},
		{&n5, sizeof(int)},
		{&n6, sizeof(int)},
		{&n7, sizeof(int)},
		{&n8, sizeof(int)},
		{&n9, sizeof(int)},
	};

	i = 3;
	test(tab, NELEM(tab));
}

// TEST 04 --> INTEGER DATA
ATF_TC(test04);
ATF_TC_HEAD(test04, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[4]);
}
ATF_TC_BODY(test04, tc)
{
	float	n1 = 0;
	float	n2 = 2;
	float	n3 = -1;
	int	n4 = -2147483648;
	int	n5 = (int) -2147483649;
	int	n6 = 2147483648;
	int	n7 = 2147483647;
	int	n8 = 2147483649;
	int	n9 = (int) 872309587230598LU;

	t_input	tab[] = {
		{&n1, sizeof(int)},
		{&n2, sizeof(int) - 3},
		{&n3, sizeof(int) - 2},
		{&n4, sizeof(int) + 30},
		{&n5, sizeof(int)},
		{&n6, sizeof(int)},
		{&n7, sizeof(int)},
		{&n8, sizeof(int)},
		{&n9, sizeof(int)},
	};

	i = 3;
	test(tab, NELEM(tab));


// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);
	ATF_TP_ADD_TC(tp, test01);
	ATF_TP_ADD_TC(tp, test02);
	ATF_TP_ADD_TC(tp, test03);

	return (atf_no_error());
}
