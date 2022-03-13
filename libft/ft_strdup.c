/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:40:49 by ahalfrun          #+#    #+#             */
/*   Updated: 2021/10/27 13:50:33 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy)
		ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
	return (copy);
}
