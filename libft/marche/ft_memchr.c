/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:29:30 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/09 13:09:22 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n )
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main()
{
	char	test[]= "onestp2asbien";

	printf("%s\n", (char *)ft_memchr(test, '2', 8));
	printf("%s\n", (char *)memchr(test, '2', 8));
}
*/
