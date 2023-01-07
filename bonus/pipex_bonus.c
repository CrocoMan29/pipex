/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:00:47 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/07 20:53:16 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../libft/libft.h"

void	execute(char *cmd, char **envp)
{
	char	**sub_cmd;
	char	*path;

	sub_cmd = ft_split(cmd, ' ');
	if (access(sub_cmd[0], F_OK | X_OK) == 0)
		path = sub_cmd[0];
	else
		path = get_path(sub_cmd[0], envp);
	if (execve(path, sub_cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(sub_cmd[0], 2);
		ft_free_tab(sub_cmd);
		exit(127);
	}
}

void	ft_put_inhere_doc(char **av, int pipe_fd[2])
{
	char	*resulta;

	close(pipe_fd[0]);
	while (1)
	{
		resulta = get_next_line(0);
		if (resulta != NULL)
		{
			if (ft_strncmp(resulta, av[2], ft_strlen(resulta) - 1) == 0)
			{
				free(resulta);
				exit(0);
			}
			ft_putstr_fd(resulta, pipe_fd[1]);
			free(resulta);
		}
		exit(1);
	}
}

void	ft_here_doc(char **av)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
		ft_put_inhere_doc(av, pipe_fd);
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		wait(NULL);
	}
}

void	ft_pipe(char *cmd, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		execute(cmd, envp);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
	}
	close(pipe_fd[1]);
	close(pipe_fd[0]);
}

int	main(int ac, char **av, char **envp)
{
	int	arr[4];

	if (ac < 5)
		ft_get_out(1);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (ac < 6)
			ft_get_out(1);
		arr[0] = 3;
		arr[2] = open_file(av[ac -1], 2);
		ft_here_doc(av);
	}
	else
		opt(arr, av, ac);
	while (arr[0] < ac - 2)
		ft_pipe(av[arr[0]++], envp);
	arr[3] = fork();
	if (!arr[3])
	{
		dup2(arr[2], 1);
		execute(av[ac - 2], envp);
	}
	else
	{
		while (wait(NULL) != -1)
			;
	}
	close(arr[2]);
	close(arr[1]);
}
