/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:34:30 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/03 11:35:53 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atf-c.h>
#include "libft.h"

ATF_TC(test_equal_numbers);
ATF_TC_HEAD(test_equal_numbers, tc)
{
    atf_tc_set_md_var(tc, "descr", "Test equal numbers");
}
ATF_TC_BODY(test_equal_numbers, tc)
{
    ATF_REQUIRE_EQ(ft_nbrcmp("42", "42"), 0);
    ATF_REQUIRE_EQ(ft_nbrcmp("0", "0"), 0);
    ATF_REQUIRE_EQ(ft_nbrcmp("123", "123"), 0);
}

ATF_TC(test_with_leading_zeros);
ATF_TC_HEAD(test_with_leading_zeros, tc)
{
    atf_tc_set_md_var(tc, "descr", "Test numbers with leading zeros");
}
ATF_TC_BODY(test_with_leading_zeros, tc)
{
    ATF_REQUIRE_EQ(ft_nbrcmp("042", "42"), 0);
    ATF_REQUIRE_EQ(ft_nbrcmp("0000123", "123"), 0);
    ATF_REQUIRE_EQ(ft_nbrcmp("00", "0"), 0);
}

ATF_TC(test_with_whitespace);
ATF_TC_HEAD(test_with_whitespace, tc)
{
    atf_tc_set_md_var(tc, "descr", "Test numbers with leading whitespace");
}
ATF_TC_BODY(test_with_whitespace, tc)
{
    ATF_REQUIRE_EQ(ft_nbrcmp("  42", "42"), 0);
    ATF_REQUIRE_EQ(ft_nbrcmp("\t\n\r42", "42"), 0);
    ATF_REQUIRE_EQ(ft_nbrcmp("   123", "  123"), 0);
}

ATF_TC(test_with_signs);
ATF_TC_HEAD(test_with_signs, tc)
{
    atf_tc_set_md_var(tc, "descr", "Test numbers with + and - signs");
}
ATF_TC_BODY(test_with_signs, tc)
{
    ATF_REQUIRE_EQ(ft_nbrcmp("+42", "42"), 0);
    ATF_REQUIRE_EQ(ft_nbrcmp("+42", "+42"), 0);
    ATF_REQUIRE_EQ(ft_nbrcmp("-42", "-42"), 0);
    ATF_REQUIRE(ft_nbrcmp("-42", "42") < 0);
    ATF_REQUIRE(ft_nbrcmp("42", "-42") > 0);
    ATF_REQUIRE(ft_nbrcmp("+42", "-42") > 0);
}

ATF_TC(test_different_lengths);
ATF_TC_HEAD(test_different_lengths, tc)
{
    atf_tc_set_md_var(tc, "descr", "Test numbers with different lengths");
}
ATF_TC_BODY(test_different_lengths, tc)
{
    ATF_REQUIRE(ft_nbrcmp("100", "99") > 0);
    ATF_REQUIRE(ft_nbrcmp("1", "1000") < 0);
    ATF_REQUIRE(ft_nbrcmp("999", "1000") < 0);
}

ATF_TC(test_same_length_different_values);
ATF_TC_HEAD(test_same_length_different_values, tc)
{
    atf_tc_set_md_var(tc, "descr", "Test numbers with same length but different values");
}
ATF_TC_BODY(test_same_length_different_values, tc)
{
    ATF_REQUIRE(ft_nbrcmp("123", "124") < 0);
    ATF_REQUIRE(ft_nbrcmp("456", "455") > 0);
    ATF_REQUIRE(ft_nbrcmp("999", "998") > 0);
}

ATF_TC(test_negative_numbers);
ATF_TC_HEAD(test_negative_numbers, tc)
{
    atf_tc_set_md_var(tc, "descr", "Test negative numbers comparison");
}
ATF_TC_BODY(test_negative_numbers, tc)
{
    ATF_REQUIRE(ft_nbrcmp("-100", "-99") < 0);
    ATF_REQUIRE(ft_nbrcmp("-1", "-1000") > 0);
    ATF_REQUIRE(ft_nbrcmp("-123", "-123") == 0);
}

ATF_TC(test_non_numeric_strings);
ATF_TC_HEAD(test_non_numeric_strings, tc)
{
    atf_tc_set_md_var(tc, "descr", "Test non-numeric strings as ASCII comparison");
}
ATF_TC_BODY(test_non_numeric_strings, tc)
{
    ATF_REQUIRE_EQ(ft_nbrcmp("abc", "abc"), 0);
    ATF_REQUIRE(ft_nbrcmp("abc", "abd") < 0);
    ATF_REQUIRE(ft_nbrcmp("xyz", "abc") > 0);
    ATF_REQUIRE(ft_nbrcmp("  abc", "abc") == 0);
}

ATF_TC(test_mixed_strings);
ATF_TC_HEAD(test_mixed_strings, tc)
{
    atf_tc_set_md_var(tc, "descr", "Test strings with mixed numeric and non-numeric characters");
}
ATF_TC_BODY(test_mixed_strings, tc)
{
    ATF_REQUIRE_EQ(ft_nbrcmp("123abc", "123abc"), 0);
    ATF_REQUIRE(ft_nbrcmp("123abc", "123xyz") < 0);
    ATF_REQUIRE(ft_nbrcmp("0001abc", "1abc") == 0);
}

ATF_TC(test_empty_and_zero);
ATF_TC_HEAD(test_empty_and_zero, tc)
{
    atf_tc_set_md_var(tc, "descr", "Test empty strings and zeros");
}
ATF_TC_BODY(test_empty_and_zero, tc)
{
    ATF_REQUIRE_EQ(ft_nbrcmp("", ""), 0);
    ATF_REQUIRE_EQ(ft_nbrcmp("0", "00"), 0);
    ATF_REQUIRE_EQ(ft_nbrcmp("000", "0"), 0);
}

ATF_TC(test_complex_cases);
ATF_TC_HEAD(test_complex_cases, tc)
{
    atf_tc_set_md_var(tc, "descr", "Test complex cases with multiple features");
}
ATF_TC_BODY(test_complex_cases, tc)
{
    ATF_REQUIRE_EQ(ft_nbrcmp("  +0042", "42"), 0);
    ATF_REQUIRE_EQ(ft_nbrcmp("\t-00123", "  -123"), 0);
    ATF_REQUIRE(ft_nbrcmp("  +123", "  -123") > 0);
    ATF_REQUIRE(ft_nbrcmp("  0001", "  00010") < 0);
}

ATF_TP_ADD_TCS(tp)
{
    ATF_TP_ADD_TC(tp, test_equal_numbers);
    ATF_TP_ADD_TC(tp, test_with_leading_zeros);
    ATF_TP_ADD_TC(tp, test_with_whitespace);
    ATF_TP_ADD_TC(tp, test_with_signs);
    ATF_TP_ADD_TC(tp, test_different_lengths);
    ATF_TP_ADD_TC(tp, test_same_length_different_values);
    ATF_TP_ADD_TC(tp, test_negative_numbers);
    ATF_TP_ADD_TC(tp, test_non_numeric_strings);
    ATF_TP_ADD_TC(tp, test_mixed_strings);
    ATF_TP_ADD_TC(tp, test_empty_and_zero);
    ATF_TP_ADD_TC(tp, test_complex_cases);

    return atf_no_error();
}
