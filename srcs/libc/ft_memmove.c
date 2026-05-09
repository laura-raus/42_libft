/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:49:41 by laraus            #+#    #+#             */
/*   Updated: 2026/05/09 00:19:09 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d > s)
	{
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}

/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = "abcdef";
	char	s2[] = "abcdef";

	ft_memmove(s1 + 2, s1, 4);
	printf("%s\n", s1);
	ft_memmove(s2, s2 + 2, 4);
	printf("%s\n", s2);
}
*/
