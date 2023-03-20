/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_name_rectangle_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:18:06 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/17 17:18:51 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	check_file(char **argv, t_win *win)
{
	int		fd;

	fd = open(argv[1], O_RDWR);
	if (check_rectangle(fd, win) == false)
		return (print_error_msg(NOT_RECTANGULAR));
	return (true);
}

bool	check_name(char **argv)
{
	char	*str;

	str = ft_strrchr(argv[1], '.');
	if (str == NULL)
		;
	else if (ft_strncmp(str, ".ber", 4) != 0)
		return (print_error_msg(2));
	return (true);
}

bool	check_arg(int argc)
{
	if (argc != 2)
		return (print_error_msg(WRONG_ARGS));
	return (true);
}

char	*get_next_line_map(int fd)
{
	char	*str;
	size_t	len;

	str = get_next_line(fd);
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}

bool	check_rectangle(int fd, t_win *win)
{
	size_t		len;
	char		*str;

	str = get_next_line_map(fd);
	win->map.nb_line++;
	if (str == NULL)
		return (false);
	len = ft_strlen(str);
	win->map.len_line = len;
	while (str != NULL && ft_strlen(str) == len)
	{
		free(str);
		str = get_next_line_map(fd);
		win->map.nb_line++;
	}
	close(fd);
	if (str == NULL)
		return (true);
	free(str);
	return (false);
}
