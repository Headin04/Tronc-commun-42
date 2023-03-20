/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:39:40 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/20 13:41:01 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_if_wall(t_win *win)
{
	if (win->map.map_in_tab[win->map.y_p][win->map.x_p] == '1')
		return (false);
	return (true);
}

bool	check_if_exit_free(t_win *win)
{
	if (win->map.map_in_tab[win->map.y_p][win->map.x_p] == 'E'
		&& win->map.i_c != 0)
		return (true);
	return (false);
}

void	deal_w_and_s(int key, t_win *win)
{
	if (key == W && win->map.y_p >= 1)
	{
		ft_printf("up\n");
		--win->map.y_p;
		if (check_if_wall(win) == true && check_if_exit_free(win) == false)
			replace_player_up(win);
		else
			win->map.y_p++;
	}
	else if (key == S && win->map.y_p <= win->map.nb_line - 3)
	{
		ft_printf("down\n");
		++win->map.y_p;
		if (check_if_wall(win) == true && check_if_exit_free(win) == false)
			replace_player_down(win);
		else
			win->map.y_p--;
	}
}

void	deal_d_and_a(int key, t_win *win)
{
	if (key == D && win->map.x_p <= win->map.len_line - 1)
	{
		ft_printf("right\n");
		++win->map.x_p;
		if (check_if_wall(win) == true && check_if_exit_free(win) == false)
			replace_player_right(win);
		else
			win->map.x_p--;
	}
	else if (key == A && win->map.x_p >= 1)
	{
		ft_printf("left\n");
		--win->map.x_p;
		if (check_if_wall(win) == true && check_if_exit_free(win) == false)
			replace_player_left(win);
		else
			win->map.x_p++;
	}
}

int	deal_key(int key, t_win *win)
{
	if (key == W || key == S)
		deal_w_and_s(key, win);
	if (key == D || key == A)
		deal_d_and_a(key, win);
	if (win->map.i_c == 0)
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_exit_2,
			win->map.x_e * 64, win->map.y_e * 64);
	if (key == 65307 || (win->map.x_p == win->map.x_e
			&& win->map.y_p == win->map.y_e))
		destroy(win);
	ft_putnbr_fd(win->count_move, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
