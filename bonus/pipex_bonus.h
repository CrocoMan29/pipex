/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:30:55 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/07 15:48:25 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	ft_pipe(char *cmd, char **envp);
void	ft_here_doc(char **av);
void	ft_put_inhere_doc(char **av, int pipe_fd[2]);
void	execute(char *cmd, char **envp);
void	ft_get_out(int getOut);
int		open_file(char *file, int in_O_out);
char	*get_path(char *cmd, char **envp);
char	*my_env(char *name, char **envp);
void	opt(int *arr, char **av, int ac);

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *read_4m_left);
char	*ft_get_our_line(char *read_4m_left);
char	*ft_new_str(char *read_4m_left);

#endif