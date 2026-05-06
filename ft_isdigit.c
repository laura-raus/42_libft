/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:47:42 by laraus            #+#    #+#             */
/*   Updated: 2026/05/06 16:04:26 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", ft_isdigit('9'));
	printf("%d\n", ft_isdigit('a'));
	printf("%d\n", ft_isdigit('/'));
}
*/
