/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:06:15 by ahalfrun          #+#    #+#             */
/*   Updated: 2021/10/26 17:11:08 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chr1;
	unsigned char	*chr2;
	size_t			i;

	i = 0;
	chr1 = (unsigned char *) s1;
	chr2 = (unsigned char *) s2;
	if (n <= 0)
		return (0);
	while (i < n - 1)
	{
		if (chr1[i] != chr2[i])
			break ;
		i++;
	}
	return (chr1[i] - chr2[i]);
}
