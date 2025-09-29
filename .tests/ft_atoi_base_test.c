/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:25:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/29 16:12:05 by joesanto         ###   ########.fr       */
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

	t_input_myown	tab[] = {
		{"a\x9e-\x9e", "\x9c\x9e-a", 217},
		{"Qß1Q1", "²Qý¦Gß1¥jX", 15616},
		{"±\x87±å", "±\x87oå\x9eæ]", 52},
		{"¶¶¶\xa0", "\xa0¶", 78},
		{"::ç\x89ç", "\x89:ç", 128},
		{"±", "±Cò\x9e", 0},
		{"õÜ", "ÜPÀóõã\x9bµ°\x91", 40},
		{"ô", "ô¶å³ÝÑ", 0},
		{"y^^²²", "²^y9¯°", 2844},
		{"ß)", ")ß", 2},
		{"é\x9a", "é\x9a", 1},
		{"#~", "~#9", 2},
		{"J$J", "$J@", 9},
		{"[a]", "[]a", 5},
		{"`^", "`^%", 2},
		{"qW", "qW", 17},
		{"<:>", "<:>", 3},
		{"*+*", "+*%", 4},
		{"_~", "~_", 1},
		{"{}{}", "{}[]", 6},
		{"@!", "!@", 1},
		{"|\\", "\\|", 1},
		{"AA", "ABC", 0},
		{"B@", "AB@", 3},
		{"1/2", "123/", 5},
		{"88", "8", 0},
		{"%&%", "%&", 5},
		{"<>", "<>", 1},
		{"??", "?", 0},
		{"!!", "!", 0},
		{"aa", "a", 0},
		{"bb", "b", 0},
		{"cc", "c", 0},
		{"dd", "d", 0},
		{"ee", "e", 0},
		{"ff", "f", 0},
		{"gg", "g", 0},
		{"hh", "h", 0},
		{"ii", "i", 0},
		{"jj", "j", 0},
		{"kk", "k", 0},
		{"ll", "l", 0},
		{"mm", "m", 0},
		{"nn", "n", 0},
		{"oo", "o", 0},
		{"pp", "p", 0},
		{"qq", "q", 0},
		{"rr", "r", 0},
		{"ss", "s", 0},
		{"tt", "t", 0},
		{"uu", "u", 0},
		{"vv", "v", 0},
		{"ww", "w", 0},
		{"xx", "x", 0},
		{"yy", "y", 0},
		{"zz", "z", 0},
		{"!!", "!", 0},
		{"@@", "@", 0},
		{"##", "#", 0},
		{"$$", "$", 0},
		{"%%", "%", 0},
		{"^^", "^", 0},
		{"&&", "&", 0},
		{"**", "*", 0},
		{"((", "(", 0},
		{"))", ")", 0},
		{"__","_",0},
		{"++","+",0},
		{"==","=",0},
		{"--","-",0},
		{"~~","~",0},
		{"||","|",0},
		{"\\\\","\\",0},
		{"``","`",0},
		{"::",":",0},
		{";;",";",0},
		{"\"\"","\"",0},
		{"''","'",0},
		{"..",".",0},
		{",,",",",0},
		{"//","/",0},
		{"??","?",0},
		{"!!","!",0},
		{"@@","@",0},
		{"##","#",0},
		{"$$","$",0},
		{"%%","%",0},
		{"^^","^",0},
		{"&&","&",0},
		{"**","*",0},
		{"((","(",0},
		{"))",")",0},
		{"__","_",0},
		{"++","+",0},
		{"==","=",0},
		{"--","-",0},
		{"~~","~",0},
		{"||","|",0},
		{"\\\\","\\",0},
		{"``","`",0},
		{"::",":",0},
		{";;",";",0},
		{"\"\"","\"",0},
		{"''","'",0},
		{"..",".",0},
		{",,",",",0},
		{"//","/",0}
	};
	t_input_libc	tab2[] = {
		{"      \t -1023f00223r2r", "0123456789abcdef"},
		{"   +1203f0023r2r", "0123456789"},
		{"    -1203f0223r2r", "01234567"},
		{" +12002343f23r2r", "01"},
	};

	i = 3;
	test_myown(tab, NELEM(tab, t_input_myown));
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
