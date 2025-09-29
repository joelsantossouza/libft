/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:25:36 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/29 15:57:04 by joesanto         ###   ########.fr       */
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
		{"1010", "01", 10},
		{"1111", "01", 15},
		{"1001", "01", 9},
		{"1100", "01", 12},
		{"0110", "01", 6},
		{"77", "01234567", 63},
		{"123", "01234567", 83},
		{"10", "01234567", 8},
		{"456", "01234567", 302},
		{"11", "01234567", 9},
		{"1A", "0123456789ABCDEF", 26},
		{"FF", "0123456789ABCDEF", 255},
		{"B4", "0123456789ABCDEF", 180},
		{"0C", "0123456789ABCDEF", 12},
		{"123", "0123456789", 123},
		{"42", "0123456789", 42},
		{"999", "0123456789", 999},
		{"7", "0123456789", 7},
		{"12345", "0123456789", 12345},
		{"ZZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 675},
		{"AB", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 28},
		{"QW", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 308},
		{"LM", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 283},
		{"CD", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 31},
		{"カケ", "アイウエオカキクケコ", 58},
		{"ウカ", "アイウエオカキクケコ", 27},
		{"エコ", "アイウエオカキクケコ", 38},
		{"オキ", "アイウエオカキクケコ", 49},
		{"カキ", "アイウエオカキクケコ", 56},
		{"漢字", "漢字", 1},
		{"字漢", "漢字", 2},
		{"漢漢", "漢字", 0},
		{"字字", "漢字", 3},
		{"🐱🐶", "🐱🐶", 1},
		{"🐶🐱", "🐱🐶", 2},
		{"🐱🐱", "🐱🐶", 0},
		{"🐶🐶", "🐱🐶", 3},
		{"😀😃", "😀😃😄😁", 6},
		{"😄😁", "😀😃😄😁", 11},
		{"😀😄", "😀😃😄😁", 8},
		{"😃😁", "😀😃😄😁", 7},
		{"çé", "abcçé", 19},
		{"abc", "abcçé", 5},
		{"bç", "abcçé", 17},
		{"éa", "abcçé", 20},
		{"ΔΣ", "ΑΒΓΔΕΣ", 121},
		{"ΑΔ", "ΑΒΓΔΕΣ", 23},
		{"ΣΔ", "ΑΒΓΔΕΣ", 35},
		{"ΔΔ", "ΑΒΓΔΕΣ", 21},
		{"ЖЮ", "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЫЭЮЯ", 61},
		{"АЖ", "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЫЭЮЯ", 6},
		{"ЮА", "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЫЭЮЯ", 25},
		{"ЖЖ", "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЫЭЮЯ", 42},
		{"١٢", "٠١٢٣٤٥٦٧٨٩", 12},
		{"٣٢", "٠١٢٣٤٥٦٧٨٩", 32},
		{"٤٥", "٠١٢٣٤٥٦٧٨٩", 45},
		{"٦٧", "٠١٢٣٤٥٦٧٨٩", 67},
		{"५४", "०१२३४५६७८९", 54},
		{"३२", "०१२३४५६७८९", 32},
		{"१२", "०१२३४५६७८९", 12},
		{"७८", "०१२३४५६७८९", 78},
		{"二一", "一二三四五六七八九", 21},
		{"五三", "一二三四五六七八九", 53},
		{"七四", "一二三四五六七八九", 74},
		{"六二", "一二三四五六七八九", 62},
		{"🀄🎴", "🀄🎴🃏", 1},
		{"🃏🀄", "🀄🎴🃏", 2},
		{"🎴🃏", "🀄🎴🃏", 5},
		{"🀄🀄", "🀄🎴🃏", 0},
		{"🎧🎼", "🎧🎼🎹", 3},
		{"🎹🎼", "🎧🎼🎹", 5},
		{"🎼🎹", "🎧🎼🎹", 7},
		{"🎧🎧", "🎧🎼🎹", 0},
		{"abcXYZ", "abcXYZ", 745},
		{"XYZabc", "abcXYZ", 857},
		{"aXbYcZ", "abcXYZ", 468},
		{"ZXYabc", "abcXYZ", 935},
		{"mnop", "mnop", 57},
		{"opmn", "mnop", 43},
		{"nmop", "mnop", 50},
		{"mnop", "mnop", 57},
		{"Δθ", "αβγδεΔθ", 34},
		{"εΔ", "αβγδεΔθ", 31},
		{"θα", "αβγδεΔθ", 41},
		{"γΔ", "αβγδεΔθ", 20},
		{"💎⚔️", "💎⚔️🛡️🏹", 6},
		{"🏹🛡️", "💎⚔️🛡️🏹", 15},
		{"⚔️💎", "💎⚔️🛡️🏹", 4},
		{"💎🏹", "💎⚔️🛡️🏹", 12},
		{"abcd", "abcd", 27},
		{"bcda", "abcd", 30},
		{"cdab", "abcd", 25},
		{"dabc", "abcd", 19},
		{"123ABC", "0123456789ABCDEF", 119468},
		{"0F1E", "0123456789ABCDEF", 3870},
		{"C0DE", "0123456789ABCDEF", 49374},
		{"FACE", "0123456789ABCDEF", 64206},
		{"👨‍💻👩‍💻", "👨‍💻👩‍💻🧑‍🚀", 1},
		{"🧑‍🚀👨‍💻", "👨‍💻👩‍💻🧑‍🚀", 6},
		{"👩‍💻🧑‍🚀", "👨‍💻👩‍💻🧑‍🚀", 7},
		{"🧑‍🚀🧑‍🚀", "👨‍💻👩‍💻🧑‍🚀", 8},
		{"テスト", "テストデータ", 14},
		{"データ", "テストデータ", 31},
		{"ストデ", "テストデータ", 19},
		{"タテス", "テストデータ", 21},
		{"αβγ", "αβγδε", 17},
		{"δεα", "αβγδε", 38},
		{"βγα", "αβγδε", 23},
		{"γδε", "αβγδε", 42}
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

	return (atf_no_error());
}
