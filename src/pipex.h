/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 05:55:44 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/07 15:00:30 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

void	execute(char *cmd, char **envp);
void	child1Process(char **av, int *pipe_fd, char **envp);
void	child2Process(char **av, int *pipe_fd, char **envp);
int		open_file(char *file, int in_O_out);
char	*my_env(char *name, char **envp);
char	*get_path(char *cmd, char **envp);

#endif