/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:47:03 by ahalfrun          #+#    #+#             */
/*   Updated: 2021/10/27 19:51:03 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*elm;

	if (lst == NULL)
		return (0);
	i = 0;
	elm = lst;
	while (elm)
	{
		elm = elm->next;
		i++;
	}
	return (i);
}
