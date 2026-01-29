/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:09:36 by joesanto          #+#    #+#             */
/*   Updated: 2026/01/29 12:33:51 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <atf-c.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define RED			"\e[0;31m"
#define GREEN		"\e[0;32m"
#define RESET_COLOR	"\e[0m"
#define NELEM(tab) (sizeof(tab) / sizeof(t_input))
#define TEST_NULLS	1<<0

char	*test_titles[] = {
	"Null Data",
	"Char Data",
	"String Data",
	"Integer Data",
	"Float Data",
	"Struct Data and Arrays",
};
static int	i;

typedef struct s_input
{
	const void	*src;
	size_t		n;
}	t_input;

void	ft_put_row(char *type, void *ptr, const char *buf, size_t size)
{
	printf("%s\t", type);
	if (ptr)
		printf("(%p) ", ptr);
	while (size--)
		printf("\\%02X", *buf++);
	printf("\n");
}

void	test(t_input tab[], int size)
{
	void	*output;
	void	*output_dst;
	void	*expected;
	void	*expected_dst;
	char	*color;

	printf("\n<test%02d> %s\n", i, test_titles[i]);
	while (size--)
	{
		output_dst = malloc(tab[size].n);
		if (!output_dst)
			return ;
		expected_dst = malloc(tab[size].n);
		if (!expected_dst)
		{
			free(output_dst);
			return ;
		}
		expected = memcpy(expected_dst, tab[size].src, tab[size].n) - expected_dst + output_dst;
		output = ft_memcpy(output_dst, tab[size].src, tab[size].n);
		color = expected == output && !memcmp(output_dst, expected_dst, tab[size].n) ? GREEN : RED;

		printf("%s", color);
		ft_put_row("Input:   ", output_dst, (char *) tab[size].src, tab[size].n);
		ft_put_row("Expected:", expected, (char *) expected_dst, tab[size].n);
		ft_put_row("Output:  ", output, (char *) output_dst, tab[size].n);
		printf("%s", RESET_COLOR);

		ATF_CHECK(expected == output && !memcmp(output_dst, expected_dst, tab[size].n));
		printf("----------\n");
		free(output_dst);
		free(expected_dst);
	}
}

void	test_expect(t_input tab[], int size, int flags)
{
	void	*output;
	void	*output_dst;
	void	*expected;
	char	*color;

	printf("\n-- My own Cases --\n");
	while (size--)
	{
		if (flags & TEST_NULLS)
			output_dst = 0;
		else
		{
			output_dst = malloc(tab[size].n);
			if (!output_dst)
				return ;
		}
		expected = output_dst;
		output = ft_memcpy(output_dst, tab[size].src, tab[size].n);
		color = expected == output ? GREEN : RED;

		printf("%s", color);
		printf("Input:    \t%p\n", tab[size].src);
		printf("Expected: \t%p\n", expected);
		printf("Output:   \t%p\n", output);
		printf("%s", RESET_COLOR);

		ATF_CHECK(expected == output);
		printf("----------\n");
		free(output_dst);
		output_dst = 0;
	}
}

// TEST 00 --> NULL DATA
ATF_TC(test00);
ATF_TC_HEAD(test00, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[0]);
}
ATF_TC_BODY(test00, tc)
{
	t_input	tab[] = {
		{0, 0},
		{0, 1},
		{0, 10},
		{0, 100},
		{0, 2000},
		{0, 10000},
	};

	i = 0;
	test_expect(tab, NELEM(tab), 0);
	test_expect(tab, NELEM(tab), TEST_NULLS);
}

// TEST 01 --> CHAR DATA
ATF_TC(test01);
ATF_TC_HEAD(test01, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[1]);
}
ATF_TC_BODY(test01, tc)
{
	char	neg = -1;
	t_input	tab[] = {
		{"A", sizeof(char) - 1},
		{"A", sizeof(char)},
		{"", sizeof(char)},
		{"\123", sizeof(char)},
		{"\223", sizeof(char)},
		{&neg, sizeof(char)},
	};

	i = 1;
	test(tab, NELEM(tab));
}

// TEST 02 --> STRING DATA
ATF_TC(test02);
ATF_TC_HEAD(test02, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[2]);
}
ATF_TC_BODY(test02, tc)
{
	char	*s1 = "";
	char	*s2 = "\233\221\000\x0a";
	char	*s3 = "";
	char	*s4 = "\0\0\0\0";
	char	*s5 = "2if2-fj23-8rj-2398fj3-98rfj-98jh-dof8hij8q-erjy=-ej4-ty3q8tj=-q38u45t5=305u8587owetjo23ifj2o3ijojojjjol";
	char	*s6 = "T";
	char	neg = -1;
	t_input	tab[] = {
		{s1, ft_strlen(s1)},
		{s2, ft_strlen(s2)},
		{s3, ft_strlen(s3)},
		{s4, ft_strlen(s4)},
		{s5, ft_strlen(s5) - 10},
		{s6, ft_strlen(s6) + 10},
		{&neg, ft_strlen(&neg)},
	};

	i = 2;
	test(tab, NELEM(tab));
}

// TEST 03 --> INTEGER DATA
ATF_TC(test03);
ATF_TC_HEAD(test03, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[3]);
}
ATF_TC_BODY(test03, tc)
{
	int	n1 = 0;
	int	n2 = 1;
	int	n3 = -1;
	int	n4 = -2147483648;
	int	n5 = (int) -2147483649;
	int	n6 = 2147483648;
	int	n7 = 2147483647;
	int	n8 = 2147483649;
	int	n9 = (int) 872309587230598LU;

	t_input	tab[] = {
		{&n1, sizeof(int)},
		{&n2, sizeof(int) - 3},
		{&n3, sizeof(int) - 2},
		{&n4, sizeof(int) + 30},
		{&n5, sizeof(int)},
		{&n6, sizeof(int)},
		{&n7, sizeof(int)},
		{&n8, sizeof(int)},
		{&n9, sizeof(int)},
	};

	i = 3;
	test(tab, NELEM(tab));
}

// TEST 04 --> FLOAT DATA
ATF_TC(test04);
ATF_TC_HEAD(test04, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[4]);
}
ATF_TC_BODY(test04, tc)
{
	float	n1 = 0;
	float	n2 = 0.1;
	float	n3 = -0.1;
	float	n4 = -0.203489;
	float	n5 = -340282346638528859811704183484516925440.0000000000000000;
	float	n6 = 340282346638528859811704183484516925440.0000000000000000;
	float	n7 = 340282346638528859811704183484516925449082374.0000000000000000;
	float	n8 = 909857.2394;
	float	n9 = 340282346638528859811704183484516925440.9999999999999999999999;

	t_input	tab[] = {
		{&n1, sizeof(float)},
		{&n2, sizeof(float) - 3},
		{&n3, sizeof(float) - 2},
		{&n4, sizeof(float) + 30},
		{&n5, sizeof(float)},
		{&n6, sizeof(float)},
		{&n7, sizeof(float)},
		{&n8, sizeof(float)},
		{&n9, sizeof(float)},
	};

	i = 4;
	test(tab, NELEM(tab));
}

// TEST 05 --> STRUCTURE DATA AND ARRAYS
ATF_TC(test05);
ATF_TC_HEAD(test05, tc)
{
	atf_tc_set_md_var(tc, "descr", test_titles[5]);
}
ATF_TC_BODY(test05, tc)
{
	t_input	data1 = {"This is a Test", 666};
	t_input	data2 = {0, -666};
	int		array_int[] = {1, 2, 3, 4, 5};
	float	array_float[] = {0.1, -234.234, 99999.1, 23541412.412424};
	t_input	array_inputs[] = {data1, data2};

	t_input	tab[] = {
		{&data1, sizeof(data1)},
		{&data2, sizeof(data2)},
		{array_int, sizeof(array_int)},
		{array_float, sizeof(array_float)},
		{array_inputs, sizeof(array_inputs)},
	};

	i = 5;
	test(tab, NELEM(tab));
}

ATF_TC(test_06_unaligned_destination);
ATF_TC_HEAD(test_06_unaligned_destination, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test copying to unaligned destination");
}
ATF_TC_BODY(test_06_unaligned_destination, tc)
{
	char buffer[30];
	const char *src = "this is a test";

	memset(buffer, 'X', sizeof(buffer));
	ft_memcpy(buffer + 13, src, strlen(src));

	ATF_REQUIRE_EQ(memcmp(buffer + 13, src, strlen(src)), 0);
	// Verify data before offset wasn't touched
	for (int i = 0; i < 13; i++)
		ATF_REQUIRE_EQ(buffer[i], 'X');
}

ATF_TC(test_07_unaligned_source);
ATF_TC_HEAD(test_07_unaligned_source, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test copying from unaligned source");
}
ATF_TC_BODY(test_07_unaligned_source, tc)
{
	char source[30] = "XXXXXXXXXXhello world";
	char dest[15];

	ft_memcpy(dest, source + 10, 11);

	ATF_REQUIRE_EQ(memcmp(dest, "hello world", 11), 0);
}

ATF_TC(test_08_both_unaligned);
ATF_TC_HEAD(test_08_both_unaligned, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test copying between two unaligned pointers");
}
ATF_TC_BODY(test_08_both_unaligned, tc)
{
	char source[30] = "AAAAA12345BBBBB";
	char dest[30];

	memset(dest, 'X', sizeof(dest));
	ft_memcpy(dest + 7, source + 5, 5);

	ATF_REQUIRE_EQ(memcmp(dest + 7, "12345", 5), 0);
	// Verify surrounding data wasn't touched
	for (int i = 0; i < 7; i++)
		ATF_REQUIRE_EQ(dest[i], 'X');
}

ATF_TC(test_09_unaligned_odd_offset);
ATF_TC_HEAD(test_09_unaligned_odd_offset, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test with odd offset (misalignment)");
}
ATF_TC_BODY(test_09_unaligned_odd_offset, tc)
{
	char buffer[50];
	const char *data = "testing unaligned copy";

	memset(buffer, 0, sizeof(buffer));
	ft_memcpy(buffer + 3, data, strlen(data));

	ATF_REQUIRE_EQ(memcmp(buffer + 3, data, strlen(data)), 0);
}

ATF_TC(test_10_unaligned_various_sizes);
ATF_TC_HEAD(test_10_unaligned_various_sizes, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test unaligned copies with various sizes");
}
ATF_TC_BODY(test_10_unaligned_various_sizes, tc)
{
	char buffer[100];

	// 1 byte unaligned
	memset(buffer, 0, sizeof(buffer));
	ft_memcpy(buffer + 5, "A", 1);
	ATF_REQUIRE_EQ(buffer[5], 'A');

	// 3 bytes unaligned
	memset(buffer, 0, sizeof(buffer));
	ft_memcpy(buffer + 7, "ABC", 3);
	ATF_REQUIRE_EQ(memcmp(buffer + 7, "ABC", 3), 0);

	// 17 bytes unaligned (crosses alignment boundaries)
	memset(buffer, 0, sizeof(buffer));
	ft_memcpy(buffer + 9, "1234567890ABCDEFG", 17);
	ATF_REQUIRE_EQ(memcmp(buffer + 9, "1234567890ABCDEFG", 17), 0);
}

ATF_TC(test_11_unaligned_end_of_buffer);
ATF_TC_HEAD(test_11_unaligned_end_of_buffer, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test copying to near end of buffer");
}
ATF_TC_BODY(test_11_unaligned_end_of_buffer, tc)
{
	char buffer[20];
	const char *src = "TEST";

	memset(buffer, 'X', sizeof(buffer));
	ft_memcpy(buffer + 16, src, 4);

	ATF_REQUIRE_EQ(memcmp(buffer + 16, "TEST", 4), 0);
}

ATF_TC(test_12_unaligned_single_byte_offset);
ATF_TC_HEAD(test_12_unaligned_single_byte_offset, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test with single byte offset");
}
ATF_TC_BODY(test_12_unaligned_single_byte_offset, tc)
{
	char buffer[30];
	const char *data = "alignment test data";

	memset(buffer, 0, sizeof(buffer));
	ft_memcpy(buffer + 1, data, strlen(data));

	ATF_REQUIRE_EQ(buffer[0], 0);
	ATF_REQUIRE_EQ(memcmp(buffer + 1, data, strlen(data)), 0);
}

ATF_TC(test_13_unaligned_crossing_boundaries);
ATF_TC_HEAD(test_13_unaligned_crossing_boundaries, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test unaligned copy crossing word boundaries");
}
ATF_TC_BODY(test_13_unaligned_crossing_boundaries, tc)
{
	char source[40];
	char dest[40];

	// Fill source with pattern
	for (size_t i = 0; i < sizeof(source); i++)
		source[i] = 'A' + (i % 26);

	memset(dest, 0, sizeof(dest));

	// Copy from offset 3 to offset 5, 20 bytes
	ft_memcpy(dest + 5, source + 3, 20);

	ATF_REQUIRE_EQ(memcmp(dest + 5, source + 3, 20), 0);
}

ATF_TC(test_14_unaligned_all_offsets);
ATF_TC_HEAD(test_14_unaligned_all_offsets, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test all possible single-byte offsets");
}
ATF_TC_BODY(test_14_unaligned_all_offsets, tc)
{
	char buffer[50];
	const char *pattern = "0123456789ABCDEF";
	size_t pattern_len = strlen(pattern);

	// Test offsets 0-15
	for (int offset = 0; offset < 16; offset++)
	{
		memset(buffer, 'X', sizeof(buffer));
		ft_memcpy(buffer + offset, pattern, pattern_len);
		ATF_REQUIRE_EQ(memcmp(buffer + offset, pattern, pattern_len), 0);
	}
}

ATF_TC(test_15_unaligned_binary_data);
ATF_TC_HEAD(test_15_unaligned_binary_data, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test unaligned copy with binary data (including nulls)");
}
ATF_TC_BODY(test_15_unaligned_binary_data, tc)
{
	unsigned char source[20] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
		0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
	unsigned char dest[30];

	memset(dest, 0, sizeof(dest));
	ft_memcpy(dest + 11, source, 16);

	ATF_REQUIRE_EQ(memcmp(dest + 11, source, 16), 0);
}

// TEST PROGRAM
ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test00);
	ATF_TP_ADD_TC(tp, test01);
	ATF_TP_ADD_TC(tp, test02);
	ATF_TP_ADD_TC(tp, test03);
	ATF_TP_ADD_TC(tp, test04);
	ATF_TP_ADD_TC(tp, test05);
	ATF_TP_ADD_TC(tp, test_06_unaligned_destination);
    ATF_TP_ADD_TC(tp, test_07_unaligned_source);
    ATF_TP_ADD_TC(tp, test_08_both_unaligned);
    ATF_TP_ADD_TC(tp, test_09_unaligned_odd_offset);
    ATF_TP_ADD_TC(tp, test_10_unaligned_various_sizes);
    ATF_TP_ADD_TC(tp, test_11_unaligned_end_of_buffer);
    ATF_TP_ADD_TC(tp, test_12_unaligned_single_byte_offset);
    ATF_TP_ADD_TC(tp, test_13_unaligned_crossing_boundaries);
    ATF_TP_ADD_TC(tp, test_14_unaligned_all_offsets);
    ATF_TP_ADD_TC(tp, test_15_unaligned_binary_data);

	return (atf_no_error());
}
