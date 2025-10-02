/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:25:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/02 20:26:41 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include <atf-c.h>

#define NELEM(tab) (sizeof(tab) / sizeof(char *))
#define RED		"\e[0;31m"
#define GREEN	"\e[0;32m"
#define RESET	"\e[0m"

char	*tests_titles[] = {
	"NULL array",
	"VALID array",
	"Big input",
};

void	test(char *tab[], size_t size)
{
	struct mallinfo2 before;
	struct mallinfo2 after;
	char	*color;

	while (size--)
	{

		before = mallinfo2();
		color =  ? GREEN : RED;
		after = mallinfo2();

		printf("%s", color);
		printf("Input:       \t%s\n", tab[size]);
		printf("Success Free:\t%s\n", "wait");
		printf("%s", RESET);

		ATF_CHECK(1);
		printf("----------\n");

		printf("Before: %lu\n", before.uordblks);
		printf("After:  %lu\n", after.uordblks);
	}
}

// TEST 00 --> NULL ARRAY
ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[0]);
}
ATF_TC_BODY(test00, tc)
{
	char	*tab[] = {
		0,
	};

	test(tab, NELEM(tab));
}
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);

	return (atf_no_error());
}
