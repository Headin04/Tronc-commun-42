/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:52:28 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/16 18:38:13 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	replace_player_up(t_win *win)
{
	if (win->map.map_in_tab[win->map.y_p][win->map.x_p] == 'C')
	{
		win->map.i_c--;
		win->map.map_in_tab[win->map.y_p][win->map.x_p] = '0';
	}
	win->count_move++;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_player,
		win->map.x_p * 64, win->map.y_p * 64);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_back,
		win->map.x_p * 64, (win->map.y_p + 1) * 64);
}

void	replace_player_down(t_win *win)
{
	if (win->map.map_in_tab[win->map.y_p][win->map.x_p] == 'C')
	{
		win->map.i_c--;
		win->map.map_in_tab[win->map.y_p][win->map.x_p] = '0';
	}
	win->count_move++;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_player,
		win->map.x_p * 64, win->map.y_p * 64);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_back,
		win->map.x_p * 64, (win->map.y_p - 1) * 64);
}

void	replace_player_left(t_win *win)
{
	if (win->map.map_in_tab[win->map.y_p][win->map.x_p] == 'C')
	{
		win->map.i_c--;
		win->map.map_in_tab[win->map.y_p][win->map.x_p] = '0';
	}
	win->count_move++;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_player,
		win->map.x_p * 64, win->map.y_p * 64);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_back,
		(win->map.x_p + 1) * 64, win->map.y_p * 64);
}

void	replace_player_right(t_win *win)
{
	if (win->map.map_in_tab[win->map.y_p][win->map.x_p] == 'C')
	{
		win->map.i_c--;
		win->map.map_in_tab[win->map.y_p][win->map.x_p] = '0';
	}
	win->count_move++;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_player,
		win->map.x_p * 64, win->map.y_p * 64);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_back,
		(win->map.x_p - 1) * 64, win->map.y_p * 64);
}

void    destroy_free(t_win *win)
{
    while (win->map.nb_line > 0)
    {
        free(win->map.map_in_tab[win->map.nb_line - 1]);
        free(win->map.map_cloned[win->map.nb_line - 1]);
        win->map.nb_line--;
    }
    free(win->map.map_in_tab);
    free(win->map.map_cloned);
    free(win->map.buf);
}