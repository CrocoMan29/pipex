/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 05:55:44 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/02 07:11:30 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);
char	**ft_free_tab(char **arr);
void	ft_free_tab2(char **arr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *old_str, char *current_str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);


void	execute(char *cmd, char **envp);
void	childProcess(char **av, int *pipe_fd, char **envp);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int	open_file(char  *file, int in_O_out);
char	*my_env(char *name, char **envp);
int	ft_strcmp(char *s1, char *s2);
char	*get_path(char *cmd, char **envp);

#endif