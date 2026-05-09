/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:51:03 by laraus            #+#    #+#             */
/*   Updated: 2026/05/09 18:15:53 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*str;

	str = "hello";
	printf("%s\n", ft_strchr(str, 'e'));
	printf("%s\n", ft_strchr(str, 'o'));
	printf("%p\n", ft_strchr(str, 'x'));
	printf("%s\n", ft_strchr(str, '\0'));
}
*/