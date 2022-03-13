/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:08:20 by ahalfrun          #+#    #+#             */
/*   Updated: 2021/10/27 20:10:41 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elm;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = NULL;
	elm = lst;
	while (lst)
	{
		elm = ft_lstnew(f(lst->content));
		if (!elm)
		{
			ft_lstclear(&elm, del);
			return (NULL);
		}
		ft_lstadd_back(&new, elm);
		lst = lst->next;
	}
	return (new);
}
