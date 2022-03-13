/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:34:55 by ahalfrun          #+#    #+#             */
/*   Updated: 2021/10/27 16:23:28 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	chr;

	chr = (char) c;
	i = -1;
	while (s[++i])
	{
		if (s[i] == chr)
			return ((char *)s + i);
	}
	if (s[i] == chr)
		return ((char *)s + i);
	return (NULL);
}
