/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:38:13 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/11 15:42:47 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char s1[] = "ACAAAAAA";
	char s2[] = "AAAA";

	printf("%d\n", strncmp(s1, s2, 4));
	printf("%d\n", ft_strncmp(s1, s2, 4));
}
*/
