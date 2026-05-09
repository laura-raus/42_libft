/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:54:17 by laraus            #+#    #+#             */
/*   Updated: 2026/05/09 18:11:13 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}
/*
int	main(void)
{
	ft_putstr_fd("hello", 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("", 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(NULL, 1);
	return (0);
}
*/