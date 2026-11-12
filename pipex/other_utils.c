/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:57:02 by ade-ross          #+#    #+#             */
/*   Updated: 2025/02/24 21:43:47 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_paths(char	**paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

/* Function that will look for the path line inside the environment, will
split and test each command path and then return the right one. */
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_paths(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_paths(paths);
	return (0);
}

/* Function that take the command and send it to find_path
before executing it. */
void	execute(char **cmd, char **envp, char *s)
{
	int		i;
	char	*path;

	i = -1;
	path = find_path(cmd[0], envp);
	if (!path)
	{
		write(2, "zsh: command not found: ", 24);
		write(2, cmd[0], ft_strlen_m(cmd[0]));
		write(2, "\n", 1);
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit(127);
	}
	execve(path, cmd, envp);
	free_paths(cmd);
	free(path);
	p_error(s, 0, 0);
}
