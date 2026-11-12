/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale <ale@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:36:46 by ade-ross          #+#    #+#             */
/*   Updated: 2025/02/27 18:51:48 by ale              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_mlx_data *data)
{
	data->wall = load_one(data, "./images/wall.xpm");
	data->floor = load_one(data, "./images/backgr.xpm");
	data->player = load_one(data, "./images/player.xpm");
	data->play_u = load_one(data, "./images/play_u.xpm");
	data->play_r = load_one(data, "./images/play_r.xpm");
	data->play_l = load_one(data, "./images/play_l.xpm");
	data->ice_cr = load_one(data, "./images/ice_cr.xpm");
	data->exit = load_one(data, "./images/exit.xpm");
}

void	print_moves(t_mlx_data *data)
{
	char	*moves_str;

	moves_str = ft_itoa(data->n_of_moves);
	put_image(data, data->wall, 0, 0);
	put_image(data, data->wall, 64, 0);
	mlx_string_put(data->mlx, data->win, 10, 10, 0x000000, "Moves: ");
	mlx_string_put(data->mlx, data->win, 100, 10, 0x000000, moves_str);
	free(moves_str);
}
