/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:17:58 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/09 16:34:49 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;

	if (size != '\0')
	{
		while (dest[i])
			i++;

		printf("%s\n", dest);
		while (j < size && src[j] !='\0')
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
		i = 0;
		while (dest[i] != '\0')
			i++;
		printf("%s\n", dest);
	}
	return (i);
}

#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	char	dest[]= "ravie";
	char	src[]= "je suis";

	printf("%ld\n", strlcat(dest, src, 2));
	printf("%ld\n", ft_strlcat(dest, src, 2));

}