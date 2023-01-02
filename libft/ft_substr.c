/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:24:18 by yismaail          #+#    #+#             */
/*   Updated: 2022/12/31 07:49:47 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*dup;

	str = (char *)s;
	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str + start))
	{
		dup = malloc(ft_strlen(str + start) + 1);
		len = ft_strlen(str + start);
	}
	else
		dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str + start, len + 1);
	return (dup);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (size && count >= SIZE_MAX / size)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	if (dstsize == 0)
		return (j);
	while (*(src + i) && i < dstsize - 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (j);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (d == NULL && s == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}