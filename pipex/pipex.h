/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:59:22 by ale               #+#    #+#             */
/*   Updated: 2025/02/24 21:46:00 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strnstr_mod(char *big, char *little, size_t len);

void	free_paths(char	**paths);
char	*find_path(char *cmd, char **envp);
void	execute(char **cmd, char **envp, char *s);

int		ft_strlen_m(const char *s);
void	p_error(char *s, int pipefd, int pipefd1);
void	process_last(int *pipefd, char **argv, int argc, char **envp);
void	check_error(int n, char *s, int pipefd, int pipefd1);
