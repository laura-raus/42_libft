/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:52:11 by laraus            #+#    #+#             */
/*   Updated: 2026/05/06 15:52:12 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > ((size_t)-1 / size))
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	int		*arr;
	size_t	i;

	arr = ft_calloc(5, sizeof(int));
	if (!arr)
		return (1);
	i = 0;
	while (i < 5)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	free(arr);
}
*/