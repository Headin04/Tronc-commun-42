/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:38:04 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/02/03 14:25:41 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <bsd/string.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 100
# endif

char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strnjoin(char *s1, char *s2, size_t size);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t m, size_t n);
bool	does_buf_contain_line(char *buf, char **final, char *rest);
bool	does_rest_contain_line(char *rest, char **final);
char	*get_next_line(int fd);

#endif
