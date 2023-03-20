/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:17:51 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/20 14:27:30 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_count_to_win(t_win *win)
{
	char	*tmp;

	tmp = ft_itoa(win->count_move);
	mlx_set_font(win->mlx_ptr, win->win_ptr, "10x20");
	mlx_pitw(0, 0, win, win->img_ptr_wall);
	win->n = mlx_string_put(win->mlx_ptr, win->win_ptr, 20, 32, 0xFFFFFF, tmp);
	free(tmp);
}

void	check_xpm_bonus(t_win *win)
{
	if (win->img_ptr_exit_2 == NULL || win ->img_ptr_back == NULL
		|| win->img_ptr_col == NULL || win->img_ptr_exit == NULL
		|| win->img_ptr_player == NULL || win->img_ptr_wall == NULL
		|| win->img_ptr_tile1 == NULL || win->img_ptr_tile2 == NULL
		|| win->img_ptr_tile3 == NULL || win->img_ptr_tile4 == NULL)
	{
		ft_dprintf("Error\nnot possile to open an image.\n");
		destroy_bonus(win);
	}
}
