#include "libft.h"

#include <assert.h>
#include <ctype.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int expected_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) ? 1 : 0;
}

static int expected_isdigit(int c)
{
    return ((c >= '0' && c <= '9')) ? 1 : 0;
}

static int expected_isalnum(int c)
{
    return (expected_isalpha(c) || expected_isdigit(c));
}

static int expected_isascii(int c)
{
    return ((c >= 0 && c <= 127)) ? 1 : 0;
}

static int expected_isprint(int c)
{
    return ((c >= 32 && c <= 126)) ? 1 : 0;
}

static void test_char_class(void)
{
    for (int c = -128; c < 128; c++)
    {
        unsigned char uc = (unsigned char)c;
        assert(ft_isalpha(uc) == expected_isalpha(uc));
        assert(ft_isdigit(uc) == expected_isdigit(uc));
        assert(ft_isalnum(uc) == expected_isalnum(uc));
        assert(ft_isascii(uc) == expected_isascii(uc));
        assert(ft_isprint(uc) == expected_isprint(uc));
        assert(ft_toupper(uc) == toupper(uc));
        assert(ft_tolower(uc) == tolower(uc));
    }
}

static void test_memory_and_string_part1(void)
{
    char src1[] = "Hello, world!";
    char dst1[64];
    char ref1[64];

    memset(dst1, 'X', sizeof(dst1));
    memset(ref1, 'X', sizeof(ref1));
    ft_memcpy(dst1, src1, strlen(src1) + 1);
    memcpy(ref1, src1, strlen(src1) + 1);
    assert(memcmp(dst1, ref1, sizeof(dst1)) == 0);

    char src2[] = "0123456789";
    char dst2[32];
    ft_memmove(dst2, src2, 10);
    assert(memcmp(dst2, src2, 10) == 0);

    char s3[] = "abcdef";
    ft_memset(s3, 'z', 3);
    assert(s3[0] == 'z' && s3[1] == 'z' && s3[2] == 'z');

    char s4[] = {0, 1, 2, 3, 4, 0};
    ft_bzero(s4, 2);
    assert(s4[0] == 0 && s4[1] == 0);

    assert(ft_strlen("") == strlen(""));
    assert(ft_strlen("abc") == strlen("abc"));
    assert(ft_strlen("123456789") == strlen("123456789"));

    assert(ft_strncmp("abc", "abd", 3) == strncmp("abc", "abd", 3));
    assert(ft_strncmp("abc", "abc", 3) == 0);
    {
        int a = ft_strncmp("abc", "ab", 5);
        int b = strncmp("abc", "ab", 5);
        assert((a > 0 && b > 0) || (a < 0 && b < 0) || (a == 0 && b == 0));
    }

    assert(ft_strchr("hello", 'l') == strchr("hello", 'l'));
    assert(ft_strrchr("hello", 'l') == strrchr("hello", 'l'));
    assert(ft_strnstr("hello world", "world", 11) == strstr("hello world", "world"));
    assert(ft_strnstr("hello", "x", 5) == NULL);

    char mem[] = {0, 1, 2, 3, 4, 5};
    assert(ft_memchr(mem, 3, sizeof(mem)) == memchr(mem, 3, sizeof(mem)));
    assert(ft_memcmp("abc", "abd", 3) == memcmp("abc", "abd", 3));

    assert(ft_atoi("  -123abc") == atoi("  -123abc"));
    assert(ft_atoi("+42") == atoi("+42"));
    assert(ft_atoi("-2147483648") == atoi("-2147483648"));
    assert(ft_atoi("2147483647") == atoi("2147483647"));
    assert(ft_atoi("0") == atoi("0"));
    assert(ft_atoi("") == atoi(""));

    void *calloc1 = ft_calloc(3, sizeof(int));
    void *calloc2 = calloc(3, sizeof(int));
    assert(calloc1 != NULL && calloc2 != NULL);
    assert(memcmp(calloc1, calloc2, 3 * sizeof(int)) == 0);
    free(calloc1);
    free(calloc2);

    char *dup1 = ft_strdup("abc");
    char *dup2 = strdup("abc");
    assert(strcmp(dup1, dup2) == 0);
    free(dup1);
    free(dup2);

    char dst_lcpy[20] = "xxxx";
    char src_lcpy[] = "abc";
    size_t lcpy_size = ft_strlcpy(dst_lcpy, src_lcpy, sizeof(dst_lcpy));
    assert(lcpy_size == strlen(src_lcpy));
    assert(strcmp(dst_lcpy, "abc") == 0);

    char dst_lcat[20] = "abc";
    char src_lcat[] = "def";
    size_t lcat_size = ft_strlcat(dst_lcat, src_lcat, sizeof(dst_lcat));
    assert(lcat_size == 6);
    assert(strcmp(dst_lcat, "abcdef") == 0);
}

