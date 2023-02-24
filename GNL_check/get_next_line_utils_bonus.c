/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:30:23 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/02/03 14:30:47 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (size != '\0')
	{
		while (i + 1 < size && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		i++;
	}
	while (src[a] != '\0')
		a++;
	return (a);
}

char	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	char	*s3;
	size_t	lens1;
	size_t	lens2;

	lens1 = 0;
	lens2 = 0;
	if (s1 != NULL)
		lens1 = ft_strlen(s1);
	if (s2 != NULL)
		lens2 = size;
	s3 = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	else
	{
		if (s1 != NULL)
			ft_strlcpy(s3, s1, lens1 + 1);
		if (s2 != NULL)
			ft_strlcpy((s3 + lens1), s2, (lens2 + 1));
	}
	if (s1 != NULL)
		free (s1);
	return (s3);
}
