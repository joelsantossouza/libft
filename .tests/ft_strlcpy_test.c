/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:31:08 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/28 14:50:51 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <atf-c/tc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>
#include <atf-c.h>

#define NELEM(tab) (sizeof(tab) / sizeof(t_input))

#define RED			"\e[0;31m"
#define GREEN		"\e[0;32m"
#define RESET_COLOR	"\e[0m"
#define TEST_NULLS	1<<0

char	*tests_titles[] = {
	"Null Strings",
	"Empty Strings",
	"Big Strings",
	"Dest Bigger Than Src",
	"Src Bigger than Dest",
	"Size bigger Than Dest",
	"Dest bigger Than Size",
};
static int	i;

typedef struct s_input
{
	size_t		dst_size;
	const char	*src;
	size_t		size;
}	t_input;

void	test(t_input tab[], size_t size)
{
	char	*expected_dst;
	char	*myown_dst;
	size_t	expected_ret;
	size_t	myown_ret;
	char	*color;

	printf("\n<test%02d> %s\n", i, tests_titles[i]);
	while (size--)
	{
		expected_dst = malloc(tab[size].dst_size);
		if (!expected_dst)
			return ;
		myown_dst = malloc(tab[size].dst_size);
		if (!myown_dst)
			return (free(expected_dst));
		expected_ret = strlcpy(expected_dst, tab[size].src, tab[size].size);
		myown_ret = ft_strlcpy(myown_dst, tab[size].src, tab[size].size);
		color = expected_ret == myown_ret && !strncmp(expected_dst, myown_dst, tab[size].size) ? GREEN : RED;

		printf("%s", color);
		printf("Input:   \t%s\n", tab[size].src);
		printf("Expected:\t(%lu) %.*s\n", expected_ret, (int) tab[size].size, expected_dst);
		printf("Output:  \t(%lu) %.*s\n", myown_ret, (int) tab[size].size, myown_dst);
		printf("%s", RESET_COLOR);

		ATF_CHECK(expected_ret == myown_ret && !strncmp(expected_dst, myown_dst, tab[size].size));
		printf("----------\n");

		free(expected_dst);
		free(myown_dst);
	}
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if ((!s1 && !s2) || !n)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while (*s1 == *s2 && *s1 && n-- > 1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	test_nulls(t_input tab[], size_t size, int flags)
{
	char	*expected_dst;
	char	*myown_dst;
	size_t	expected_ret;
	size_t	myown_ret;
	char	*color;

	printf("{My Own Test}\n");
	while (size--)
	{
		if (flags & TEST_NULLS)
			expected_dst = myown_dst = 0;
		else
		{
			expected_dst = malloc(tab[size].dst_size);
			if (!expected_dst)
				return ;
			myown_dst = malloc(tab[size].dst_size);
			if (!myown_dst)
				return (free(expected_dst));
		}
		ft_memcpy(expected_dst, myown_dst, tab[size].dst_size);
		expected_ret = ft_strlen(tab[size].src);
		myown_ret = ft_strlcpy(myown_dst, tab[size].src, tab[size].size);
		color = expected_ret == myown_ret && !ft_strncmp(expected_dst, myown_dst, tab[size].dst_size) ? GREEN : RED;

		printf("%s", color);
		printf("Input:   \t%s\n", tab[size].src);
		printf("Expected:\t(%lu) %.*s\n", expected_ret, (int)tab[size].dst_size, expected_dst);
		printf("Output:  \t(%lu) %.*s\n", myown_ret, (int)tab[size].dst_size, myown_dst);
		printf("%s", RESET_COLOR);

		ATF_CHECK(expected_ret == myown_ret && !ft_strncmp(expected_dst, myown_dst, tab[size].dst_size));
		printf("----------\n");

		free(expected_dst);
		free(myown_dst);
	}
}

// TEST 00 --> NULL STRINGS
ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[0]);
}
ATF_TC_BODY(test00, tc)
{
	t_input	tab1[] = {
		{0, 0, 0},
		{1, 0, 0},
		{0, 0, 1},
		{1, 0, 1},
		{1, 0, 10},
		{10, 0, 10},
		{10, 0, 1},
		{100, 0, 10},
		{10, 0, 100},
		{100, 0, 100},
	};
	t_input	tab2[] = {
		{0, "f8&KqZpL#9", 0},
		{1, "TgY7w^pLk@2zR", 0},
		{0, "aP3$LmNzX!qRvT1oJ", 1},
		{1, "xV8m#QwErTzYpLd9FhGjK", 1},
		{1, "Zr7@qLpXyNwVt8sBmCkJdHf", 10},
		{10, "mP2&nXvLqWtR9zYgFhJbCsTk4o", 10},
		{10, "cL8$XpQzNrVwTgHfYjMkSaBdUiKo", 1},
		{100, "hT1@qLpXyNwVt8sBmCkJdHfZr7pRvGjF", 10},
		{10, "pR4#nXvLqWtR9zYgFhJbCsTkLmQaWmZoXt", 100},
		{100, "jK9^xLpQwErTzYpLd9FhGjKmNaSbDcVtYwXr", 100},
	};

	i = 0;
	printf("\n<test%02d> %s\n", i, tests_titles[i]);
	test_nulls(tab1, NELEM(tab1), 0);
	test_nulls(tab1, NELEM(tab1), TEST_NULLS);
	test_nulls(tab2, NELEM(tab2), TEST_NULLS);
}

