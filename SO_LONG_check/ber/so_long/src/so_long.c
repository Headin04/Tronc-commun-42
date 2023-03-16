/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:53:59 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/16 16:50:11 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Ft_printf/libft/libft.h"

void	initialize_map(t_win *win)
{
	win->map.len_line = 0;
	win->map.nb_line = 0;
	win->map.map_in_tab = NULL;
	win->map.buf = NULL;
	win->map.x_p = 0;
	win->map.y_p = 0;
	win->map.p = 0;
	win->map.c = 0;
	win->map.e = 0;
	win->map.i_c = 0;
	win->map.i_e = 0;
	win->map.i_p = 0;
}

void	initialize_win(t_win *win)
{
	win->width = 64;
	win->height = 64;
	win->count_move = 0;
	initialize_map(win);
}

int	main(int argc, char **argv)
{
	t_win	win;

	initialize_win(&win);
	if (check_map(argc, argv, &win) == false)
		return (0);
	create_window(&win);
	return (0);
}
