/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:07:34 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/20 12:54:27 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mlx_pitw(int x, int y, t_win *win, void *img_ptr)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		img_ptr, x * 64, y * 64);
}

void	put_img_to_win(t_win *win)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y <= win->map.nb_line - 2)
	{
		x = -1;
		while (++x <= win->map.len_line - 1)
		{
			if (win->map.map_in_tab[y][x] == '1')
				mlx_pitw(x, y, win, win->img_ptr_wall);
			else if (win->map.map_in_tab[y][x] == '0')
				mlx_pitw(x, y, win, win->img_ptr_back);
			else if (win->map.map_in_tab[y][x] == 'P')
				mlx_pitw(x, y, win, win->img_ptr_player);
			else if (win->map.map_in_tab[y][x] == 'E')
			{
				win->map.y_e = y;
				win->map.x_e = x;
				mlx_pitw(x, y, win, win->img_ptr_exit);
			}
			else if (win->map.map_in_tab[y][x] == 'C')
				mlx_pitw(x, y, win, win->img_ptr_col);
		}
	}
}

void	open_img(t_win *win)
{
	win->img_ptr_wall = mlx_xpm_file_to_image(win->mlx_ptr, "./img/box4.xpm",
			&win->width, &win->height);
	win->img_ptr_back = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/tile_back.xpm", &win->width, &win->height);
	win->img_ptr_player = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/face_char.xpm", &win->width, &win->height);
	win->img_ptr_col = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/col/col_1.xpm", &win->width, &win->height);
	win->img_ptr_exit = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/exit/exit_1.xpm", &win->width, &win->height);
	win->img_ptr_exit_2 = mlx_xpm_file_to_image(win->mlx_ptr,
			"./img/exit/exit_2.xpm", &win->width, &win->height);
}

int	create_window(t_win *win)
{
	win->mlx_ptr = mlx_init();
	if(win->mlx_ptr == NULL)
		return(0);
	win->win_ptr = mlx_new_window(win->mlx_ptr, (win->map.len_line) * 64,
			(win->map.nb_line - 1) * 64, "so_long");
	open_img(win);
	put_img_to_win(win);
	mlx_loop_hook(win->mlx_ptr, open_anim, win);
	mlx_key_hook(win->win_ptr, deal_key, win);
	mlx_hook(win->win_ptr, 17, (1L << 17), destroy_bonus, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
