/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_ultoa_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:45:03 by joesanto          #+#    #+#             */
/*   Updated: 2026/01/28 21:47:03 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atf-c.h>
#include <string.h>
#include "../libft.h"

ATF_TC(test_basic_conversion);
ATF_TC_HEAD(test_basic_conversion, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test basic number to string conversion");
}
ATF_TC_BODY(test_basic_conversion, tc)
{
	char buffer[20];
	size_t result;

	result = ft_buffer_ultoa(123, sizeof(buffer), buffer);
	ATF_REQUIRE_EQ(result, 3);
	ATF_REQUIRE_STREQ(buffer, "123");

	result = ft_buffer_ultoa(0, sizeof(buffer), buffer);
	ATF_REQUIRE_EQ(result, 1);
	ATF_REQUIRE_STREQ(buffer, "0");

	result = ft_buffer_ultoa(42, sizeof(buffer), buffer);
	ATF_REQUIRE_EQ(result, 2);
	ATF_REQUIRE_STREQ(buffer, "42");
}

ATF_TC(test_large_numbers);
ATF_TC_HEAD(test_large_numbers, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test large number conversions");
}
ATF_TC_BODY(test_large_numbers, tc)
{
	char buffer[30];
	size_t result;

	result = ft_buffer_ultoa(1234567890, sizeof(buffer), buffer);
	ATF_REQUIRE_EQ(result, 10);
	ATF_REQUIRE_STREQ(buffer, "1234567890");

	result = ft_buffer_ultoa(999999999, sizeof(buffer), buffer);
	ATF_REQUIRE_EQ(result, 9);
	ATF_REQUIRE_STREQ(buffer, "999999999");
}

ATF_TC(test_exact_buffer_size);
ATF_TC_HEAD(test_exact_buffer_size, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test when buffer size equals number length + 1");
}
ATF_TC_BODY(test_exact_buffer_size, tc)
{
	char buffer[4];
	size_t result;

	result = ft_buffer_ultoa(123, 4, buffer);
	ATF_REQUIRE_EQ(result, 3);
	ATF_REQUIRE_STREQ(buffer, "123");

	char buffer2[2];
	result = ft_buffer_ultoa(5, 2, buffer2);
	ATF_REQUIRE_EQ(result, 1);
	ATF_REQUIRE_STREQ(buffer2, "5");
}

ATF_TC(test_buffer_too_small);
ATF_TC_HEAD(test_buffer_too_small, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test truncation when buffer is too small");
}
ATF_TC_BODY(test_buffer_too_small, tc)
{
	char buffer[4];
	size_t result;

	// 12345 needs 6 bytes (5 digits + null), but buffer is only 4
	result = ft_buffer_ultoa(12345, 4, buffer);
	ATF_REQUIRE_EQ(result, 5);  // Still returns full number length
	ATF_REQUIRE_EQ(strlen(buffer), 3);  // Only 3 chars fit (+ null)
	ATF_REQUIRE_STREQ(buffer, "123");  // Truncated from the right

	char buffer2[3];
	result = ft_buffer_ultoa(9999, 3, buffer2);
	ATF_REQUIRE_EQ(result, 4);
	ATF_REQUIRE_STREQ(buffer2, "99");
}

ATF_TC(test_buffer_size_one);
ATF_TC_HEAD(test_buffer_size_one, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test with buffer size of 1 (should return 0)");
}
ATF_TC_BODY(test_buffer_size_one, tc)
{
	char buffer[1];
	size_t result;

	result = ft_buffer_ultoa(123, 1, buffer);
	ATF_REQUIRE_EQ(result, 0);
}

ATF_TC(test_buffer_size_zero);
ATF_TC_HEAD(test_buffer_size_zero, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test with buffer size of 0 (should return 0)");
}
ATF_TC_BODY(test_buffer_size_zero, tc)
{
	char buffer[1];
	size_t result;

	result = ft_buffer_ultoa(123, 0, buffer);
	ATF_REQUIRE_EQ(result, 0);
}

ATF_TC(test_single_digit_truncation);
ATF_TC_HEAD(test_single_digit_truncation, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test truncation with single digit visible");
}
ATF_TC_BODY(test_single_digit_truncation, tc)
{
	char buffer[2];
	size_t result;

	result = ft_buffer_ultoa(987654, 2, buffer);
	ATF_REQUIRE_EQ(result, 6);
	ATF_REQUIRE_STREQ(buffer, "9");
}

ATF_TC(test_powers_of_ten);
ATF_TC_HEAD(test_powers_of_ten, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test powers of 10");
}
ATF_TC_BODY(test_powers_of_ten, tc)
{
	char buffer[20];
	size_t result;

	result = ft_buffer_ultoa(10, sizeof(buffer), buffer);
	ATF_REQUIRE_EQ(result, 2);
	ATF_REQUIRE_STREQ(buffer, "10");

	result = ft_buffer_ultoa(100, sizeof(buffer), buffer);
	ATF_REQUIRE_EQ(result, 3);
	ATF_REQUIRE_STREQ(buffer, "100");

	result = ft_buffer_ultoa(1000, sizeof(buffer), buffer);
	ATF_REQUIRE_EQ(result, 4);
	ATF_REQUIRE_STREQ(buffer, "1000");
}

ATF_TC(test_buffer_larger_than_needed);
ATF_TC_HEAD(test_buffer_larger_than_needed, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test when buffer is much larger than needed");
}
ATF_TC_BODY(test_buffer_larger_than_needed, tc)
{
	char buffer[100];
	size_t result;

	memset(buffer, 'X', sizeof(buffer));
	result = ft_buffer_ultoa(42, sizeof(buffer), buffer);
	ATF_REQUIRE_EQ(result, 2);
	ATF_REQUIRE_STREQ(buffer, "42");
	// Verify only necessary bytes were written
	ATF_REQUIRE_EQ(buffer[0], '4');
	ATF_REQUIRE_EQ(buffer[1], '2');
	ATF_REQUIRE_EQ(buffer[2], '\0');
}

ATF_TC(test_various_truncations);
ATF_TC_HEAD(test_various_truncations, tc)
{
	atf_tc_set_md_var(tc, "descr", "Test various levels of truncation");
}
ATF_TC_BODY(test_various_truncations, tc)
{
	char buffer[5];
	size_t result;

	result = ft_buffer_ultoa(123456789, 5, buffer);
	ATF_REQUIRE_EQ(result, 9);
	ATF_REQUIRE_STREQ(buffer, "1234");

	char buffer2[3];
	result = ft_buffer_ultoa(123456789, 3, buffer2);
	ATF_REQUIRE_EQ(result, 9);
	ATF_REQUIRE_STREQ(buffer2, "12");
}

ATF_TP_ADD_TCS(tp)
{
	ATF_TP_ADD_TC(tp, test_basic_conversion);
	ATF_TP_ADD_TC(tp, test_large_numbers);
	ATF_TP_ADD_TC(tp, test_exact_buffer_size);
	ATF_TP_ADD_TC(tp, test_buffer_too_small);
	ATF_TP_ADD_TC(tp, test_buffer_size_one);
	ATF_TP_ADD_TC(tp, test_buffer_size_zero);
	ATF_TP_ADD_TC(tp, test_single_digit_truncation);
	ATF_TP_ADD_TC(tp, test_powers_of_ten);
	ATF_TP_ADD_TC(tp, test_buffer_larger_than_needed);
	ATF_TP_ADD_TC(tp, test_various_truncations);

	return atf_no_error();
}
