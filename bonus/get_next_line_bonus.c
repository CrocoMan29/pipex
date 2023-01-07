/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:25:53 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/05 09:26:17 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../libft/libft.h"

char	*ft_read_str(int fd, char *read_4m_left)
{
	char	*new_str;
	int		bytes_read;

	new_str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(read_4m_left, '\n') && bytes_read)
	{
		bytes_read = read(fd, new_str, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(new_str);
			free(read_4m_left);
			new_str = NULL;
			read_4m_left = NULL;
			return (NULL);
		}
		new_str[bytes_read] = '\0';
		read_4m_left = ft_strjoin(read_4m_left, new_str);
	}
	free(new_str);
	return (read_4m_left);
}

char	*get_next_line(int fd)
{
	static char	*read_4m_left[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_4m_left[fd] = ft_read_str(fd, read_4m_left[fd]);
	if (!read_4m_left[fd])
		return (NULL);
	line = ft_get_our_line(read_4m_left[fd]);
	read_4m_left[fd] = ft_new_str(read_4m_left[fd]);
	return (line);
}
