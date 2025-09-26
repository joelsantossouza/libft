/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:09:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/26 20:19:43 by joesanto         ###   ########.fr       */
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

/*
   TEST CASES -->
   		- NULL DATA
		- CHAR
		- CHAR *
		- INT
		- FLOAT
		- STRUCTURES

	STRUCTURE OF TEST
		- structure of input: char *dst, char *src, size_t n
		- Create a function that going to test each case and compare with the original mempcpy
 */

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

// TEST 00 --> NULL DATA
ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[0]);
}
ATF_TC_BODY(test00, tc)
{
	t_input	tab[] = {
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
