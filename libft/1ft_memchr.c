/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1ft_memchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:29:30 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/15 14:05:01 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(char *)(s + i) == '\0')
			return (NULL);
		if (*(char *)(s + i) == c)
			return ((char *)(s + i));
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
