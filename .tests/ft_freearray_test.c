/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:25:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/03 09:20:39 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include <atf-c.h>

#define TEST_NULL	1<<0
#define NELEM(tab) (sizeof(tab) / sizeof(t_input))
#define RED		"\e[0;31m"
#define GREEN	"\e[0;32m"
#define RESET	"\e[0m"

char	*tests_titles[] = {
	"NULL array",
	"VALID array",
	"Big input",
};
static int	i;

typedef struct s_input
{
	size_t	nmemb;
	size_t	size;
	void	(*fun)(void *);
}	t_input;

void	test(t_input tab[], size_t size, int flags)
{
	struct mallinfo2	before;
	struct mallinfo2	between;
	struct mallinfo2	after;
	void				**array;
	void				**parray;
	char				*color;
	size_t				j;

	printf("\n<test%02d> %s\n", i, tests_titles[i]);
	while (size--)
	{
		before = mallinfo2();

		if (flags & TEST_NULL)
			array = 0;
		else
		{
			array = malloc(sizeof(void *) * (tab[size].nmemb + 1));
			if (array)
			{
				parray = array;
				j = -1;
				while (++j < tab[size].nmemb)
				{
					*parray = malloc(tab[size].size);
					if (!*parray++)
						break ;
				}
				*parray = 0;
			}
		}

		between = mallinfo2();
		(void)between;

		ft_freearray(array, tab[size].fun);

		after = mallinfo2();

		color =  before.uordblks == after.uordblks ? GREEN : RED;

		printf("%s", color);
		printf("Input:       \t%lu - %lu\n", tab[size].nmemb, tab[size].size);
		printf("Success Free:\t%s\n", "wait");
		printf("%s", RESET);

		ATF_CHECK(before.uordblks == after.uordblks);
		printf("----------\n");

		printf("Before: %lu\n", before.uordblks);
		printf("Between: %lu\n", between.uordblks);
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
	t_input	tab[] = {
		{2, 2, free},
	};

	i = 0;
	test(tab, NELEM(tab), 0);
}
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);

	return (atf_no_error());
}
