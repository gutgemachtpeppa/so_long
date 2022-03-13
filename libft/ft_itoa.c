/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:28:23 by ahalfrun          #+#    #+#             */
/*   Updated: 2021/10/27 19:16:20 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	n /= 10;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*out;
	size_t			len;
	size_t			i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbrlen(n);
	out = malloc(sizeof(char) * len + 1);
	out[len] = '\0';
	if (!out)
		return (NULL);
	if (n < 0)
	{
		out[0] = '-';
		n = n * (-1);
		i = i + 1;
	}
	while (i < len--)
	{
		out[len] = (n % 10) + '0';
		n /= 10;
	}
	return (out);
}
