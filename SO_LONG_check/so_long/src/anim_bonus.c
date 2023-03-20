/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:32 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/20 14:43:27 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	open_anim(t_win *win)
{
	win->img_ptr_tile1 = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/char_anim/anim1.xpm", &win->width, &win->height);
	win->img_ptr_tile2 = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/char_anim/anim2.xpm", &win->width, &win->height);
	win->img_ptr_tile3 = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/char_anim/anim3.xpm", &win->width, &win->height);
	win->img_ptr_tile4 = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/char_anim/anim4.xpm", &win->width, &win->height);
	check_xpm_bonus(win);
	put_anim_to_win(win);
	return (0);
}

void	put_anim_to_win(t_win *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_tile1,
		win->map.x_p * 64, win->map.y_p * 64);
	mlx_do_sync(win->mlx_ptr);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_tile2,
		win->map.x_p * 64, win->map.y_p * 64);
	usleep(50000);
	mlx_do_sync(win->mlx_ptr);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_tile3,
		win->map.x_p * 64, win->map.y_p * 64);
	usleep(200000);
	mlx_do_sync(win->mlx_ptr);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr_tile4,
		win->map.x_p * 64, win->map.y_p * 64);
	usleep(50000);
	mlx_do_sync(win->mlx_ptr);
}
