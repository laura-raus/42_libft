/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:54:22 by laraus            #+#    #+#             */
/*   Updated: 2026/05/06 15:56:22 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	ft_putendl_fd("hello", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd(NULL, 1);
	return (0);
}
*/