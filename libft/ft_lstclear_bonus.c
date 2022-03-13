/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:02:57 by ahalfrun          #+#    #+#             */
/*   Updated: 2021/10/27 20:14:46 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elm;
	t_list	*next;

	if (!lst || !(*lst))
		return ;
	elm = *lst;
	while (elm)
	{
		next = elm->next;
		ft_lstdelone(elm, del);
		elm = next;
	}
	*lst = NULL;
}
