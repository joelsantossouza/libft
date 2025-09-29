/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:25:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/29 16:27:55 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdio.h>
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

// TEST 00 --> NULL INPUTS
ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[0]);
}
ATF_TC_BODY(test00, tc)
{
	t_input_myown	tab[] = {
		{0, "123", 0},
		{"123", 0, 0},
		{0, 0, 0},
		{0, "", 0},
		{"", 0, 0},
		{"-+", 0, 0},
		{0, "-+", 0},
	};

	i = 0;
	test_myown(tab, NELEM(tab, t_input_myown));
}

// TEST 01 --> EMPTY INPUTS
ATF_TC(test01);
ATF_TC_HEAD(test01, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[1]);
}
ATF_TC_BODY(test01, tc)
{
	t_input_myown	tab[] = {
		{"", "", 0},
		{"1234", "", 0},
		{"", "1234", 0},
		{"", "-+", 0},
		{"-+", "", 0},
		{"  234f2 ", "", 0},
		{"", "  234f2 ", 0},
		{"", "987642", 0},
		{"987642", "", 0},
	};

	i = 1;
	test_myown(tab, NELEM(tab, t_input_myown));
}

// TEST 02 --> INVALID BASE AND NO MATCH IN STR
ATF_TC(test02);
ATF_TC_HEAD(test02, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[2]);
}
ATF_TC_BODY(test02, tc)
{
	t_input_myown	tab[] = {
		{"+120234", "0", 0},
		{"-1", "120234", 0},
		{"42", "f[3oij-", 0},
		{"zf3jjji", "f[3oij", 0},
		{"124jkl", "123478-0asrf1", 0},
		{"-123", "j-2rj-", 0},
		{"123", "", 0},
		{"123", "1", 0},
		{"123", "01234567890", 0},
		{"123", "01234 56789", 0},
		{"123", "01234+56789", 0},
		{"123", "01234-56789", 0},
		{"123", " 0123456789", 0},
		{"123", "01234\t56789", 0},
		{"123", "01233456789", 0},
		{"123", "abcdefgaa", 0},
		{"123", "a+b-c", 0},
		{"123", "0123\n456789", 0},
		{"123", "  ", 0},
		{"123", "\t\n", 0},
		{"123", "00", 0},
		{"123", "aa", 0},
		{"123", "01 ", 0},
		{"123", "01+", 0},
		{"123", "01-", 0},
		{"123", "0\t1", 0},
		{"XYZ", "01", 0},
		{"hello", "0123456789", 0},
		{"999", "abc", 0},
		{"world", "01", 0},
		{"***", "abcdef", 0},
		{"123", "abcdef", 0},
		{"qwerty", "0123456789", 0},
		{"###", "01", 0},
		{"zzz", "abc", 0},
		{"---", "0123456789", 0},
	};

	i = 2;
	test_myown(tab, NELEM(tab, t_input_myown));
}

