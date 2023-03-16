/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:52:51 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/16 17:46:23 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Ft_printf/ft_printf.h"
# include "../Ft_printf/libft/libft.h"
# include <unistd.h>
# include <mlx.h>
# include <stdbool.h>

# define NOT_RECTANGULAR 1
# define WRONG_NAME 2
# define WRONG_ARGS 3
# define LEAK_IN_THE_WALLS 4
# define WRONG_LETTERS 5
# define PLAYER_ERROR 6
# define EXIT_ERROR 7
# define COLLECTIBLE_ERROR 8
# define NO_ACCESS_TO_COLLECTIBLE 9
# define NO_ACESS_TO_EXIT 10

# define W 119 
# define S 115 
# define D 100 
# define A 97

typedef struct s_map
{
	size_t		len_line;
	size_t		nb_line;
	char		**map_in_tab;
	char		**map_cloned;
	char		*buf;
	size_t		x_p;
	size_t		y_p;
	size_t		x_e;
	size_t		y_e;
	size_t		p;
	size_t		c;
	size_t		e;
	size_t		i_p;
	size_t		i_c;
	size_t		i_e;
}				t_map;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr_wall;
	void	*img_ptr_back;
	void	*img_ptr_player;
	void	*img_ptr_col;
	void	*img_ptr_exit;
	void	*img_ptr_exit_2;
	int		width;
	int		height;
	int		count_move;
	t_map	map;
}				t_win;

bool	check_map(int argc, char **argv, t_win *win);
bool	print_error_msg(int key);
bool	check_arg(int argc);
bool	check_name(char **argv);
bool	check_file(char **argv, t_win *win);
bool	check_rectangle(int fd, t_win *win);
char	*get_next_line_map(int fd);
bool	check_wall(char **argv, t_win *win);
bool	check_left_and_right(int fd, t_win *win);
bool	check_first_and_last(int fd, char *str, t_win *win);
void	make_map_tab(char **argv, t_win *win);
bool	check_letters(char **argv, t_win *win);
bool	go_on_the_caracter(t_win *win);
bool	is_finishable(t_win *win);
void	backtracking(t_win *win, int y, int x);

int		create_window(t_win *win);
void	open_img(t_win *win);
void	put_img_to_win(t_win *win);
int		deal_key(int key, t_win *win);
bool	check_if_exit_free(t_win *win);
bool	check_if_wall(t_win *win);
void	replace_player_up(t_win *win);
void	replace_player_down(t_win *win);
void	replace_player_left(t_win *win);
void	replace_player_right(t_win *win);
void	deal_w_and_s(int key, t_win *win);
void	deal_d_and_a(int key, t_win *win);
int		deal_key(int key, t_win *win);
int		destroy(t_win *win);
void    destroy_free(t_win *win);

#endif
