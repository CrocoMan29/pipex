/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:50:37 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/07 16:19:59 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../libft/libft.h"

void	ft_get_out(int getOut)
{
	if (getOut == 1)
		ft_putstr_fd("./pipex infile cmd ... cmd outfile", 2);
	exit(127);
}

int	open_file(char *file, int in_O_out)
{
	int	ownfile;

	if (in_O_out == 0)
		ownfile = open(file, O_RDONLY, 0644);
	if (in_O_out == 1)
		ownfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (in_O_out == 2)
		ownfile = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (in_O_out == -1)
		exit(2);
	if (ownfile < 0)
		exit(1);
	return (ownfile);
}

char	*my_env(char *name, char **envp)
{
	int		i;
	int		j;
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

char	*get_path(char *cmd, char **envp)
{
	char	**source_path;
	int		i;
	char	*part_of_path;
	char	*exec_cmd;

	source_path = ft_split(my_env("PATH", envp), ':');
	if (source_path == NULL)
		return (cmd);
	i = -1;
	while (source_path[++i])
	{
		part_of_path = ft_strjoin(source_path[i], "/");
		exec_cmd = ft_strjoin(part_of_path, cmd);
		if (access(exec_cmd, F_OK | X_OK) == 0)
		{
			free(cmd);
			return (exec_cmd);
		}
		free(exec_cmd);
	}
	return (cmd);
}

void	opt(int *arr, char **av, int ac)
{
	arr[0] = 2;
	arr[1] = open_file(av[1], 0);
	arr[2] = open_file(av[ac - 1], 1);
	dup2(arr[1], 0);
}
