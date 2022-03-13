/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <ahalfrun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:01:08 by ahalfrun          #+#    #+#             */
/*   Updated: 2022/02/23 17:01:28 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->y = 0;
	game->x = 0;
	game->exit = 0;
	game->col = 0;
	game->start_p = 0;
	game->width = 0;
	game->height = 0;
	game->moves = 0;
	game->win = 0;
	game->has_col = 0;
}

void	extention(char **argv)
{
	if (argv[1][ft_strlen(argv[1]) - 1] != 'r'
		|| (argv[1][ft_strlen(argv[1]) - 2]) != 'e'
		|| (argv[1][ft_strlen(argv[1]) - 3]) != 'b'
		|| (argv[1][ft_strlen(argv[1]) - 4]) != '.')
	{
		printf("Error\nWrong extention of file\n"),
		exit(1);
	}
}

void	check_fd_map(char **argv, t_game *game)
{
	int		fd;
	char	*str;

	extention(argv);
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		game->y++;
		free(str);
		str = get_next_line(fd);
	}
	if (game->y == 0)
	{
		printf("Error\nThe map is empty\n"),
		close(fd),
		exit(1);
	}
	close(fd);
}

int	put_to_window(t_game *game)
{
	static int	counter;

	mlx_clear_window(game->mlx, game->mlx_win);
	if (game->win == 1)
	{
		counter++;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_win,
			game->x * 1 - 48, game->y * 1 - 48);
		if (counter == 250)
			close_game(game);
	}
	else
		rendering(game, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		x;

	x = ft_strlen(argv[1]);
	if (argc != 2)
	{
		printf("%s", "Wrong number of arguments\n");
		exit(1);
	}
	init_game(&game);
	parsing(argv, &game);
	errors(&game);
	game.mlx = mlx_init();
	ft_match_images(&game);
	game.mlx_win = mlx_new_window(game.mlx, game.x * 65,
			game.y * 65, "so_long");
	printf("Moves: %d\n", game.moves);
	mlx_hook(game.mlx_win, 2, 0, keyboard, &game);
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, put_to_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
