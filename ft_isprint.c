/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:48:10 by laraus            #+#    #+#             */
/*   Updated: 2026/05/06 16:04:42 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isprint(' '));
	printf("%d\n", ft_isprint('~'));
	printf("%d\n", ft_isprint('\n'));
	printf("%d\n", ft_isprint(127));
}
*/
