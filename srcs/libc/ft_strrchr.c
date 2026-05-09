/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:51:14 by laraus            #+#    #+#             */
/*   Updated: 2026/05/09 18:15:40 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (last);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*str;

	str = "banana";
	printf("%s\n", ft_strrchr(str, 'a'));
	printf("%s\n", ft_strrchr(str, 'n'));
	printf("%p\n", ft_strrchr(str, 'x'));
}
*/
