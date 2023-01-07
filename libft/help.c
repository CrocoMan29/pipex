/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:28:51 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/07 14:59:06 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_free(char *p)
{
	free(p);
	return (NULL);
}

char	*ft_strjoin(char *old_str, char *current_str)
{
	size_t		arr[2];
	char		*new_str;

	if (!old_str)
	{
		old_str = malloc(1 * sizeof(char));
		old_str[0] = '\0';
	}
	if (!old_str || !current_str)
		return (ft_free(old_str));
	new_str = malloc(ft_strlen(old_str) + ft_strlen(current_str) + 1);
	if (!new_str)
		return (NULL);
	arr[0] = -1;
	if (old_str)
		while (old_str[++arr[0]] != '\0')
			new_str[arr[0]] = old_str[arr[0]];
	arr[1] = 0;
	while (current_str[arr[1]] != '\0')
		new_str[arr[0]++] = current_str[arr[1]++];
	new_str[ft_strlen(old_str) + ft_strlen(current_str)] = '\0';
	free(old_str);
	return (new_str);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}
