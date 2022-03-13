/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:23:49 by ahalfrun          #+#    #+#             */
/*   Updated: 2021/10/27 19:24:24 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	len;
	size_t	size;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	len = dlen;
	if (!(dstsize > dlen))
		return (dstsize + slen);
	else
		size = dlen + slen;
	while (*src && len + 1 < dstsize)
	{
		dst[len++] = *src++;
	}
	if (len < dstsize)
		dst[len] = '\0';
	return (size);
}
