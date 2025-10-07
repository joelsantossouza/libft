/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:25:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/07 19:23:16 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <atf-c.h>

#define RED		"\e[0;31m"
#define GREEN	"\e[0;32m"
#define RESET	"\e[0m"
#define NELEM(tab) (sizeof(tab) / sizeof(t_list *))

void    print_list(t_list *begin)                                                                                                                                                             
{                                                                                                                                                                                             
	while (begin)                                                                                                                                                                         
	{                                                                                                                                                                                     
		printf("%p%s", begin->content, !begin->next ? "" : ", ");                                                                                                                     
		begin = begin->next;                                                                                                                                                          
	}                                                                                                                                                                                     
	printf("\n");                                                                                                                                                                         
} 

void	test(t_list *tab[], size_t size)
{
	int		output;
	int		expected;
	char	*color;

	while (size--)
	{
		expected = lstsize(tab[size]);
		output = ft_lstsize(tab[size]);
		color = output == expected ? GREEN : RED;

		printf("%s", color);
		printf("Input:   \t"); print_list(tab[size]);
		printf("Expected:\t%d\n", expected);
		printf("Output:  \t%d\n", output);
		printf("%s", RESET);

		ATF_CHECK(output == expected);
		printf("----------\n");

		ft_lstclear(&tab[size], 0);
	}
}

ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", "Testing some inputs in creation of a node of a linked list");
}
ATF_TC_BODY(test00, tc)
{
	t_list	*tab[] = {
	};

	test(tab, NELEM(tab));
}
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);

	return (atf_no_error());
}
