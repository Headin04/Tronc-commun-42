/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:04:36 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/08 20:14:31 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i]!= '\0')
		i++;
	while (str[i] != c)
	{
		if (i < 0)
			return (0);
		i--;
	}
	return (&str[i]);
}

/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char	tst[] = "baaaaaa";

	printf("%s\n",ft_strrchr(tst, 'b'));
	printf("%s", strrchr(tst, 'b'));
}
*/