static char add_one_to_char(unsigned int i, char c)
{
    (void)i;
    return ((char)(c + 1));
}

static void increment_char(unsigned int i, char *c)
{
    (void)i;
    *c = (char)(*c + 1);
}

static void test_part2(void)
{
    char *sub = ft_substr("abcdef", 2, 4);
    assert(sub != NULL);
    assert(strcmp(sub, "cdef") == 0);
    free(sub);

    sub = ft_substr("abcdef", 10, 3);
    assert(sub != NULL);
    assert(strcmp(sub, "") == 0);
    free(sub);

    char *join = ft_strjoin("hello", " world");
    assert(strcmp(join, "hello world") == 0);
    free(join);

    char *trim = ft_strtrim("   abc   ", " ");
    assert(strcmp(trim, "abc") == 0);
    free(trim);

    char **split = ft_split("one-two-three", '-');
    assert(split != NULL);
    assert(strcmp(split[0], "one") == 0);
    assert(strcmp(split[1], "two") == 0);
    assert(strcmp(split[2], "three") == 0);
    assert(split[3] == NULL);
    for (int i = 0; split[i] != NULL; i++)
        free(split[i]);
    free(split);

    char *itoa = ft_itoa(-12345);
    assert(strcmp(itoa, "-12345") == 0);
    free(itoa);

    itoa = ft_itoa(INT_MIN);
    assert(strcmp(itoa, "-2147483648") == 0);
    free(itoa);

    char *mapped = ft_strmapi("abc", add_one_to_char);
    assert(strcmp(mapped, "bcd") == 0);
    free(mapped);

    char stri[] = "abc";
    ft_striteri(stri, increment_char);
    assert(strcmp(stri, "bcd") == 0);
}

static void test_edge_cases(void)
{
    char **split = ft_split("", '-');
    assert(split != NULL);
    assert(split[0] != NULL);
    assert(strcmp(split[0], "") == 0);
    assert(split[1] == NULL);
    free(split[0]);
    free(split);

    char haystack[] = "abc";
    char *empty = ft_strnstr(haystack, "", 3);
    assert(empty == haystack);
}

static void test_fd_functions(void)
{
    char path[] = "/tmp/libft_test_XXXXXX";
    int fd = mkstemp(path);
    assert(fd >= 0);

    ft_putchar_fd('A', fd);
    ft_putstr_fd("BC", fd);
    ft_putendl_fd("DE", fd);
    ft_putnbr_fd(-42, fd);
    close(fd);

    int rfd = open(path, O_RDONLY);
    char buffer[64] = {0};
    read(rfd, buffer, sizeof(buffer) - 1);
    close(rfd);
    unlink(path);

    assert(strcmp(buffer, "ABCDE\n-42") == 0);
}

static void *double_int_value(void *content)
{
    int *value = malloc(sizeof(int));
    if (value == NULL)
        return (NULL);
    *value = *(int *)content * 2;
    return ((void *)value);
}

static void test_list(void)
{
    t_list *list = NULL;
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));

    assert(a && b && c);
    *a = 10;
    *b = 20;
    *c = 30;

    ft_lstadd_front(&list, ft_lstnew(a));
    ft_lstadd_back(&list, ft_lstnew(b));
    ft_lstadd_back(&list, ft_lstnew(c));
    assert(ft_lstsize(list) == 3);
    assert(*(int *)ft_lstlast(list)->content == 30);

    t_list *node = list;
    while (node)
    {
        int *value = (int *)node->content;
        *value += 1;
        node = node->next;
    }

    ft_lstclear(&list, free);

    t_list *copy = NULL;
    int *n1 = malloc(sizeof(int));
    int *n2 = malloc(sizeof(int));
    assert(n1 && n2);
    *n1 = 1;
    *n2 = 2;
    ft_lstadd_back(&copy, ft_lstnew(n1));
    ft_lstadd_back(&copy, ft_lstnew(n2));

    t_list *mapped = ft_lstmap(copy, double_int_value, free);
    assert(ft_lstsize(mapped) == 2);
    assert(*(int *)mapped->content == 2);
    assert(*(int *)mapped->next->content == 4);

    ft_lstclear(&mapped, free);
    ft_lstclear(&copy, free);
}

int main(void)
{
    test_char_class();
    test_memory_and_string_part1();
    test_part2();
    test_edge_cases();
    test_fd_functions();
    test_list();
    printf("All Libft tests passed.\n");
    return (0);
}
