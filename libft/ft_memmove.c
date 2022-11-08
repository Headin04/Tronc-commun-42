/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:18:52 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/08 17:35:53 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t	i;
	unsigned char *temp;

	i = 0;
	while (i != n)
	{
		temp[i] = ((unsigned char *)src)[i];
		i++;
	}
	i = 0;
	while (i != n)
	{
		((unsigned char *)dest)[i] = temp[i];
		i++;
	}
	return (dest);
}

int	main()
{
	char	test[]= "j'ai la flemme
}
