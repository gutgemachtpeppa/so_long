/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <ahalfrun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:04:06 by ahalfrun          #+#    #+#             */
/*   Updated: 2022/02/23 16:44:22 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	no01cep(t_game *game)
{
	int	i_r;
	int	i_l;

	i_r = game->y - 1;
	while (i_r >= 0)
	{
		i_l = game->x - 1;
		while (i_l >= 0)
		{
			if (game->map[i_r][i_l] != 'E' && game->map[i_r][i_l] != 'C'
				&& game->map[i_r][i_l] != 'P' && game->map[i_r][i_l] != '0'
				&& game->map[i_r][i_l] != '1')
			{
				printf("%s", "Error\nThe map's elements are wrong\n"),
				exit(1);
			}
			i_l--;
		}
		i_r--;
	}
}

int	check_p(t_game *game)
{
	int	check;

	check = 1;
	if (game->exit == 0 || game->col == 0 || game->start_p != 1)
	check = 0;
	return (check);
}

int	meetcep(t_game *game)
{
	int	i_r;
	int	i_l;

	i_r = game->y - 1;
	while (i_r >= 0)
	{
		i_l = game->x - 1;
		while (i_l >= 0)
		{
			if (game->map[i_r][i_l] == 'C')
				game->col++;
			if (game->map[i_r][i_l] == 'E')
				game->exit++;
			if (game->map[i_r][i_l] == 'P')
			{
				game->start_p++;
				game->width = i_l;
				game->height = i_r;
			}
			i_l--;
		}
		i_r--;
	}
	no01cep(game);
	return (check_p(game));
}

int	errors(t_game *game)
{
	int	check;

	check = 1;
	if (check_x(game) == 0 || meetcep(game) == 0
		|| check_sur(game) == 0)
	{
		if (check_x(game) == 0)
			printf("%s", "Error\nThe map is not rectangrular\n");
		else if (game->exit == 0)
			printf("%s", "Error\nThere is no exit\n");
		else if (game->col == 0)
			printf("%s", "Error\nThere is no collectives\n");
		else if (game->start_p != 1)
			printf("%s", "Error\nIncorrect number of starting positions\n");
		else if (check_sur(game) == 0)
			printf("%s", "Error\nThe map is not surrounded\n");
		if (check_x(game) == 0 || meetcep(game) == 0
			|| check_sur(game) == 0)
			exit(1);
		check--;
	}
	return (check);
}
