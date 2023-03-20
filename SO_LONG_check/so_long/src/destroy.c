/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:17:06 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/20 14:32:48 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_win *win)
{
	if (win->img_ptr_wall != NULL)
		mlx_destroy_image(win->mlx_ptr, win->img_ptr_wall);
	if (win ->img_ptr_back != NULL)
		mlx_destroy_image(win->mlx_ptr, win->img_ptr_back);
	if (win->img_ptr_player != NULL)
		mlx_destroy_image(win->mlx_ptr, win->img_ptr_player);
	if (win->img_ptr_col != NULL)
		mlx_destroy_image(win->mlx_ptr, win->img_ptr_col);
	if (win->img_ptr_exit != NULL)
		mlx_destroy_image(win->mlx_ptr, win->img_ptr_exit);
	if (win->img_ptr_exit_2 != NULL)
		mlx_destroy_image(win->mlx_ptr, win->img_ptr_exit_2);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	destroy_free(win);
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	destroy_free(t_win *win)
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
