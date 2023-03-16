/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:54:18 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/15 19:45:27 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	print_error_msg(int key)
{
	if (key == NOT_RECTANGULAR)
		ft_dprintf("Error.\nFile not existing or map not rectangular.\n");
	if (key == WRONG_NAME)
		ft_dprintf("Error\nWrong name of file\n");
	if (key == WRONG_ARGS)
		ft_dprintf("Error\nNot enough or too much arguments\n");
	if (key == LEAK_IN_THE_WALLS)
		ft_dprintf("Error\nLeak in the walls\n");
	if (key == WRONG_LETTERS)
		ft_dprintf("Error\nWrong caracter in map\n");
	if (key == PLAYER_ERROR)
		ft_dprintf("Error\nNone or too much player\n");
	if (key == EXIT_ERROR)
		ft_dprintf("Error\nNone or too much exit\n");
	if (key == COLLECTIBLE_ERROR)
		ft_dprintf("Error\nNo collectible\n");
	if (key == NO_ACCESS_TO_COLLECTIBLE)
		ft_dprintf("Error\nCollectible blocked\n");
	if (key == NO_ACESS_TO_EXIT)
		ft_dprintf("Error\nExit blocked\n");
	return (false);
}

bool	check_map(int argc, char **argv, t_win *win)
{
	if (check_arg(argc) == false)
		return (false);
	if (check_name(argv) == false)
		return (false);
	if (check_file(argv, win) == false)
		return (false);
	if (check_wall(argv, win) == false)
		return (false);
	if (check_letters(argv, win) == false)
		return (false);
	if (is_finishable(win) == false)
		return (false);
	return (true);
}
