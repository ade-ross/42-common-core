/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_h.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:43:40 by ade-ross          #+#    #+#             */
/*   Updated: 2025/02/24 18:18:23 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_proc_fir_h(int *pipefd, char **argv, int *pipefd1, char ***cmd1)
{
	int		fd1;

	close(pipefd[0]);
	close(pipefd1[1]);
	close(pipefd1[0]);
	fd1 = open(argv[1], O_RDONLY);
	check_error(fd1, argv[1], 0, pipefd[1]);
	dup2(fd1, STDIN_FILENO);
	close(fd1);
	cmd1[0] = ft_split(argv[2], ' ');
	if (!cmd1[0])
		p_error("malloc failed", 0, pipefd[1]);
}

void	p_error_b(char *s, int *pipefd, int *pipefd1)
{
	if (pipefd[0])
		close (pipefd[0]);
	if (pipefd[1])
		close (pipefd[1]);
	if (pipefd1[0])
		close (pipefd1[0]);
	if (pipefd1[1])
		close (pipefd1[1]);
	perror(s);
	exit(1);
}
