/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:31:41 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/24 15:27:59 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t m, size_t n)
{
	size_t	mn;
	void	*dest;

	dest = NULL;
	mn = m * n;
	if (m <= SIZE_MAX / n)
		dest = (void *)malloc(mn * sizeof(void));
	if (dest == NULL)
		return (NULL);
	else
		ft_bzero(dest, mn);
	return (dest);
}
// (mn == 0 
