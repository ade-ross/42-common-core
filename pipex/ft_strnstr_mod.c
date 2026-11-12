/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:09:36 by ade-ross          #+#    #+#             */
/*   Updated: 2025/02/20 00:19:45 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strnstr_mod(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!big || !little)
	{
		free(big);
		free(little);
		exit(1);
	}
	while (*big != '\0' && count < len)
	{
		i = 0;
		while (big[i] == little[i] && (count + i) < len)
		{
			if (little[i + 1] == '\0')
				return (count);
			i++;
		}
		big++;
		count++;
	}
	return (-1);
}

