/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:02:55 by joesanto          #+#    #+#             */
/*   Updated: 2025/11/03 18:11:15 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atf-c.h>
#include <stddef.h>
#include <string.h>
#include "libft.h"

ATF_TC(swap_integers);
ATF_TC_HEAD(swap_integers, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de inteiros");
}
ATF_TC_BODY(swap_integers, tc)
{
    int a = 42;
    int b = 84;
    
    ft_swap(&a, &b, sizeof(int));
    
    ATF_REQUIRE_EQ(a, 84);
    ATF_REQUIRE_EQ(b, 42);
}

ATF_TC(swap_chars);
ATF_TC_HEAD(swap_chars, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de caracteres");
}
ATF_TC_BODY(swap_chars, tc)
{
    char a = 'A';
    char b = 'Z';
    
    ft_swap(&a, &b, sizeof(char));
    
    ATF_REQUIRE_EQ(a, 'Z');
    ATF_REQUIRE_EQ(b, 'A');
}

ATF_TC(swap_longs);
ATF_TC_HEAD(swap_longs, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de long (8 bytes)");
}
ATF_TC_BODY(swap_longs, tc)
{
    long a = 0x123456789ABCDEF0L;
    long b = 0xFEDCBA9876543210L;
    long original_a = a;
    long original_b = b;
    
    ft_swap(&a, &b, sizeof(long));
    
    ATF_REQUIRE_EQ(a, original_b);
    ATF_REQUIRE_EQ(b, original_a);
}

ATF_TC(swap_strings);
ATF_TC_HEAD(swap_strings, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de arrays de chars");
}
ATF_TC_BODY(swap_strings, tc)
{
    char str1[20] = "Hello";
    char str2[20] = "World";
    
    ft_swap(str1, str2, 6);  // Inclui null terminator
    
    ATF_REQUIRE_STREQ(str1, "World");
    ATF_REQUIRE_STREQ(str2, "Hello");
}

ATF_TC(swap_arrays);
ATF_TC_HEAD(swap_arrays, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de arrays de inteiros");
}
ATF_TC_BODY(swap_arrays, tc)
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 20, 30, 40, 50};
    int expected1[] = {10, 20, 30, 40, 50};
    int expected2[] = {1, 2, 3, 4, 5};
    
    ft_swap(arr1, arr2, sizeof(arr1));
    
    ATF_REQUIRE(memcmp(arr1, expected1, sizeof(arr1)) == 0);
    ATF_REQUIRE(memcmp(arr2, expected2, sizeof(arr2)) == 0);
}

ATF_TC(swap_structs);
ATF_TC_HEAD(swap_structs, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de estruturas");
}
ATF_TC_BODY(swap_structs, tc)
{
    struct {
        int id;
        char name[20];
        double value;
    } s1 = {1, "First", 3.14};
    
    struct {
        int id;
        char name[20];
        double value;
    } s2 = {2, "Second", 2.71};
    
    ft_swap(&s1, &s2, sizeof(s1));
    
    ATF_REQUIRE_EQ(s1.id, 2);
    ATF_REQUIRE_STREQ(s1.name, "Second");
    ATF_REQUIRE_EQ(s1.value, 2.71);
    
    ATF_REQUIRE_EQ(s2.id, 1);
    ATF_REQUIRE_STREQ(s2.name, "First");
    ATF_REQUIRE_EQ(s2.value, 3.14);
}

ATF_TC(swap_large_data);
ATF_TC_HEAD(swap_large_data, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de dados grandes (>8 bytes)");
}
ATF_TC_BODY(swap_large_data, tc)
{
    char data1[100];
    char data2[100];
    char expected1[100];
    char expected2[100];
    size_t i;
    
    // Preenche com padrões
    for (i = 0; i < 100; i++)
    {
        data1[i] = (char)i;
        data2[i] = (char)(100 - i);
        expected1[i] = (char)(100 - i);
        expected2[i] = (char)i;
    }
    
    ft_swap(data1, data2, 100);
    
    ATF_REQUIRE(memcmp(data1, expected1, 100) == 0);
    ATF_REQUIRE(memcmp(data2, expected2, 100) == 0);
}

ATF_TC(swap_single_byte);
ATF_TC_HEAD(swap_single_byte, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de um único byte");
}
ATF_TC_BODY(swap_single_byte, tc)
{
    unsigned char a = 0xAA;
    unsigned char b = 0x55;
    
    ft_swap(&a, &b, 1);
    
    ATF_REQUIRE_EQ(a, 0x55);
    ATF_REQUIRE_EQ(b, 0xAA);
}

ATF_TC(swap_odd_size);
ATF_TC_HEAD(swap_odd_size, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap com tamanho ímpar");
}
ATF_TC_BODY(swap_odd_size, tc)
{
    char data1[7] = "ABCDEF";
    char data2[7] = "123456";
    
    ft_swap(data1, data2, 7);
    
    ATF_REQUIRE_STREQ(data1, "123456");
    ATF_REQUIRE_STREQ(data2, "ABCDEF");
}

ATF_TC(swap_9_bytes);
ATF_TC_HEAD(swap_9_bytes, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de 9 bytes (8 + 1)");
}
ATF_TC_BODY(swap_9_bytes, tc)
{
    char data1[9] = "12345678";
    char data2[9] = "abcdefgh";
    
    ft_swap(data1, data2, 9);
    
    ATF_REQUIRE_STREQ(data1, "abcdefgh");
    ATF_REQUIRE_STREQ(data2, "12345678");
}

ATF_TC(swap_zero_values);
ATF_TC_HEAD(swap_zero_values, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de valores zero");
}
ATF_TC_BODY(swap_zero_values, tc)
{
    int a = 0;
    int b = 42;
    
    ft_swap(&a, &b, sizeof(int));
    
    ATF_REQUIRE_EQ(a, 42);
    ATF_REQUIRE_EQ(b, 0);
}

ATF_TC(swap_same_values);
ATF_TC_HEAD(swap_same_values, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de valores iguais");
}
ATF_TC_BODY(swap_same_values, tc)
{
    int a = 100;
    int b = 100;
    
    ft_swap(&a, &b, sizeof(int));
    
    ATF_REQUIRE_EQ(a, 100);
    ATF_REQUIRE_EQ(b, 100);
}

ATF_TC(swap_binary_data);
ATF_TC_HEAD(swap_binary_data, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de dados binários");
}
ATF_TC_BODY(swap_binary_data, tc)
{
    unsigned char bin1[] = {0x00, 0xFF, 0xAA, 0x55, 0x12, 0x34, 0x56, 0x78};
    unsigned char bin2[] = {0xFF, 0x00, 0x55, 0xAA, 0x87, 0x65, 0x43, 0x21};
    unsigned char exp1[] = {0xFF, 0x00, 0x55, 0xAA, 0x87, 0x65, 0x43, 0x21};
    unsigned char exp2[] = {0x00, 0xFF, 0xAA, 0x55, 0x12, 0x34, 0x56, 0x78};
    
    ft_swap(bin1, bin2, 8);
    
    ATF_REQUIRE(memcmp(bin1, exp1, 8) == 0);
    ATF_REQUIRE(memcmp(bin2, exp2, 8) == 0);
}

ATF_TC(swap_floats);
ATF_TC_HEAD(swap_floats, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de floats");
}
ATF_TC_BODY(swap_floats, tc)
{
    float a = 3.14f;
    float b = 2.71f;
    
    ft_swap(&a, &b, sizeof(float));
    
    ATF_REQUIRE_EQ(a, 2.71f);
    ATF_REQUIRE_EQ(b, 3.14f);
}

ATF_TC(swap_doubles);
ATF_TC_HEAD(swap_doubles, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de doubles");
}
ATF_TC_BODY(swap_doubles, tc)
{
    double a = 3.141592653589793;
    double b = 2.718281828459045;
    
    ft_swap(&a, &b, sizeof(double));
    
    ATF_REQUIRE_EQ(a, 2.718281828459045);
    ATF_REQUIRE_EQ(b, 3.141592653589793);
}

ATF_TC(swap_pointers);
ATF_TC_HEAD(swap_pointers, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de ponteiros");
}
ATF_TC_BODY(swap_pointers, tc)
{
    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;
    
    ft_swap(&p1, &p2, sizeof(int *));
    
    ATF_REQUIRE_EQ(p1, &y);
    ATF_REQUIRE_EQ(p2, &x);
    ATF_REQUIRE_EQ(*p1, 20);
    ATF_REQUIRE_EQ(*p2, 10);
}

ATF_TC(swap_exactly_8_bytes);
ATF_TC_HEAD(swap_exactly_8_bytes, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de exatamente 8 bytes");
}
ATF_TC_BODY(swap_exactly_8_bytes, tc)
{
    unsigned long a = 0x0123456789ABCDEFUL;
    unsigned long b = 0xFEDCBA9876543210UL;
    
    ft_swap(&a, &b, 8);
    
    ATF_REQUIRE_EQ(a, 0xFEDCBA9876543210UL);
    ATF_REQUIRE_EQ(b, 0x0123456789ABCDEFUL);
}

ATF_TC(swap_16_bytes);
ATF_TC_HEAD(swap_16_bytes, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa swap de 16 bytes (duas iterações de 8)");
}
ATF_TC_BODY(swap_16_bytes, tc)
{
    char data1[16] = "0123456789ABCDE";
    char data2[16] = "FEDCBA987654321";
    
    ft_swap(data1, data2, 16);
    
    ATF_REQUIRE_STREQ(data1, "FEDCBA987654321");
    ATF_REQUIRE_STREQ(data2, "0123456789ABCDE");
}

ATF_TP_ADD_TCS(tp)
{
    ATF_TP_ADD_TC(tp, swap_integers);
    ATF_TP_ADD_TC(tp, swap_chars);
    ATF_TP_ADD_TC(tp, swap_longs);
    ATF_TP_ADD_TC(tp, swap_strings);
    ATF_TP_ADD_TC(tp, swap_arrays);
    ATF_TP_ADD_TC(tp, swap_structs);
    ATF_TP_ADD_TC(tp, swap_large_data);
    ATF_TP_ADD_TC(tp, swap_single_byte);
    ATF_TP_ADD_TC(tp, swap_odd_size);
    ATF_TP_ADD_TC(tp, swap_9_bytes);
    ATF_TP_ADD_TC(tp, swap_zero_values);
    ATF_TP_ADD_TC(tp, swap_same_values);
    ATF_TP_ADD_TC(tp, swap_binary_data);
    ATF_TP_ADD_TC(tp, swap_floats);
    ATF_TP_ADD_TC(tp, swap_doubles);
    ATF_TP_ADD_TC(tp, swap_pointers);
    ATF_TP_ADD_TC(tp, swap_exactly_8_bytes);
    ATF_TP_ADD_TC(tp, swap_16_bytes);

    return atf_no_error();
}
