/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <ahalfrun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:18:45 by ahalfrun          #+#    #+#             */
/*   Updated: 2022/02/23 17:02:12 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_n_exit(t_game *game)
{
	clean_map(game);
	exit(1);
}	

void	parsing(char **argv, t_game *game)
{
	int		fd;
	int		i;
	char	*str;

	check_fd_map(argv, game);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	game->map = (char **)malloc(sizeof(char *) * game->y);
	while (i < game->y)
	{
		str = get_next_line(fd);
		game->map[i] = str;
		if (game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
		{
			game->map[i] = ft_substr(game->map[i], 0,
					ft_strlen(game->map[i]) - 1);
			if (!(game->map[i]))
				clean_n_exit(game);
			free(str);
		}
		i++;
	}
	close(fd);
}

int	check_x(t_game *game)
{
	size_t	x;
	size_t	x_new;
	int		counter_y;
	int		check;

	check = 1;
	counter_y = game->y - 1;
	x = ft_strlen(game->map[counter_y]);
	while (counter_y != 0)
	{
		x_new = ft_strlen(game->map[counter_y - 1]);
		if (x != x_new)
			check = 0;
		counter_y--;
	}
	if (check == 1)
		game->x = ft_strlen(game->map[game->y - 1]);
	return (check);
}

int	check_sur(t_game *game)
{
	int	check;
	int	counter;

	check = 1;
	counter = game->x - 1;
	while (counter >= 0)
	{
		if ((game->map[0][counter] != '1')
			|| (game->map[game->y - 1][counter] != '1'))
			check = 0;
		counter--;
	}
	counter = game->y - 1;
	while (counter >= 0)
	{
		if ((game->map[counter][0] != '1')
			|| (game->map[counter][game->x - 1] != '1'))
			check = 0;
		counter--;
	}
	return (check);
}
