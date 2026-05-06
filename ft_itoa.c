/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:53:42 by laraus            #+#    #+#             */
/*   Updated: 2026/05/06 16:13:32 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = ft_len(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (len-- > 0 && str[len] != '-')
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s;

	s = ft_itoa(0);
	printf("[%s]\n", s);
	free(s);
	s = ft_itoa(42);
	printf("[%s]\n", s);
	free(s);
	s = ft_itoa(-42);
	printf("[%s]\n", s);
	free(s);
	s = ft_itoa(-2147483648);
	printf("[%s]\n", s);
	free(s);
	s = ft_itoa(2147483647);
	printf("[%s]\n", s);
	free(s);
	return (0);
}
*/
