/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:31:41 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/15 16:26:03 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t m, size_t n)
{
	size_t	mn;
	void	*dest;

	mn = m * n;
	if (m == '\0' || n == '\0')
		return (NULL);
	dest = malloc(mn);
	if (dest == NULL)
		return (NULL);
	else
		ft_bzero(dest, mn);
	return(dest);
}

