/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_libc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 00:28:37 by laraus            #+#    #+#             */
/*   Updated: 2026/05/09 08:38:37 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

static void	test_chars(void)
{
	test_header("CHARACTER FUNCTIONS");
	check_bool("ft_isalpha('A')", ft_isalpha('A'), isalpha('A'));
	check_bool("ft_isalpha('z')", ft_isalpha('z'), isalpha('z'));
	check_bool("ft_isalpha('1')", ft_isalpha('1'), isalpha('1'));
	check_bool("ft_isalpha(EOF)", ft_isalpha(EOF), isalpha(EOF));
	check_bool("ft_isdigit('7')", ft_isdigit('7'), isdigit('7'));
	check_bool("ft_isdigit('a')", ft_isdigit('a'), isdigit('a'));
	check_bool("ft_isalnum('z')", ft_isalnum('z'), isalnum('z'));
	check_bool("ft_isascii(127)", ft_isascii(127), isascii(127));
	check_bool("ft_isascii(128)", ft_isascii(128), isascii(128));
	check_bool("ft_isprint(' ')", ft_isprint(' '), isprint(' '));
	check_bool("ft_isprint('\\n')", ft_isprint('\n'), isprint('\n'));
	check_int("ft_toupper('a')", ft_toupper('a'), toupper('a'));
	check_int("ft_toupper('A')", ft_toupper('A'), toupper('A'));
	check_int("ft_tolower('Z')", ft_tolower('Z'), tolower('Z'));
	check_int("ft_tolower('z')", ft_tolower('z'), tolower('z'));
}

static void	test_strings(void)
{
	char	*dup;

	test_header("STRING FUNCTIONS");
	check_size("ft_strlen hello", ft_strlen("hello"), strlen("hello"));
	check_size("ft_strlen empty", ft_strlen(""), strlen(""));
	check_int("ft_strncmp same", ft_strncmp("abc", "abc", 3),
		strncmp("abc", "abc", 3));
	check_int("ft_strncmp n=0", ft_strncmp("abc", "xyz", 0),
		strncmp("abc", "xyz", 0));
	check_int("ft_strncmp diff", ft_strncmp("abc", "abd", 3),
		strncmp("abc", "abd", 3));
	check_str("ft_strchr", ft_strchr("hello", 'e'), strchr("hello", 'e'));
	check_str("ft_strrchr", ft_strrchr("hello", 'l'), strrchr("hello", 'l'));
	check_str("ft_strnstr", ft_strnstr("hello world", "world", 11), "world");
	dup = ft_strdup("hello");
	check_str("ft_strdup", dup, "hello");
	free(dup);
}

static void	test_memory(void)
{
	char	a[20];
	char	b[20];

	test_header("MEMORY FUNCTIONS");
	memset(a, 'A', 5);
	ft_memset(b, 'A', 5);
	a[5] = '\0';
	b[5] = '\0';
	check_str("ft_memset", b, a);
	strcpy(a, "abcdef");
	strcpy(b, "abcdef");
	memmove(a + 2, a, 4);
	ft_memmove(b + 2, b, 4);
	check_str("ft_memmove overlap right", b, a);
	strcpy(a, "abcdef");
	strcpy(b, "abcdef");
	memmove(a, a + 2, 4);
	ft_memmove(b, b + 2, 4);
	check_str("ft_memmove overlap left", b, a);
	check_int("ft_memcmp same", ft_memcmp("abc", "abc", 3),
		memcmp("abc", "abc", 3));
	check_int("ft_memcmp diff", ft_memcmp("abc", "abd", 3),
		memcmp("abc", "abd", 3));
}

static void	test_conversion(void)
{
	test_header("CONVERSION FUNCTIONS");
	check_int("ft_atoi -42", ft_atoi("   -42"), atoi("   -42"));
	check_int("ft_atoi +42abc", ft_atoi("   +42abc"), atoi("   +42abc"));
	check_int("ft_atoi zero", ft_atoi("0"), atoi("0"));
	check_int("ft_atoi spaces", ft_atoi(" \t\n\r\v\f42"),
		atoi(" \t\n\r\v\f42"));
}

int	main(void)
{
	test_chars();
	test_strings();
	test_memory();
	test_conversion();
	return (print_summary());
}
