/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 23:59:52 by laraus            #+#    #+#             */
/*   Updated: 2026/05/09 00:29:00 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"

static void	del(void *content)
{
	free(content);
}

static void	to_upper_first(void *content)
{
	char	*s;

	s = (char *)content;
	if (s && s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;
}

static void	*dup_upper(void *content)
{
	char	*s;
	char	*copy;
	int		i;

	s = (char *)content;
	copy = ft_strdup(s);
	if (!copy)
		return (NULL);
	i = 0;
	while (copy[i])
	{
		if (copy[i] >= 'a' && copy[i] <= 'z')
			copy[i] -= 32;
		i++;
	}
	return (copy);
}

int	main(void)
{
	t_list	*list;
	t_list	*mapped;

	test_header("LINKED LIST FUNCTIONS");
	list = NULL;
	check_int("empty list size", ft_lstsize(list), 0);
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("one")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("two")));
	ft_lstadd_front(&list, ft_lstnew(ft_strdup("zero")));
	check_int("list size after add", ft_lstsize(list), 3);
	check_str("first node", (char *)list->content, "zero");
	check_str("last node", (char *)ft_lstlast(list)->content, "two");
	ft_lstiter(list, to_upper_first);
	check_str("iter changed first", (char *)list->content, "Zero");
	mapped = ft_lstmap(list, dup_upper, del);
	check_int("mapped size", ft_lstsize(mapped), 3);
	check_str("mapped first", (char *)mapped->content, "ZERO");
	ft_lstclear(&mapped, del);
	check_int("mapped cleared", mapped == NULL, 1);
	ft_lstclear(&list, del);
	check_int("list cleared", list == NULL, 1);
	return (print_summary());
}
