/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:12:56 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/08 17:12:20 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
int	main()
{
	char	test[]= "jenaijamais";
	char	test2[]= "vrai";

	printf("%s", (char *)ft_memcpy(test, test2, 4));
	printf("%d", '\n');
	printf("%s", (char *)memcpy(test, test2, 4));
}
*/
