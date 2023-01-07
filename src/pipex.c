/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 05:48:51 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/06 20:51:09 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
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

void	child1Process(char **av, int *pipe_fd, char **envp)
{
	int	fd;
	
	fd = open_file(av[1], 0);
	if(fd==-1)
	{
		perror(av[1]);
		exit(1);
	}
	dup2(fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	execute(av[2], envp);
}

void	child2Process(char **av, int *pipe_fd, char **envp)
{
	int fd;

	fd = open_file(av[4], 1);
	if(fd==-1)
	{
		perror(av[4]);
		exit(1);
	}
	dup2(fd, 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	execute(av[3], envp);
}

int main(int ac, char **av, char **envp)
{
	int		pipe_fd[2];
	int		x;
	pid_t	pid1;
	pid_t	pid2;
	
	if (ac != 5)
	{
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
		exit(1);
	}
	if (pipe(pipe_fd) == -1)
		exit(-1);
	pid1 = fork();
	if (pid1 == -1)
		exit(-1);
	if (!pid1)
			child1Process(av, pipe_fd, envp);
	else
	{
		pid2 = fork();
		if (!pid2)
			child2Process(av, pipe_fd, envp);
		else
		{
			close(pipe_fd[1]);
			close(pipe_fd[0]);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, &x, 0);
			if (WIFEXITED(x))
			{
				int exit_status = WEXITSTATUS(x);
				exit (exit_status);
			}
			
		}
	}
}
	