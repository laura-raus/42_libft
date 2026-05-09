/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_additional.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 00:27:20 by laraus            #+#    #+#             */
/*   Updated: 2026/05/09 00:27:21 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <limits.h>

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	split_equals(char **split, char **expected)
{
	int	i;

	if (!split)
		return (0);
	i = 0;
	while (expected[i])
	{
		if (!split[i] || strcmp(split[i], expected[i]) != 0)
			return (0);
		i++;
	}
	return (split[i] == NULL);
}

static void	check_split(char *label, char *s, char c, char **expected)
{
	char	**split;

	g_total++;
	split = ft_split(s, c);
	printf("%-35s | ", label);
	if (split_equals(split, expected))
		printf("OK\n");
	else
	{
		g_failed++;
		printf("FAIL\n");
	}
	free_split(split);
}

static char	map_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static void	iter_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static void	test_substr(void)
{
	char	*s;

	test_header("FT_SUBSTR");
	s = ft_substr("hello world", 6, 5);
	check_str("normal", s, "world");
	free(s);
	s = ft_substr("hello", 0, 2);
	check_str("start 0 len 2", s, "he");
	free(s);
	s = ft_substr("hello", 2, 50);
	check_str("len too long", s, "llo");
	free(s);
	s = ft_substr("hello", 50, 10);
	check_str("start too far", s, "");
	free(s);
	s = ft_substr("", 0, 5);
	check_str("empty source", s, "");
	free(s);
	s = ft_substr("hello", 0, 0);
	check_str("zero len", s, "");
	free(s);
}

static void	test_join_trim(void)
{
	char	*s;

	test_header("FT_STRJOIN");
	s = ft_strjoin("hello ", "world");
	check_str("normal", s, "hello world");
	free(s);
	s = ft_strjoin("", "hello");
	check_str("empty first", s, "hello");
	free(s);
	s = ft_strjoin("hello", "");
	check_str("empty second", s, "hello");
	free(s);
	s = ft_strjoin("", "");
	check_str("both empty", s, "");
	free(s);
	test_header("FT_STRTRIM");
	s = ft_strtrim("...hello...", ".");
	check_str("dots", s, "hello");
	free(s);
	s = ft_strtrim("hello", "x");
	check_str("nothing to trim", s, "hello");
	free(s);
	s = ft_strtrim("xxxx", "x");
	check_str("all trimmed", s, "");
	free(s);
	s = ft_strtrim("", "x");
	check_str("empty string", s, "");
	free(s);
	s = ft_strtrim("abchellocba", "abc");
	check_str("multi charset", s, "hello");
	free(s);
}

static void	test_split(void)
{
	char	*e1[] = {"hello", "world", "42", NULL};
	char	*e2[] = {NULL};
	char	*e3[] = {"hello", NULL};
	char	*e4[] = {"hello", "world", NULL};
	char	*e5[] = {"a", "b", "c", NULL};

	test_header("FT_SPLIT");
	check_split("spaces", "  hello  world  42  ", ' ', e1);
	check_split("empty string", "", ' ', e2);
	check_split("only delimiters", "      ", ' ', e2);
	check_split("no delimiter", "hello", ' ', e3);
	check_split("commas", ",,,hello,,world,,,", ',', e4);
	check_split("colon", "a:b:c", ':', e5);
}

static void	test_itoa_mapi_iteri(void)
{
	char	*s;
	char	buf[6];

	test_header("FT_ITOA");
	s = ft_itoa(0);
	check_str("zero", s, "0");
	free(s);
	s = ft_itoa(1);
	check_str("one", s, "1");
	free(s);
	s = ft_itoa(-1);
	check_str("minus one", s, "-1");
	free(s);
	s = ft_itoa(INT_MAX);
	check_str("INT_MAX", s, "2147483647");
	free(s);
	s = ft_itoa(INT_MIN);
	check_str("INT_MIN", s, "-2147483648");
	free(s);
	test_header("FT_STRMAPI / FT_STRITERI");
	s = ft_strmapi("abc42", map_upper);
	check_str("strmapi upper", s, "ABC42");
	free(s);
	strcpy(buf, "abc42");
	ft_striteri(buf, iter_upper);
	check_str("striteri upper", buf, "ABC42");
}

int	main(void)
{
	test_substr();
	test_join_trim();
	test_split();
	test_itoa_mapi_iteri();
	return (print_summary());
}
