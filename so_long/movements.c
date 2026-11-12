/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:59:49 by ale               #+#    #+#             */
/*   Updated: 2025/02/25 22:31:13 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_up(t_mlx_data *data)
{
	if (data->map[data->ps.y - 1][data->ps.x] != '1')
	{
		if (data->map[data->ps.y - 1][data->ps.x] == 'C')
		{
			data->n_of_collectibles--;
			data->map[data->ps.y - 1][data->ps.x] = '0';
		}
		if (data->prev_is_exit == 1)
		{
			put_image(data, data->exit, data->ps.x * 64, data->ps.y * 64);
			data->prev_is_exit = 0;
		}
		else
			put_image(data, data->floor, data->ps.x * 64, data->ps.y * 64);
		put_image(data, data->player, data->ps.x * 64, data->ps.y * 64 - 64);
		if (data->map[data->ps.y - 1][data->ps.x] == 'E')
		{
			if (data->n_of_collectibles == 0)
				close_game(data);
			data->prev_is_exit = 1;
		}
		data->ps.y = data->ps.y - 1;
	}
	print_moves(data);
}

void	move_player_down(t_mlx_data *data)
{
	if (data->map[data->ps.y + 1][data->ps.x] != '1')
	{
		if (data->map[data->ps.y + 1][data->ps.x] == 'C')
		{
			data->n_of_collectibles--;
			data->map[data->ps.y + 1][data->ps.x] = '0';
		}
		if (data->prev_is_exit == 1)
		{
			put_image(data, data->exit, data->ps.x * 64, data->ps.y * 64);
			data->prev_is_exit = 0;
		}
		else
			put_image(data, data->floor, data->ps.x * 64, data->ps.y * 64);
		put_image(data, data->player, data->ps.x * 64, data->ps.y * 64 + 64);
		if (data->map[data->ps.y + 1][data->ps.x] == 'E')
		{
			if (data->n_of_collectibles == 0)
				close_game(data);
			data->prev_is_exit = 1;
		}
		data->ps.y = data->ps.y + 1;
	}
	print_moves(data);
}

void	move_player_left(t_mlx_data *data)
{
	if (data->map[data->ps.y][data->ps.x - 1] != '1')
	{
		if (data->map[data->ps.y][data->ps.x - 1] == 'C')
		{
			data->n_of_collectibles--;
			data->map[data->ps.y][data->ps.x - 1] = '0';
		}
		if (data->prev_is_exit == 1)
		{
			put_image(data, data->exit, data->ps.x * 64, data->ps.y * 64);
			data->prev_is_exit = 0;
		}
		else
			put_image(data, data->floor, data->ps.x * 64, data->ps.y * 64);
		put_image(data, data->player, data->ps.x * 64 - 64, data->ps.y * 64);
		if (data->map[data->ps.y][data->ps.x - 1] == 'E')
		{
			if (data->n_of_collectibles == 0)
				close_game(data);
			data->prev_is_exit = 1;
		}
		data->ps.x = data->ps.x - 1;
	}
	print_moves(data);
}

void	move_player_right(t_mlx_data *data)
{
	if (data->map[data->ps.y][data->ps.x + 1] != '1')
	{
		if (data->map[data->ps.y][data->ps.x + 1] == 'C')
		{
			data->n_of_collectibles--;
			data->map[data->ps.y][data->ps.x + 1] = '0';
		}
		if (data->prev_is_exit == 1)
		{
			put_image(data, data->exit, data->ps.x * 64, data->ps.y * 64);
			data->prev_is_exit = 0;
		}
		else
			put_image(data, data->floor, data->ps.x * 64, data->ps.y * 64);
		put_image(data, data->player, data->ps.x * 64 + 64, data->ps.y * 64);
		if (data->map[data->ps.y][data->ps.x + 1] == 'E')
		{
			if (data->n_of_collectibles == 0)
				close_game(data);
			data->prev_is_exit = 1;
		}
		data->ps.x = data->ps.x + 1;
	}
	print_moves(data);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		close_game(data);
	if (keysym == XK_w || keysym == XK_Up)
		move_player_up(data);
	if (keysym == XK_s || keysym == XK_Down)
		move_player_down(data);
	if (keysym == XK_a || keysym == XK_Left)
		move_player_left(data);
	if (keysym == XK_d || keysym == XK_Right)
		move_player_right(data);
	data->n_of_moves++;
	return (0);
}
