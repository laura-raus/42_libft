/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:53:14 by laraus            #+#    #+#             */
/*   Updated: 2026/05/06 16:00:12 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s;

	s = ft_strjoin("hello", " world");
	printf("[%s]\n", s);
	free(s);
	s = ft_strjoin("", "abc");
	printf("[%s]\n", s);
	free(s);
	s = ft_strjoin("abc", "");
	printf("[%s]\n", s);
	free(s);
	s = ft_strjoin("", "");
	printf("[%s]\n", s);
	free(s);
	return (0);
}
*/