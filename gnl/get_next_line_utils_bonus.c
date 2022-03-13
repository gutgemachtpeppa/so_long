/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:11:03 by ahalfrun          #+#    #+#             */
/*   Updated: 2021/12/24 15:35:08 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strdup(char const *str)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	out = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!out)
		return (NULL);
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j])
		out[i++] = s2[j++];
	out[i] = '\0';
	return (out);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	i = 0;
	if (!s || len < 0)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		out = malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	while (len > 0 && s[i + start])
	{
		out[i] = s[i + start];
		i++;
		len--;
	}
	out[i] = '\0';
	return (out);
}
