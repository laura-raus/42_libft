/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:51:49 by laraus            #+#    #+#             */
/*   Updated: 2026/05/06 16:50:59 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little[0])
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j]
			&& i + j < len)
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "hello world";

	printf("%s\n", ft_strnstr(str, "world", 11));
	printf("%s\n", ft_strnstr(str, "hello", 5));
	printf("%p\n", ft_strnstr(str, "world", 5));
	printf("%s\n", ft_strnstr(str, "", 5));
}
*/