/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:15:22 by ade-ross          #+#    #+#             */
/*   Updated: 2025/02/24 18:16:26 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "pipex.h"

void	child_proc_fir_h(int *pipefd, char **argv, int *pipefd1, char ***cmd1);
void	p_error_b(char *s, int *pipefd, int *pipefd1);
