/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:30:13 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/26 10:00:19 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <atf-c.h>
#include <stdio.h>

#define NELEM(tab) (sizeof(tab) / sizeof(t_input))
#define GREEN
#define RED
#define RESET_COLOR

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

typedef struct s_input
{
	char	*s1;
	char	*s2;
}	t_input;

void	test(t_input tab[], int size)
{
	static int	i;
	int			expected;
	int			output;

	printf("<test%02d> %s\n\n----------\n", i, test_titles[i]);
	while (size--)
	{
		expected = strcmp(tab[size].s1, tab[size].s2);
		output = ft_strcmp(tab[size].s1, tab[size].s2);
		color = output == expected ? GREEN : RED;

		printf("%s", COLOR);
		printf("Input:   \t\"%s\"\t-\t\"%s\"\n", tab[size].s1, tab[size].s2);
		printf("Expected:\t%3d\n", expected);
		printf("Output:  \t%3d\n", output);
		printf("%s", RESET_COLOR);

		printf("\n----------\n");
	}
	i++;
}

// TEST 00 --> EMPTY AND NULLS
ATF_TC(test00);
ATF_TC_BODY(tes00, tc)
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
