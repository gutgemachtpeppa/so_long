/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:41:54 by ahalfrun          #+#    #+#             */
/*   Updated: 2021/10/27 19:22:53 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	chr;

	chr = (char) c;
	i = ft_strlen(s);
	if (chr != '\0')
	{
		while (i)
		{
			if (s[i] == chr)
				return ((char *)s + i);
			i--;
		}
	}
	if (s[i] == chr)
		return ((char *)s + i);
	return (NULL);
}
