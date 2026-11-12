/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale <ale@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:00:24 by ale               #+#    #+#             */
/*   Updated: 2025/01/29 18:00:24 by ale              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_here_doc_h(char *limiter, int *pipefd1, int *pipefd, int **pid)
{
	char	*buffer;
	int		i;
	char	*limiter_n;

	close(pipefd[0]);
	close(pipefd[1]);
	close(pipefd1[0]);
	free(*pid);
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		buffer = get_next_line(STDIN_FILENO);
		limiter_n = ft_strjoin(limiter, "\n");
		i = ft_strnstr_mod(buffer, limiter_n, ft_strlen(limiter_n));
		free(limiter_n);
		if (i == 0)
			break ;
		else
			write(pipefd1[1], buffer, ft_strlen(buffer));
		free(buffer);
	}
	free(buffer);
	close(pipefd1[1]);
	exit(0);
}

void	handle_here_doc(char *limiter, int *pipefd1, int *pipefd, int **pid)
{
	*pid[0] = fork();
	if (*pid[0] == -1)
		p_error_b("fork", pipefd, pipefd1);
	if (*pid[0] == 0)
		handle_here_doc_h(limiter, pipefd1, pipefd, pid);
	else
	{
		while (wait(NULL) < 0)
			;
	}
}

void	child_process_first(int *pipefd, char **argv, int *pipefd1, char **envp)
{
	char	**cmd1;

	if (ft_strcmp(argv[1], "here_doc") != 0)
	{
		child_proc_fir_h(pipefd, argv, pipefd1, &cmd1);
	}
	else
	{
		close(pipefd[0]);
		close(pipefd1[1]);
		dup2(pipefd1[0], STDIN_FILENO);
		close(pipefd1[0]);
		cmd1 = ft_split(argv[3], ' ');
		if (!cmd1[0])
			p_error("malloc failed", 0, pipefd[1]);
	}
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	execute(cmd1, envp, "execvp cmd1");
}

void	execute_pipex(char **argv, int argc, int *pipefd, char **envp)
{
	int		*pid;
	int		pipefd1[2];

	if (pipe(pipefd1) == -1)
		p_error("pipe", pipefd[0], pipefd[1]);
	pid = malloc(sizeof(int) * 2);
	if (!pid)
		p_error_b("pid", pipefd, pipefd1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		handle_here_doc(argv[2], pipefd1, pipefd, &pid);
	pid[1] = fork();
	if (pid[1] == -1)
		p_error_b("fork", pipefd, pipefd1);
	if (pid[1] == 0)
	{
		free(pid);
		child_process_first(pipefd, argv, pipefd1, envp);
	}
	close(pipefd1[1]);
	close(pipefd1[0]);
	while (wait(NULL) < 0)
		;
	free(pid);
	process_last(pipefd, argv, argc, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];

	if ((ft_strcmp("here_doc", argv[1]) != 0 && argc != 5) || \
		(ft_strcmp("here_doc", argv[1]) == 0 && argc != 6))
		return (1);
	if (pipe(pipefd) == -1)
		p_error("pipe", 0, 0);
	execute_pipex(argv, argc, pipefd, envp);
}
