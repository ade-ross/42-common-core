/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:07:31 by ale               #+#    #+#             */
/*   Updated: 2025/02/24 21:46:46 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process_first(int *pipefd, char **argv, char **envp)
{
	int		fd1;
	char	**cmd1;

	fd1 = open(argv[1], O_RDONLY);
	check_error(fd1, argv[1], pipefd[0], pipefd[1]);
	close(pipefd[0]);
	dup2(fd1, STDIN_FILENO);
	close(fd1);
	cmd1 = ft_split(argv[2], ' ');
	if (!cmd1)
		p_error("malloc failed", 0, pipefd[1]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	execute(cmd1, envp, "execvp cmd1");
}

void	execute_pipex(char **argv, int argc, int *pipefd, char **envp)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		p_error("fork", pipefd[0], pipefd[1]);
	if (pid == 0)
		child_process_first(pipefd, argv, envp);
	while (wait(NULL) < 0)
		;
	process_last(pipefd, argv, argc, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];

	if (argc != 5)
		return (1);
	if (pipe(pipefd) == -1)
		p_error("pipe", 0, 0);
	execute_pipex(argv, argc, pipefd, envp);
}
