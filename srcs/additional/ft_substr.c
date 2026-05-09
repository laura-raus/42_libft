/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:53:08 by laraus            #+#    #+#             */
/*   Updated: 2026/05/06 15:55:03 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s;

	s = ft_substr("hello world", 0, 5);
	printf("[%s]\n", s);
	free(s);
	s = ft_substr("hello world", 6, 20);
	printf("[%s]\n", s);
	free(s);
	s = ft_substr("hello", 50, 10);
	printf("[%s]\n", s);
	free(s);
	s = ft_substr("", 0, 5);
	printf("[%s]\n", s);
	free(s);
	return (0);
}
*/
