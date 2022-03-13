/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <ahalfrun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:55:32 by ahalfrun          #+#    #+#             */
/*   Updated: 2022/02/23 16:12:52 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>             //fd
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"

typedef struct s_game
{
	char	**map;
	int		x;
	int		height;
	int		width;
	int		y;
	int		start_p;
	int		moves;
	int		col;
	int		has_col;
	int		win;
	int		exit;
	void	*mlx;
	void	*mlx_win;
	void	*img_0;
	void	*img_1;
	void	*img_p;
	void	*img_e;
	void	*img_c;
	void	*img_win;
}	t_game;

# define W	13
# define S	1
# define A	0
# define D	2
# define ESC 	53

void	init_game(t_game *game);
void	extention(char **argv);
void	check_fd_map(char **argv, t_game *game);
int		put_to_window(t_game *game);
int		main(int argc, char **argv);
void	parsing(char **argv, t_game *game);
int		check_x(t_game *game);
int		check_sur(t_game *game);
int		meetcep(t_game *game);
void	no01cep(t_game *game);
int		check_p(t_game *game);
int		errors(t_game *game);
void	press_w(t_game *game);
void	press_s(t_game *game);
void	press_d(t_game *game);
void	press_a(t_game *game);
int		keyboard(int keycode, t_game *game);
void	destroy_images(t_game *game);
void	clean_map(t_game *game);
int		close_game(t_game *game);
void	ft_match_images(t_game *game);
int		rendering(t_game *game, int c, int r);

#endif
