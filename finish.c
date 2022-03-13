/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:54:37 by ahalfrun          #+#    #+#             */
/*   Updated: 2022/02/23 17:02:55 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_map(t_game *game)
{
	int	counter;

	counter = 0;
	while (counter < game->y)
	{
		free(game->map[counter]);
		counter++;
	}
	free(game->map);
}

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_1);
	mlx_destroy_image(game->mlx, game->img_0);
	mlx_destroy_image(game->mlx, game->img_c);
	mlx_destroy_image(game->mlx, game->img_e);
	mlx_destroy_image(game->mlx, game->img_p);
}

int	close_game(t_game *game)
{
	clean_map(game);
	destroy_images(game);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
	return (0);
}

void	ft_match_images(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	game->img_1 = mlx_xpm_file_to_image(game->mlx,
			"./img/1.XPM", &width, &height);
	game->img_0 = mlx_xpm_file_to_image(game->mlx,
			"./img/0.XPM", &width, &height);
	game->img_c = mlx_xpm_file_to_image(game->mlx,
			"./img/C.XPM", &width, &height);
	game->img_e = mlx_xpm_file_to_image(game->mlx,
			"./img/E.XPM", &width, &height);
	game->img_p = mlx_xpm_file_to_image(game->mlx,
			"./img/P.XPM", &width, &height);
	game->img_win = mlx_xpm_file_to_image(game->mlx,
			"./img/WIN.XPM", &width, &height);
}

int	rendering(t_game *game, int c, int r)
{
	while (r < game->y)
	{
		c = 0;
		while (c < game->x)
		{
			if (game->map[r][c] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_1, c * 65, r * 65);
			if (game->map[r][c] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_0, c * 65, r * 65);
			if (game->map[r][c] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_c, c * 65, r * 65);
			if (game->map[r][c] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_e, c * 65, r * 65);
			if (game->map[r][c] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_p, c * 65, r * 65);
			c++;
		}
		r++;
	}
	return (0);
}
