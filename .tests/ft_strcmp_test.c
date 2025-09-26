/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:30:13 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/26 10:25:04 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <atf-c.h>
#include <stdio.h>

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
	"Empty and Nulls",
	"Size of One",
	"Size of Five",
	"Non Printable",
	"Out of Ascii Range",
	"Long strings"
};
static int	i;

typedef struct s_input
{
	char	*s1;
	char	*s2;
}	t_input;

void	test(t_input tab[], int size)
{
	int			expected;
	int			output;
	char		*color;

	printf("<test%02d> %s\n\n----------\n", i, test_titles[i]);
	while (size--)
	{
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
	i++;
}

// TEST 00 --> EMPTY AND NULLS
ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[i]);
}
ATF_TC_BODY(test00, tc)
{
	t_input tab[] = {
		{"", ""}
	};

	test(tab, NELEM(tab));
}

// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);

	return (atf_no_error());
}
