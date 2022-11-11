/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:26:10 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/11 15:44:24 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (s2[0] == '\0')
		return (s1);
	i = 0;
	while (i < n && s1)
	{
		j = 0;
		while (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return (&s1[i - j]);
		i = i - j + 1;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main()
{
	char	s1[]= "Je sais pas";
	char	s2[]= "sais";

	printf ("%s\n", ft_strnstr(s1, s2, 9));
	printf ("%s\n", strnstr(s1, s2, 9));
}
*/
