/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:49:05 by laraus            #+#    #+#             */
/*   Updated: 2026/05/09 18:10:57 by laraus           ###   ########.fr       */
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
	// 196354
	int arr[1] = {0};
	ft_memset(arr, 2, 1);
	ft_memset(((unsigned char *)(arr) + 1), 255, 1);
	ft_memset(((unsigned char *)(arr) + 2), 2, 1);
	printf("%d\n", arr[0]);
}
*/