/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:19:54 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/05 09:26:25 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../libft/libft.h"

char	*ft_get_our_line(char *read_4m_left)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!read_4m_left[i])
		return (NULL);
	while (read_4m_left[i] && read_4m_left[i] != '\n')
		i++;
	new_str = malloc((i + 2) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (read_4m_left[i] && read_4m_left[i] != '\n')
	{
		new_str[i] = read_4m_left[i];
		i++;
	}
	if (read_4m_left[i] == '\n')
	{
		new_str[i] = read_4m_left[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_new_str(char *read_4m_left)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (read_4m_left[i] && read_4m_left[i] != '\n')
		i++;
	if (!read_4m_left[i])
	{
		free(read_4m_left);
		return (NULL);
	}
	new_line = malloc((ft_strlen(read_4m_left) - i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (read_4m_left[i])
		new_line[j++] = read_4m_left[i++];
	new_line[j] = '\0';
	free(read_4m_left);
	return (new_line);
}
