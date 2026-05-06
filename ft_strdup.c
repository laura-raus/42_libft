/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:52:20 by laraus            #+#    #+#             */
/*   Updated: 2026/05/06 15:52:21 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*copy;

	copy = ft_strdup("hello");
	printf("%s\n", copy);
	free(copy);

	copy = ft_strdup("");
	printf("%s\n", copy);
	free(copy);
}
*/