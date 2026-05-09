/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:49:29 by laraus            #+#    #+#             */
/*   Updated: 2026/05/09 18:21:16 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>
int	main(void)
{
	int	src[] = {1, 2, 3, 4 ,5};
	int	dst[] = {0 , 0, 0, 0, 0};

	ft_memcpy(dst, src, 20);
	printf("%d\n", dst[0]);
	printf("%d\n", dst[1]);
	printf("%d\n", dst[2]);
	printf("%d\n", dst[3]);
	printf("%d\n", dst[4]);

	ft_memcpy(dst, src, 0);
	printf("%d\n", dst[0]);
}
*/