/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:51:31 by laraus            #+#    #+#             */
/*   Updated: 2026/05/09 18:16:15 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "hello";

	printf("%s\n", (char *)ft_memchr(str, 'e', 5));
	printf("%s\n", (char *)ft_memchr(str, 'o', 5));
	printf("%p\n", ft_memchr(str, 'x', 5));
	printf("%p\n", ft_memchr(str, 'o', 4));
}
*/
