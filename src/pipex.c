/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 05:48:51 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/02 07:33:04 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char **envp)
{
	char	**sub_cmd;
	char	*path;

	sub_cmd = ft_split(cmd, ' ');
	path = get_path(sub_cmd[0], envp);
	if (execve(path, sub_cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: cooand not found: ", 2);
		ft_putendl_fd(sub_cmd[0], 2);
		ft_free_tab(sub_cmd);
		exit(0);
	}
}

void	childProcess(char **av, int *pipe_fd, char **envp)
{
	int	fd;
	
	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	execute(av[2], envp);
}

void	parentProcess(char **av, int *pipe_fd, char **envp)
{
	int fd;


	fd = open_file(av[4], 1);
	dup2(fd, 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	execute(av[3], envp);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

int main(int ac, char **av, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;
	if (ac != 5)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
	if (pipe(pipe_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		childProcess(av, pipe_fd, envp);
	parentProcess(av, pipe_fd, envp);
	printf("mohammed"); 
}