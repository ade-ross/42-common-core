/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale <ale@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 02:00:52 by ale               #+#    #+#             */
/*   Updated: 2025/02/27 18:39:34 by ale              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_mlx_data *data)
{
	data->wall = load_one(data, "./images/wall.xpm");
	data->floor = load_one(data, "./images/backgr.xpm");
	data->player = load_one(data, "./images/player.xpm");
	data->ice_cr = load_one(data, "./images/ice_cr.xpm");
	data->exit = load_one(data, "./images/exit.xpm");
}

void	print_moves(t_mlx_data *data)
{
	ft_printf("Moves: %d\n", data->n_of_moves);
}