// TEST 01 --> EMPTY STRINGS
ATF_TC(test01);
ATF_TC_HEAD(test01, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[1]);
}
ATF_TC_BODY(test01, tc)
{
	t_input	tab[] = {
		{0, "", 0},
		{1, "", 0},
		{1, "", 1},
		{0, "", 1},
		{10, "", 1},
		{10, "", 10},
		{1, "", 10},
		{100, "", 10},
		{100, "", 100},
		{10, "", 100},
		{10000, "", 100},
		{10000, "", 10000},
	};

	i = 1;
	test(tab, NELEM(tab));
}

// TEST 02 --> BIG STRINGS
ATF_TC(test02);
ATF_TC_HEAD(test02, tc)
{
	atf_tc_set_md_var(tc, "descr", tests_titles[2]);
}
ATF_TC_BODY(test02, tc)
{
	t_input	tab[] = {
		{48291, "kT9vQ", 92734},
		{123, "漢字かなカタカナ", 99999},
		{90812, "😀😃😄😁", 271},
		{56789, "ЖщЮяЁЇҐ", 31415},
		{777, "abcXYZ123ç", 888},
		{45001, "テストデータ測定", 67890},
		{91324, "LoremIpsum123", 1000},
		{22222, "🌍🚀✨🔥", 54321},
		{99999, "Δεδομένα", 11111},
		{13579, "طَبْشُورَة‎", 24680},
		{44444, "नमस्तेभारत", 98765},
		{31416, "꧁༺✿༻꧂", 27182},
		{10101, "ABCDEFGHIJKLMNOPQRSTUVWXYZ漢字", 20202},
		{8080, "©®™✓✔✖", 9090},
		{60000, "🦄👾🤖👽", 70000},
		{2468, "↔↕↖↗↘↙↩↪", 1357},
		{55555, "Data測試Тест", 33333},
		{43210, "qZ7^NdYp#kLm漢字", 6789},
		{87654, "🎵🎶🎼", 12345},
		{3141, "文字列の長さテストです", 59265},
		{14785, "🐉🐲🦄👾🤖", 9653},
		{90123, "abcdef123456", 123},
		{74589, "😆😅😂🤣", 85214},
		{52000, "Здра́вствуйте", 31010},
		{27182, "✈️🚗🚲🛴", 31416},
		{88888, "カタカナひらがな", 22222},
		{99000, "ΔοκιμήUnicode", 1010},
		{4444, "مرحبا", 7777},
		{54321, "1234567890漢字", 13579},
		{33333, "Ω≈ç√∫˜µ≤≥÷", 44444},
		{2222, "こんにちは世界", 8888},
		{1000, "🎭🎨🎬🎤", 90000},
		{65432, "abcdefghijklmnop", 24680},
		{11111, "テキストデータ12345", 22222},
		{76543, "🎧🎼🎹🥁", 23456},
		{888, "abcdef漢字😀", 111},
		{9999, "꧁༺✿✿༻꧂", 7777},
		{24680, "data測試テスト", 13579},
		{11223, "🀄🎴🃏", 44556},
		{33445, "漢字カタカナ123", 66778},
		{55667, "👑💎⚔️🛡️🏹", 88990},
		{77889, "Lorem ipsum 😀😃😄", 99000},
		{99001, "♠♥♦♣♪♫♬⚡", 100},
		{12345, "abcdefghi漢字", 67890},
		{5432, "👨‍💻👩‍💻🧑‍🚀", 9876},
		{3210, "測定データ123", 11111},
		{111, "ЖщЮ漢字😀🚀", 222},
		{222, "🌌🌠🌟💫", 333},
		{333, "テスト漢字カタカナ", 444},
		{444, "🐍🐢🦎🦂", 555},
		{555, "Δεδομένα漢字😀", 666},
		{666, "🔥💧🌈", 777},
		{777, "꧁༺Unicode༻꧂", 888},
		{888, "πρστυφχψω", 999},
		{999, "🚀✨🌍🎶", 111},
		{10000, "абвгдежзийкл", 20000},
		{20001, "😀漢字テスト", 30002},
		{30003, "🎼🎵🎶", 40004},
		{40005, "∑∆∏∫√", 50006},
		{50007, "☀☁❄☂☃", 60008},
		{60009, "qwerty漢字жшюя😀", 70010},
		{70011, "テストデータ測定123", 80012},
		{80013, "🎹🥁🎸", 90014},
		{90015, "ΔοκιμήUnicode漢字", 100016},
		{11112, "Data測試Тестاختبار", 12113},
		{12114, "©®™✓✔✖漢字", 13115},
		{13116, "abcXYZ123", 14117},
		{14118, "δθλμνξ", 15119},
		{15120, "😆😅😂🤣漢字", 16121},
		{16122, "テスト12345", 17123},
		{17124, "こんにちは", 18125},
		{18126, "🐉🐲🦄👾🤖👽", 19127},
		{19128, "ЖщЮяЁЇҐѪ", 20129},
		{20130, "LoremIpsum😀", 21131},
		{21132, "🌍🚀✨🔥💧", 22133},
		{22134, "ΔεδομέναΣυμβολοσειρά", 23135},
		{23136, "طَبْشُورَة", 24137},
		{24138, "नमस्तेभारत漢字", 25139},
		{25140, "꧁༺✿⚡✿༻꧂", 26141},
		{26142, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 27143},
		{27144, "©®™✓✔✖😃", 28145},
		{28146, "🦄👾🤖👽💀☠️", 29147},
		{29148, "↔↕↖↗↘↙↩↪漢字", 30149},
		{30150, "テストデータPrueba", 31151},
		{31152, "🎵🎶🎼漢字かな", 32153},
		{32154, "文字列の長さはテストです", 33155},
		{33156, "👑💎⚔️🛡️🏹🎯", 34157},
		{34158, "Ω≈ç√∫˜µ≤≥÷漢字", 35159},
		{35160, "Data測試", 36161},
		{36162, "🀄🎴🃏漢字", 37163},
		{37164, "abcdefg1234567", 38165},
		{38166, "🎧🎼🎹", 39167},
		{39168, "πρστυφ漢字ψω", 40169},
		{40170, "🚀✨🌍🎶🔥💧", 41171},
		{41172, "テスト漢字カタカナ123", 42173},
		{42174, "🐍🐢🦎🦂漢字", 43175},
		{43176, "Δεδομένα漢字😀🚀", 44177},
		{44178, "🔥💧🌈🎭", 45179},
	};

	i = 2;
	test(tab, NELEM(tab));
}

// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);
	ATF_TP_ADD_TC(tp, test01);
	ATF_TP_ADD_TC(tp, test02);
	
	return (atf_no_error());
}
