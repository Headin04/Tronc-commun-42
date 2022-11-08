/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:28:25 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/08 20:03:33 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int	i;
	char	*str;
	
	i = 0;
	str = (char *)s;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (&str[i]);
}

/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char	tst[] = "aaabaaaa";

	printf("%s",ft_strchr(tst, 'b'));
	printf("%s", strchr(tst, 'b'));
}
*/
