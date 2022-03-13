/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:10:02 by ahalfrun          #+#    #+#             */
/*   Updated: 2022/02/20 21:13:30 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	press_w(t_game *game)
{
	int	h;

	h = game->height;
	if (game->map[h - 1][game->width] == 'C'
		|| game->map[h - 1][game->width] == '0'
		|| (game->map[h - 1][game->width] == 'E'
		&& game->has_col == game->col))
	{
		if (game->map[h - 1][game->width] == 'C')
			game->has_col++;
		game->moves++;
		game->height--;
		if (game->map[game->height][game->width] == 'E')
			game->win++;
		game->map[game->height][game->width] = 'P';
		game->map[h][game->width] = '0';
	}
}

void	press_s(t_game *game)
{
	int	h;

	h = game->height;
	if (game->map[h + 1][game->width] == 'C'
		|| game->map[h + 1][game->width] == '0'
		|| (game->map[h + 1][game->width] == 'E'
		&& game->has_col == game->col))
	{
		if (game->map[h + 1][game->width] == 'C')
			game->has_col++;
		game->moves++;
		game->height++;
		if (game->map[game->height][game->width] == 'E')
			game->win++;
		game->map[game->height][game->width] = 'P';
		game->map[h][game->width] = '0';
	}
}

void	press_d(t_game *game)
{
	int	w;

	w = game->width;
	if (game->map[game->height][w + 1] == 'C'
		|| game->map[game->height][w + 1] == '0'
		|| (game->map[game->height][w + 1] == 'E'
		&& game->has_col == game->col))
	{
		if (game->map[game->height][w + 1] == 'C')
			game->has_col++;
		game->moves++;
		game->width++;
		if (game->map[game->height][game->width] == 'E')
			game->win++;
		game->map[game->height][game->width] = 'P';
		game->map[game->height][w] = '0';
	}
}

void	press_a(t_game *game)
{
	int	w;

	w = game->width;
	if (game->map[game->height][w - 1] == 'C'
		|| game->map[game->height][w - 1] == '0'
		|| (game->map[game->height][w - 1] == 'E'
		&& game->has_col == game->col))
	{
		if (game->map[game->height][w - 1] == 'C')
			game->has_col++;
		game->moves++;
		game->width--;
		if (game->map[game->height][w - 1] == 'E')
			game->win++;
		game->map[game->height][game->width] = 'P';
		game->map[game->height][w] = '0';
	}
}

int	keyboard(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	if (keycode == W)
		press_w(game);
	if (keycode == D)
		press_d(game);
	if (keycode == A)
		press_a(game);
	if (keycode == S)
		press_s(game);
	if (keycode == W || keycode == D || keycode == A || keycode == S)
		printf("Moves:%d\n", game->moves);
	return (0);
}
