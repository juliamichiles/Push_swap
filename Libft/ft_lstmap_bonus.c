/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:27:02 by juliatav          #+#    #+#             */
/*   Updated: 2025/10/24 16:13:42 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			del(new_node->content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*
#include <stdio.h>

void	*ft_strdup_upcase(void *p)
{
	int		i = 0;
	char	*str;
	char	*new;

	str = (char *)p;
	if (!str)
		return (NULL);
	new = malloc(ft_strlen(str) + 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			new[i] = str[i] - 32;
		else
			new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return ((void *)new);
}

void do_nothing(void *p) { (void)p; }

int	main(int ac, char **av)
{
	t_list	*new_list = NULL;
	t_list	*temp_new = NULL;
	t_list  *list = NULL;
	t_list	*node;
	int	i = 1;

	if (ac < 2)
		return 1;
	printf("[OG LIST]\n");
	while (i < ac)
	{
		node = ft_lstnew(av[i]);
		if (!node)
		{
			ft_lstclear(&list, do_nothing);
			printf("mem. alloc. failed\n");
			return 1;
		}
		ft_lstadd_back(&list, node);
		printf("[node %d - (%p)]\n", i, list);
		printf("[content = %s | next -> (%p)]\n\n", 
			(char *)list->content, list->next);
		i++;
	}
	new_list = ft_lstmap(list, ft_strdup_upcase, free);
	if (!new_list)
	{
		printf("mem. alloc. failed in ft_lstmap\n");
		ft_lstclear(&list, free);
		return (1);
	}
	temp_new = new_list;
	printf("[NEW LIST]\n");
	i = 1;
	while (temp_new)
	{
		printf("[node %d - (%p)]\n", i, temp_new);
		printf("[content = %s | next -> (%p)]\n\n", 
			(char *)temp_new->content, temp_new->next);
		temp_new = temp_new->next;
		i++;
	}
	ft_lstclear(&new_list, free);
	ft_lstclear(&list, do_nothing);
	return (0);
}*/
