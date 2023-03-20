/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_caracter_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:18:16 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/17 17:18:55 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	make_map_tab(char **argv, t_win *win)
{
	int		fd;
	size_t	buffer_size;

	fd = open(argv[1], O_RDWR);
	buffer_size = (win->map.len_line * win->map.nb_line) * 2;
	win->map.buf = ft_calloc(buffer_size + 1, 1);
	read(fd, win->map.buf, buffer_size);
	win->map.map_in_tab = ft_split(win->map.buf, '\n');
	win->map.map_cloned = ft_split(win->map.buf, '\n');
	close(fd);
}

bool	go_on_the_caracter(t_win *win)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y != win->map.nb_line - 2)
	{
		x = -1;
		while (++x != win->map.len_line -1)
		{
			if (ft_strchr("10PCE\n", win->map.map_in_tab[y][x]) == NULL)
				return (print_error_msg(WRONG_LETTERS));
			if (win->map.map_in_tab[y][x] == 'P')
			{
				win->map.p++;
				win->map.x_p = x;
				win->map.y_p = y;
			}
			if (win->map.map_in_tab[y][x] == 'C')
				win->map.c++;
			if (win->map.map_in_tab[y][x] == 'E')
				win->map.e++;
		}
	}
	return (true);
}

bool	check_letters(char **argv, t_win *win)
{
	make_map_tab(argv, win);
	if (go_on_the_caracter(win) == false)
		return (false);
	if (win->map.p != 1)
		return (print_error_msg(PLAYER_ERROR));
	if (win->map.e != 1)
		return (print_error_msg(EXIT_ERROR));
	if (win->map.c == 0)
		return (print_error_msg(COLLECTIBLE_ERROR));
	return (true);
}
