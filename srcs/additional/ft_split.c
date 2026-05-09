/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:53:34 by laraus            #+#    #+#             */
/*   Updated: 2026/05/09 18:12:18 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

static void	ft_free(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			arr[i] = ft_word(s, c);
			if (!arr[i++])
				return (ft_free(arr, i - 1), NULL);
		}
		while (*s && *s != c)
			s++;
	}
	arr[i] = NULL;
	return (arr);
}

/*
#include <stdio.h>

static void	print_split(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		printf("[%s]\n", arr[i]);
		i++;
	}
	printf("NULL\n");
}

static void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main(void)
{
	char	**arr;

	arr = ft_split("hello world 42", ' ');
	print_split(arr);
	free_split(arr);
	arr = ft_split("   hello   world   ", ' ');
	print_split(arr);
	free_split(arr);
	arr = ft_split(";;;;", ';');
	print_split(arr);
	free_split(arr);
	arr = ft_split("", ' ');
	print_split(arr);
	free_split(arr);
	arr = ft_split("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 'a');
	print_split(arr);
	free_split(arr);
	return (0);
}
*/