/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:31:41 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/17 12:02:20 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t m, size_t n)
{
	size_t	mn;
	void	*dest;

	dest = NULL;
	mn = m * n;
	if (mn == 0 || m <= SIZE_MAX/n)
		dest = (void *)malloc(mn * sizeof(void));
	if (dest == NULL)
		return (NULL);
	else
		ft_bzero(dest, mn);
	return(dest);
}

/*
int main ()
{

    size_t nb = 5;
    size_t *liste = NULL;

    liste = calloc(nb, sizeof(size_t));
    for (size_t j = 0; j < nb; j++)
    printf("[%ld]", liste[j]);
    size_t nb = 5;
    size_t *liste = NULL;

    liste = ft_calloc(nb, sizeof(size_t));
    for (size_t j = 0; j < nb; j++)
    printf("[%ld]", liste[j]);


    return (0);
}
*/
