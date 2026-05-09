/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:24:57 by laraus            #+#    #+#             */
/*   Updated: 2026/05/09 14:33:01 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_H
# define TEST_UTILS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define UNUSED __attribute__((unused))

static int	g_total = 0;
static int	g_failed = 0;

static void	UNUSED	test_header(char *title)
{
	printf("\n=====================================================================================\n");
	printf("%s\n", title);
	printf("=====================================================================================\n");
}

static void	UNUSED	check_int(char *label, int got, int expected)
{
	g_total++;
	printf("%-35s | got: %-14d expected: %-14d",
		label, got, expected);
	if (got == expected)
		printf(" OK\n");
	else
	{
		g_failed++;
		printf(" FAIL\n");
	}
}

static void	UNUSED	check_size(char *label, size_t got, size_t expected)
{
	g_total++;
	printf("%-35s | got: %-14zu expected: %-14zu",
		label, got, expected);
	if (got == expected)
		printf(" OK\n");
	else
	{
		g_failed++;
		printf(" FAIL\n");
	}
}

static void	UNUSED	check_bool(char *label, int got, int expected)
{
	check_int(label, got != 0, expected != 0);
}

static void	UNUSED	check_str(char *label, char *got, char *expected)
{
	g_total++;
	if (!got && !expected)
	{
		printf("%-35s | got: %-14s expected: %-14s OK\n",
			label, "[NULL]", "[NULL]");
		return ;
	}
	if (!got || !expected)
	{
		g_failed++;
		printf("%-35s | got: %-14s expected: %-14s FAIL\n",
			label,
			got ? got : "[NULL]",
			expected ? expected : "[NULL]");
		return ;
	}
	printf("%-35s | got: [%-12s] expected: [%-12s]",
		label, got, expected);
	if (strcmp(got, expected) == 0)
		printf(" OK\n");
	else
	{
		g_failed++;
		printf(" FAIL\n");
	}
}

static int UNUSED	print_summary(void)
{
	printf("\nTOTAL: %d | FAILED: %d\n", g_total, g_failed);
	return (g_failed);
}

#endif
