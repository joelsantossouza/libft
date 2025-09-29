/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:25:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/29 15:04:53 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include <atf-c.h>

#define RED		"\e[0;31m"
#define GREEN	"\e[0;32m"
#define RESET	"\e[0m"
#define NELEM(tab, type) (sizeof(tab) / sizeof(type))

char	*tests_titles[] = {
	"Null inputs",
	"Empty inputs",
	"Invalid base and No match in str",
	"Valid base and Valid str",
};
static int	i;

typedef struct s_input_libc
{
	const char	*str;
	const char	*base;
}	t_input_libc;

typedef struct s_input_myown
{
	const char	*str;
	const char	*base;
	int			expected;
}	t_input_myown;

void	test_libc(t_input_libc tab[], size_t size)
{
	int		output;
	int		expected;
	char	*color;
	char	*end;

	printf("\n<test%02d> %s\n", i, tests_titles[i]);
	while (size--)
	{
		expected = (int) strtol(tab[size].str, &end, ft_strlen(tab[size].base));
		output = ft_atoi_base(tab[size].str, tab[size].base);
		color = expected == output ? GREEN : RED;

		printf("%s", color);
		printf("Input:   \t(%s) %s\n", tab[size].base, tab[size].str);
		printf("Expected:\t%d\n", expected);
		printf("Output:  \t%d\n", output);
		printf("%s", RESET);

		ATF_CHECK_EQ(expected, output);
		printf("----------\n");
	}
}

void	test_myown(t_input_myown tab[], size_t size)
{
	int		expected;
	int		output;
	char	*color;

	printf("\n<test%02d> %s\n", i, tests_titles[i]);
	while (size--)
	{
		expected = tab[size].str && tab[size].base ? tab[size].expected : 0;
		output = ft_atoi_base(tab[size].str, tab[size].base);
		color = expected == output ? GREEN : RED;

		printf("%s", color);
		printf("Input:   \t(%s) %s\n", tab[size].base, tab[size].str);
		printf("Expected:\t%d\n", expected);
		printf("Output:  \t%d\n", output);
		printf("%s", RESET);

		ATF_CHECK_EQ(expected, output);
		printf("----------\n");
	}
}

ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", "Recreating the ctype library");
}
ATF_TC_BODY(test00, tc)
{
	test(-100, 10000);
}
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);

	return (atf_no_error());
}
