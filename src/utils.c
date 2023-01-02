/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:13:30 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/02 07:24:05 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char  *file, int in_O_out)
{
	int ownfile;

	if (in_O_out == 0)
		ownfile = open(file, O_RDONLY, 0777);
	if (in_O_out == 1)
		ownfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (in_O_out == -1)
		exit(0);
	return (ownfile);
}

char	*my_env(char *name, char **envp)
{
	int	i;
	int	j;
	char	*sub;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		sub = ft_substr(envp[i], 0, j);
		if (ft_strcmp(name, sub) == 0)
		{
			free(sub);
			return (envp[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
		ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

char	*get_path(char *cmd, char **envp)
{
	char	**source_path;
	char	**source_cmd;
	int	i;
	char	*part_of_path;
	char	*exec_cmd;

	source_path = ft_split(my_env("PATH", envp), ':');
	source_cmd = ft_split(cmd, ' ');
	i = -1;
	while (source_path[++i])
	{
		part_of_path = ft_strjoin(source_path[i], "/");
		exec_cmd = ft_strjoin(part_of_path, source_cmd[0]);
		if (access(exec_cmd, F_OK | X_OK) == 0)
		{
			ft_free_tab2(source_cmd);
			return(exec_cmd);
		}
		free(exec_cmd);
	}
	//char *sr = malloc(1);

	//ft_free_tab2(source_cmd);
	//ft_free_tab2(source_path);
	return (cmd);
}