/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:09:55 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/09 13:25:36 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
			return (((char *)s1)[i] - ((char *)s2)[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int	main()
{
	char	s1[]= "AAAAA\0CAA";
	char	s2[]= "AAAAA\0DAA";

	printf("%d\n", ft_memcmp(s1, s2, 9));
	printf("%d\n", memcmp(s1, s2, 9));
}
*/
