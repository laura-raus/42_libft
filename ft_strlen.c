/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:48:23 by laraus            #+#    #+#             */
/*   Updated: 2026/05/06 16:51:56 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*pt;

	pt = s;
	while (*s)
		s++;
	return (s - pt);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%zu\n", ft_strlen(""));
	printf("%zu\n", ft_strlen("hello"));
	printf("%zu\n", ft_strlen("hello world"));
}
*/