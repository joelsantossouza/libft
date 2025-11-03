/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:49:14 by joesanto          #+#    #+#             */
/*   Updated: 2025/11/03 09:54:35 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atf-c.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "libft.h"

// Helper para criar arquivo temporário
static char *create_temp_file(const char *content, size_t len)
{
    static char template[] = "/tmp/ft_getfile_test_XXXXXX";
    char *path = strdup(template);
    int fd = mkstemp(path);
    
    if (fd < 0)
    {
        free(path);
        return NULL;
    }
    
    if (content && len > 0)
        write(fd, content, len);
    
    close(fd);
    return path;
}

ATF_TC(getfile_simple_text);
ATF_TC_HEAD(getfile_simple_text, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa leitura de arquivo de texto simples");
}
ATF_TC_BODY(getfile_simple_text, tc)
{
    char *content = NULL;
    const char *expected = "Hello, World!";
    char *path = create_temp_file(expected, strlen(expected));
    ssize_t len;
    
    ATF_REQUIRE(path != NULL);
    
    len = ft_getfile(&content, path);
    
    ATF_REQUIRE(len >= 0);
    ATF_REQUIRE_EQ(len, (ssize_t)strlen(expected));
    ATF_REQUIRE(content != NULL);
    ATF_REQUIRE_STREQ(content, expected);
    
    free(content);
    unlink(path);
    free(path);
}

ATF_TC(getfile_empty_file);
ATF_TC_HEAD(getfile_empty_file, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa leitura de arquivo vazio");
}
ATF_TC_BODY(getfile_empty_file, tc)
{
    char *content = NULL;
    char *path = create_temp_file(NULL, 0);
    ssize_t len;
    
    ATF_REQUIRE(path != NULL);
    
    len = ft_getfile(&content, path);
    
    ATF_REQUIRE_EQ(len, 0);
    ATF_REQUIRE(content == NULL);
    
    free(content);
    unlink(path);
    free(path);
}

ATF_TC(getfile_multiline);
ATF_TC_HEAD(getfile_multiline, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa arquivo com múltiplas linhas");
}
ATF_TC_BODY(getfile_multiline, tc)
{
    char *content = NULL;
    const char *expected = "Line 1\nLine 2\nLine 3\n";
    char *path = create_temp_file(expected, strlen(expected));
    ssize_t len;
    
    ATF_REQUIRE(path != NULL);
    
    len = ft_getfile(&content, path);
    
    ATF_REQUIRE(len >= 0);
    ATF_REQUIRE_EQ(len, (ssize_t)strlen(expected));
    ATF_REQUIRE(content != NULL);
    ATF_REQUIRE_STREQ(content, expected);
    
    free(content);
    unlink(path);
    free(path);
}

ATF_TC(getfile_binary_data);
ATF_TC_HEAD(getfile_binary_data, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa leitura de dados binários (com zeros)");
}
ATF_TC_BODY(getfile_binary_data, tc)
{
    char *content = NULL;
    unsigned char binary[] = {0x00, 0x01, 0x02, 0xFF, 0xFE, 0x00, 0x42};
    size_t binary_len = sizeof(binary);
    char *path = create_temp_file((char *)binary, binary_len);
    ssize_t len;
    
    ATF_REQUIRE(path != NULL);
    
    len = ft_getfile(&content, path);
    
    ATF_REQUIRE(len >= 0);
    ATF_REQUIRE_EQ(len, (ssize_t)binary_len);
    ATF_REQUIRE(content != NULL);
    ATF_REQUIRE(memcmp(content, binary, binary_len) == 0);
    ATF_REQUIRE_EQ((unsigned char)content[binary_len], 0);  // Null terminator
    
    free(content);
    unlink(path);
    free(path);
}

ATF_TC(getfile_large_file);
ATF_TC_HEAD(getfile_large_file, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa arquivo maior que BUFFER_SIZE");
}
ATF_TC_BODY(getfile_large_file, tc)
{
    char *content = NULL;
    size_t size = 100000;  // 100KB - maior que buffer típico
    char *large_data = malloc(size);
    char *path;
    ssize_t len;
    size_t i;
    
    ATF_REQUIRE(large_data != NULL);
    
    // Preenche com padrão reconhecível
    for (i = 0; i < size; i++)
        large_data[i] = (char)('A' + (i % 26));
    
    path = create_temp_file(large_data, size);
    ATF_REQUIRE(path != NULL);
    
    len = ft_getfile(&content, path);
    
    ATF_REQUIRE(len >= 0);
    ATF_REQUIRE_EQ(len, (ssize_t)size);
    ATF_REQUIRE(content != NULL);
    ATF_REQUIRE(memcmp(content, large_data, size) == 0);
    ATF_REQUIRE_EQ(content[size], '\0');
    
    free(content);
    free(large_data);
    unlink(path);
    free(path);
}

ATF_TC(getfile_nonexistent);
ATF_TC_HEAD(getfile_nonexistent, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa arquivo que não existe");
}
ATF_TC_BODY(getfile_nonexistent, tc)
{
    char *content = NULL;
    ssize_t len;
    
    len = ft_getfile(&content, "/tmp/this_file_does_not_exist_123456789");
    
    ATF_REQUIRE_EQ(len, -1);
}

ATF_TC(getfile_no_permissions);
ATF_TC_HEAD(getfile_no_permissions, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa arquivo sem permissões de leitura");
}
ATF_TC_BODY(getfile_no_permissions, tc)
{
    char *content = NULL;
    char *path = create_temp_file("test", 4);
    ssize_t len;
    
    ATF_REQUIRE(path != NULL);
    
    // Remove permissões de leitura
    chmod(path, 0000);
    
    len = ft_getfile(&content, path);
    
    ATF_REQUIRE_EQ(len, -1);
    
    // Restaura permissões para deletar
    chmod(path, 0644);
    unlink(path);
    free(path);
}

ATF_TC(getfile_special_chars);
ATF_TC_HEAD(getfile_special_chars, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa arquivo com caracteres especiais");
}
ATF_TC_BODY(getfile_special_chars, tc)
{
    char *content = NULL;
    const char *expected = "Tab:\t\nNewline:\n\rCarriage:\rNull after:X\0YZ";
    size_t len_with_null = 28;  // Inclui o \0 no meio
    char *path = create_temp_file(expected, len_with_null);
    ssize_t len;
    
    ATF_REQUIRE(path != NULL);
    
    len = ft_getfile(&content, path);
    
    ATF_REQUIRE(len >= 0);
    ATF_REQUIRE_EQ(len, (ssize_t)len_with_null);
    ATF_REQUIRE(content != NULL);
    ATF_REQUIRE(memcmp(content, expected, len_with_null) == 0);
    
    free(content);
    unlink(path);
    free(path);
}

ATF_TC(getfile_reuse_pointer);
ATF_TC_HEAD(getfile_reuse_pointer, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa reutilização do ponteiro fileptr");
}
ATF_TC_BODY(getfile_reuse_pointer, tc)
{
    char *content = malloc(100);  // Memória pré-alocada
    const char *expected1 = "First file";
    const char *expected2 = "Second file content";
    char *path1 = create_temp_file(expected1, strlen(expected1));
    char *path2 = create_temp_file(expected2, strlen(expected2));
    ssize_t len;
    
    ATF_REQUIRE(path1 != NULL);
    ATF_REQUIRE(path2 != NULL);
    ATF_REQUIRE(content != NULL);
    
    // Primeira leitura
    len = ft_getfile(&content, path1);
    ATF_REQUIRE(len >= 0);
    ATF_REQUIRE_STREQ(content, expected1);
    
    // Segunda leitura - deve realocar/liberar memória antiga
    len = ft_getfile(&content, path2);
    ATF_REQUIRE(len >= 0);
    ATF_REQUIRE_STREQ(content, expected2);
    
    free(content);
    unlink(path1);
    unlink(path2);
    free(path1);
    free(path2);
}

ATF_TC(getfile_null_termination);
ATF_TC_HEAD(getfile_null_termination, tc)
{
    atf_tc_set_md_var(tc, "descr", "Verifica que o conteúdo é null-terminated");
}
ATF_TC_BODY(getfile_null_termination, tc)
{
    char *content = NULL;
    const char *expected = "Test content";
    char *path = create_temp_file(expected, strlen(expected));
    ssize_t len;
    
    ATF_REQUIRE(path != NULL);
    
    len = ft_getfile(&content, path);
    
    ATF_REQUIRE(len >= 0);
    ATF_REQUIRE(content != NULL);
    ATF_REQUIRE_EQ(content[len], '\0');  // Verifica null terminator
    ATF_REQUIRE_EQ(strlen(content), (size_t)len);  // strlen deve bater
    
    free(content);
    unlink(path);
    free(path);
}

ATF_TC(getfile_single_byte);
ATF_TC_HEAD(getfile_single_byte, tc)
{
    atf_tc_set_md_var(tc, "descr", "Testa arquivo com um único byte");
}
ATF_TC_BODY(getfile_single_byte, tc)
{
    char *content = NULL;
    const char expected[] = "X";
    char *path = create_temp_file(expected, 1);
    ssize_t len;
    
    ATF_REQUIRE(path != NULL);
    
    len = ft_getfile(&content, path);
    
    ATF_REQUIRE_EQ(len, 1);
    ATF_REQUIRE(content != NULL);
    ATF_REQUIRE_EQ(content[0], 'X');
    ATF_REQUIRE_EQ(content[1], '\0');
    
    free(content);
    unlink(path);
    free(path);
}

ATF_TP_ADD_TCS(tp)
{
    ATF_TP_ADD_TC(tp, getfile_simple_text);
    ATF_TP_ADD_TC(tp, getfile_empty_file);
    ATF_TP_ADD_TC(tp, getfile_multiline);
    ATF_TP_ADD_TC(tp, getfile_binary_data);
    ATF_TP_ADD_TC(tp, getfile_large_file);
    ATF_TP_ADD_TC(tp, getfile_nonexistent);
    ATF_TP_ADD_TC(tp, getfile_no_permissions);
    ATF_TP_ADD_TC(tp, getfile_special_chars);
    ATF_TP_ADD_TC(tp, getfile_reuse_pointer);
    ATF_TP_ADD_TC(tp, getfile_null_termination);
    ATF_TP_ADD_TC(tp, getfile_single_byte);

    return atf_no_error();
}