// TEST 03 --> VALID BASE AND VALID STRING
ATF_TC(test03);
ATF_TC_HEAD(test03, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[3]);
}
ATF_TC_BODY(test03, tc)
{

	t_input_myown	tab1[] = {
		{"1[a:", "n-:a&1R[", 3034},
		{"F*6", "*F}L976E", 70},
		{"]M*]*", "*]M", 138},
		{"P*6z", "Ppz.*\\6w1!", 462},
		{"I", "y/I#Os_", 2},
		{"?[LLL", "[?eL", 319},
		{"l$l", "ml@$", 29},
		{"*3qqq", "Gq63K*U", 13091},
		{"rP", "SP1rDq", 19},
		{";~a", "!Y~;#_abX}", 326},
		{"9Q", "9Qd{3", 73},
		{"&a", "&a8$", 1},
		{"0-", "-01", 1},
		{"@0", "@0*", 0},
		{"^|", "|^%", 1},
		{"z3", "3z!", 7},
		{"M0", "M0&", 0},
		{"1&", "&1M", 1},
		{"G#1", "G#12", 7},
		{"$%$", "%$!", 3},
		{"!~", "~!", 1},
		{"AB", "ABCD", 1},
		{"CD", "ABCD", 14},
		{"AA", "AB", 0},
		{"BB", "AB", 3},
		{"XY", "XYZ", 23},
		{"Z", "XYZ", 2},
		{"..", ".#", 0},
		{"##", "#.", 1},
		{"++", "+-", 0},
		{"--", "+-", 1},
		{"11", "123", 4},
		{"23", "123", 5},
		{"321", "123", 14},
		{"12", "123", 3},
		{"@!", "@!", 1},
		{"!@", "@!", 0},
		{"%%", "%&", 0},
		{"&&", "%&", 3},
		{"~~", "~^", 0},
		{"^^", "~^", 1},
		{"**", "*+", 0},
		{"++", "*+", 1},
		{"A1", "A1B2", 2},
		{"B2", "A1B2", 7},
		{"12", "12AB", 3},
		{"21", "12AB", 5},
		{"aa", "ab", 0},
		{"bb", "ab", 3},
		{"ab", "ab", 1},
		{"ba", "ab", 2},
		{"??", "?@", 1},
		{"@?", "?@", 0},
		{"ll", "lm", 0},
		{"mm", "lm", 3},
		{"lm", "lm", 1},
		{"ml", "lm", 2},
		{"11", "12", 1},
		{"22", "12", 3},
		{"12", "12", 1},
		{"21", "12", 2},
		{"::", ":;", 0},
		{";;", ":;", 1},
		{"A+", "A+B", 1},
		{"B+", "A+B", 2},
		{"C+", "ABC", 2},
		{"AB", "ABC", 1},
		{"BC", "ABC", 5},
		{"CA", "ABC", 6},
		{"0$", "$0", 1},
		{"$0", "$0", 0},
		{"$$", "$%", 0},
		{"%%", "$%", 3},
		{"0#", "#0", 1},
		{"#0", "#0", 0},
		{"##", "#@", 0},
		{"@@", "#@", 3},
		{"XY", "XYZ", 23},
		{"XZ", "XYZ", 24},
		{"YZ", "XYZ", 26},
		{"ZX", "XYZ", 18},
		{"12", "1234", 5},
		{"34", "1234", 14},
		{"23", "1234", 7},
		{"41", "1234", 12},
		{"!$", "!$%", 1},
		{"$!", "!$%", 2},
		{"!%", "!$%", 2},
		{"%!","!$%", 1},
		{"AA", "ABCD", 0},
		{"BB", "ABCD", 5},
		{"CC", "ABCD", 10},
		{"DD", "ABCD", 15},
		{"AD", "ABCD", 3},
		{"BC", "ABCD", 6},
		{"CD", "ABCD", 7},
		{"DA", "ABCD", 12},
		{"AB", "ABCD", 1},
		{"BA", "ABCD", 4},
		{"??", "?@#", 2},
		{"@?", "?@#", 1},
		{"#?", "?@#", 0},
		{"?#", "?@#", 1},
		{"!~", "!~^", 1},
		{"~!", "!~^", 0},
		{"^!", "!~^", 2},
		{"!^", "!~^", 1},
		{"12", "12AB", 3},
		{"A1", "12AB", 8},
		{"1A", "12AB", 6},
		{"AA", "12AB", 10},
		{"B1", "12AB", 11},
		{"1B", "12AB", 9},
		{"AB", "12AB", 5},
		{"BA", "12AB", 7}
	};
	t_input_libc	tab2[] = {
		{"      \t -1023f00223r2r", "0123456789abcdef"},
		{"   +1203f0023r2r", "0123456789"},
		{"    -1203f0223r2r", "01234567"},
		{" +12002343f23r2r", "01"},
	};

	i = 3;
	test_myown(tab1, NELEM(tab1, t_input_myown));
	test_libc(tab2, NELEM(tab2, t_input_libc));
}

// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);
	ATF_TP_ADD_TC(tp, test01);
	ATF_TP_ADD_TC(tp, test02);
	ATF_TP_ADD_TC(tp, test03);

	return (atf_no_error());
}
