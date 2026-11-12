/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:00:22 by ale               #+#    #+#             */
/*   Updated: 2025/02/25 20:46:16 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen_m(const char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len])
		len++;
	return (len);
}

void	p_error(char *s, int pipefd, int pipefd1)
{
	if (pipefd)
		close (pipefd);
	if (pipefd1)
		close (pipefd1);
	perror(s);
	exit(1);
}

void	check_error(int n, char *s, int pipefd, int pipefd1)
{
	char	c;

	if (n == -1)
	{
		if (pipefd)
			close(pipefd);
		if (pipefd1)
			close(pipefd1);
		write(2, "zsh: ", 6);
		c = strerror(errno)[0] + 32;
		write(2, &c, 1);
		write(2, strerror(errno) + 1, (ft_strlen_m(strerror(errno)) - 1));
		write(2, ": ", 2);
		write(2, s, ft_strlen(s));
		write(2, "\n", 1);
		exit(1);
	}
}

void	process_last(int *pipefd, char **argv, int argc, char **envp)
{
	char	**cmd2;
	int		fd2;

	fd2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	check_error(fd2, argv[argc - 1], pipefd[0], pipefd[1]);
	cmd2 = ft_split(argv[argc - 2], ' ');
	if (!cmd2)
		p_error("malloc failed", pipefd[0], pipefd[1]);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(fd2);
	close(pipefd[0]);
	execute(cmd2, envp, "execvp cmd2");
}
