/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:49:05 by laraus            #+#    #+#             */
/*   Updated: 2026/05/06 15:49:08 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*
#include <stdio.h>
int	main(void)
{
	char	s[10] = "abcdefghi";

	ft_memset(s, 'X', 3);
	printf("%s\n", s);
	ft_memset(s, 0, 10);
	printf("%d\n", s[0]);
}
*/
