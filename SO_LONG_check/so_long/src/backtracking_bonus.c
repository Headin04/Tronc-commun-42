/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:22:39 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/17 17:18:47 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	backtracking(t_win *win, int y, int x)
{
	if (win->map.map_cloned[y][x] == '2')
		return ;
	else if (win->map.map_cloned[y][x] == '1')
		return ;
	else if (win->map.map_cloned[y][x] == 'P')
		win->map.map_cloned[y][x] = '2';
	else if (win->map.map_cloned[y][x] == '0')
		win->map.map_cloned[y][x] = '2';
	else if (win->map.map_cloned[y][x] == 'C')
	{
		win->map.i_c++;
		win->map.map_cloned[y][x] = '2';
	}
	else if (win->map.map_cloned[y][x] == 'E')
	{
		win->map.i_e++;
		win->map.map_cloned[y][x] = '1';
		return ;
	}
	backtracking(win, y, x + 1);
	backtracking(win, y, x - 1);
	backtracking(win, y + 1, x);
	backtracking(win, y - 1, x);
}

bool	is_finishable(t_win *win)
{
	size_t	x;
	size_t	y;

	x = win->map.x_p;
	y = win->map.y_p;
	backtracking(win, y, x);
	if (win->map.i_c != win->map.c)
		return (print_error_msg(NO_ACCESS_TO_COLLECTIBLE));
	if (win->map.i_e != 1)
		return (print_error_msg(NO_ACESS_TO_EXIT));
	if (win->map.i_c == win->map.c && win->map.i_e == win->map.e)
		return (true);
	return (false);
}
