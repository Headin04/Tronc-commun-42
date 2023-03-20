/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:05:44 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/17 17:19:02 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	check_left_and_right(int fd, t_win *win)
{
	char	*str;
	int		len;
	size_t	i;

	i = 1;
	str = get_next_line_map(fd);
	if (i++ == win->map.nb_line - 1)
		return (check_first_and_last(fd, str, win));
	while (str != NULL)
	{
		len = win->map.len_line;
		if (str[0] != '1' || str[len - 1] != '1')
		{
			close(fd);
			return (print_error_msg(LEAK_IN_THE_WALLS));
		}
		if (i++ == win->map.nb_line - 1)
			return (check_first_and_last(fd, str, win));
		free(str);
		str = get_next_line_map(fd);
	}
	return (true);
}

bool	check_first_and_last(int fd, char *str, t_win *win)
{
	size_t	i;

	i = 0;
	while (str[i] == '1')
	i++;
	if (i != win->map.len_line)
	{
		close (fd);
		free(str);
		return (print_error_msg(LEAK_IN_THE_WALLS));
	}
	free(str);
	return (true);
}

bool	check_wall(char **argv, t_win *win)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDWR);
	str = get_next_line_map(fd);
	if (check_first_and_last(fd, str, win) == false)
		return (false);
	if (check_left_and_right(fd, win) == false)
		return (false);
	close(fd);
	return (true);
}
