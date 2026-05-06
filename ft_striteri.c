/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:53:57 by laraus            #+#    #+#             */
/*   Updated: 2026/05/06 15:56:06 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

static void	test_func(unsigned int i, char *c)
{
	if (i % 2 == 1 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	main(void)
{
	char	s1[] = "abcdef";
	char	s2[] = "";

	ft_striteri(s1, test_func);
	printf("[%s]\n", s1);
	ft_striteri(s2, test_func);
	printf("[%s]\n", s2);
	return (0);
}
*/