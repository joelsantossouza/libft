/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 00:03:20 by joesanto          #+#    #+#             */
/*   Updated: 2025/11/02 00:14:18 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atf-c.h>
#include <limits.h>
#include <stddef.h>
#include "libft.h"

// Prototipo da função a testar
ATF_TC(atoh_basic_hex);
ATF_TC_HEAD(atoh_basic_hex, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa conversão hexadecimal básica");
}
ATF_TC_BODY(atoh_basic_hex, tc)
{
    char *end;
    
    ATF_REQUIRE_EQ(ft_atoh("0", &end), 0L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("1", &end), 1L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("a", &end), 10L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("f", &end), 15L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("10", &end), 16L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("ff", &end), 255L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("100", &end), 256L);
    ATF_REQUIRE_EQ(*end, '\0');
}

ATF_TC(atoh_uppercase);
ATF_TC_HEAD(atoh_uppercase, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa letras maiúsculas");
}
ATF_TC_BODY(atoh_uppercase, tc)
{
    char *end;
    
    ATF_REQUIRE_EQ(ft_atoh("A", &end), 10L);
    ATF_REQUIRE_EQ(ft_atoh("F", &end), 15L);
    ATF_REQUIRE_EQ(ft_atoh("FF", &end), 255L);
    ATF_REQUIRE_EQ(ft_atoh("DeAdBeEf", &end), 0xDEADBEEFL);
    ATF_REQUIRE_EQ(*end, '\0');
}

ATF_TC(atoh_mixed_case);
ATF_TC_HEAD(atoh_mixed_case, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa mistura de maiúsculas e minúsculas");
}
ATF_TC_BODY(atoh_mixed_case, tc)
{
    char *end;
    
    ATF_REQUIRE_EQ(ft_atoh("aB", &end), 171L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("CdEf", &end), 0xCDEFL);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("1a2B3c", &end), 0x1A2B3CL);
    ATF_REQUIRE_EQ(*end, '\0');
}

ATF_TC(atoh_prefix_0x);
ATF_TC_HEAD(atoh_prefix_0x, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa com e sem prefixo 0x/0X");
}
ATF_TC_BODY(atoh_prefix_0x, tc)
{
    char *end;
    
    // Com prefixo 0x
    ATF_REQUIRE_EQ(ft_atoh("0x10", &end), 16L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("0xff", &end), 255L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("0X1A", &end), 26L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("0xDEADBEEF", &end), 0xDEADBEEFL);
    ATF_REQUIRE_EQ(*end, '\0');
    
    // Sem prefixo - deve funcionar igual
    ATF_REQUIRE_EQ(ft_atoh("10", &end), 16L);
    ATF_REQUIRE_EQ(ft_atoh("ff", &end), 255L);
    ATF_REQUIRE_EQ(ft_atoh("1A", &end), 26L);
    ATF_REQUIRE_EQ(ft_atoh("DEADBEEF", &end), 0xDEADBEEFL);
    
    // Prefixo com sinal
    ATF_REQUIRE_EQ(ft_atoh("+0xff", &end), 255L);
    ATF_REQUIRE_EQ(ft_atoh("-0x10", &end), -16L);
}

ATF_TC(atoh_whitespace);
ATF_TC_HEAD(atoh_whitespace, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa com espaços em branco iniciais");
}
ATF_TC_BODY(atoh_whitespace, tc)
{
    char *end;
    
    ATF_REQUIRE_EQ(ft_atoh("  10", &end), 16L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("\t\nff", &end), 255L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("   0x1a", &end), 26L);
    ATF_REQUIRE_EQ(*end, '\0');
}

ATF_TC(atoh_endptr_invalid);
ATF_TC_HEAD(atoh_endptr_invalid, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa endptr com caracteres inválidos");
}
ATF_TC_BODY(atoh_endptr_invalid, tc)
{
    char *end;
    const char *str;
    
    str = "ffg";
    ATF_REQUIRE_EQ(ft_atoh(str, &end), 255L);
    ATF_REQUIRE_EQ(end, str + 2);  // Aponta para 'g'
    ATF_REQUIRE_EQ(*end, 'g');
    
    str = "1234xyz";
    ATF_REQUIRE_EQ(ft_atoh(str, &end), 0x1234L);
    ATF_REQUIRE_EQ(end, str + 4);  // Aponta para 'x'
    ATF_REQUIRE_EQ(*end, 'x');
    
    str = "abc def";
    ATF_REQUIRE_EQ(ft_atoh(str, &end), 0xABCL);
    ATF_REQUIRE_EQ(end, str + 3);  // Aponta para ' '
    ATF_REQUIRE_EQ(*end, ' ');
    
    str = "0x10!";
    ATF_REQUIRE_EQ(ft_atoh(str, &end), 16L);
    ATF_REQUIRE_EQ(*end, '!');
}

ATF_TC(atoh_endptr_null);
ATF_TC_HEAD(atoh_endptr_null, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa com endptr NULL");
}
ATF_TC_BODY(atoh_endptr_null, tc)
{
    // Deve funcionar sem crashar
    ATF_REQUIRE_EQ(ft_atoh("ff", NULL), 255L);
    ATF_REQUIRE_EQ(ft_atoh("0x10", NULL), 16L);
    ATF_REQUIRE_EQ(ft_atoh("123", NULL), 0x123L);
}

ATF_TC(atoh_edge_cases);
ATF_TC_HEAD(atoh_edge_cases, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa casos extremos");
}
ATF_TC_BODY(atoh_edge_cases, tc)
{
    char *end;
    const char *str;
    
    str = "";
    ATF_REQUIRE_EQ(ft_atoh(str, &end), 0L);
    ATF_REQUIRE_EQ(end, str);  // endptr não deve avançar
    
    str = "0x";
    ATF_REQUIRE_EQ(ft_atoh(str, &end), 0L);
    // endptr pode apontar para 'x' ou para str, depende da implementação
    
    str = "   ";
    ATF_REQUIRE_EQ(ft_atoh(str, &end), 0L);
    
    str = "xyz";
    ATF_REQUIRE_EQ(ft_atoh(str, &end), 0L);
    ATF_REQUIRE_EQ(end, str);  // Nenhum dígito válido
}

ATF_TC(atoh_large_numbers);
ATF_TC_HEAD(atoh_large_numbers, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa números grandes");
}
ATF_TC_BODY(atoh_large_numbers, tc)
{
    char *end;
    
    ATF_REQUIRE_EQ(ft_atoh("7fffffff", &end), 0x7FFFFFFFL);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("12345678", &end), 0x12345678L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    // Se for 64-bit
    if (sizeof(long) == 8)
    {
        ATF_REQUIRE_EQ(ft_atoh("7fffffffffffffff", &end), 0x7FFFFFFFFFFFFFFFL);
        ATF_REQUIRE_EQ(*end, '\0');
    }
}

ATF_TC(atoh_with_sign);
ATF_TC_HEAD(atoh_with_sign, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa com sinais (+ e -)");
}
ATF_TC_BODY(atoh_with_sign, tc)
{
    char *end;
    
    ATF_REQUIRE_EQ(ft_atoh("+10", &end), 16L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("+ff", &end), 255L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("+0x1a", &end), 26L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    // Números negativos - agora retornam valores negativos!
    ATF_REQUIRE_EQ(ft_atoh("-1", &end), -1L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("-10", &end), -16L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("-ff", &end), -255L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("-0xff", &end), -255L);
    ATF_REQUIRE_EQ(*end, '\0');
    
    ATF_REQUIRE_EQ(ft_atoh("-0x10", &end), -16L);
    ATF_REQUIRE_EQ(*end, '\0');
}

ATF_TC(atoh_negative_values);
ATF_TC_HEAD(atoh_negative_values, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa valores negativos signed");
}
ATF_TC_BODY(atoh_negative_values, tc)
{
    char *end;
    
    // Valores negativos devem retornar números negativos
    ATF_REQUIRE_EQ(ft_atoh("-1", &end), -1L);
    ATF_REQUIRE(ft_atoh("-1", &end) < 0);
    
    ATF_REQUIRE_EQ(ft_atoh("-0x10", &end), -16L);
    ATF_REQUIRE(ft_atoh("-0x10", &end) < 0);
    
    ATF_REQUIRE_EQ(ft_atoh("-a", &end), -10L);
    ATF_REQUIRE(ft_atoh("-a", &end) < 0);
    
    // Testa comparação: valor negativo < valor positivo
    ATF_REQUIRE(ft_atoh("-ff", NULL) < ft_atoh("ff", NULL));
    ATF_REQUIRE(ft_atoh("-10", NULL) < ft_atoh("10", NULL));
}

ATF_TC(atoh_endptr_consistency);
ATF_TC_HEAD(atoh_endptr_consistency, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa consistência do endptr");
}
ATF_TC_BODY(atoh_endptr_consistency, tc)
{
    char *end;
    const char *str;
    
    // Conversão completa
    str = "abc";
    ft_atoh(str, &end);
    ATF_REQUIRE_EQ(end, str + 3);
    
    // Conversão parcial
    str = "12g34";
    ft_atoh(str, &end);
    ATF_REQUIRE_EQ(end, str + 2);
    
    // Sem conversão
    str = "xyz";
    ft_atoh(str, &end);
    ATF_REQUIRE_EQ(end, str);
    
    // Com whitespace inicial
    str = "  ff";
    ft_atoh(str, &end);
    ATF_REQUIRE_EQ(end, str + 4);
}

ATF_TP_ADD_TCS(tp)
{
    ATF_TP_ADD_TC(tp, atoh_basic_hex);
    ATF_TP_ADD_TC(tp, atoh_uppercase);
    ATF_TP_ADD_TC(tp, atoh_mixed_case);
    ATF_TP_ADD_TC(tp, atoh_prefix_0x);
    ATF_TP_ADD_TC(tp, atoh_whitespace);
    ATF_TP_ADD_TC(tp, atoh_endptr_invalid);
    ATF_TP_ADD_TC(tp, atoh_endptr_null);
    ATF_TP_ADD_TC(tp, atoh_edge_cases);
    ATF_TP_ADD_TC(tp, atoh_large_numbers);
    ATF_TP_ADD_TC(tp, atoh_with_sign);
    ATF_TP_ADD_TC(tp, atoh_negative_values);
    ATF_TP_ADD_TC(tp, atoh_endptr_consistency);

    return atf_no_error();
}
