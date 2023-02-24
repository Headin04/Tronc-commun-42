/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:21:55 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/01/11 15:55:59 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#define HEX_BASE 16

char	*ft_strnjoin(char *s1, char const *s2, size_t size)
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

static long int	get_len(long int n)
{
	long int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= (-1);
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoctoa(int n, t_list **lst)
{
	char	c;
	char	*res;

	c = n;
	if (n == 0)
		(*lst)->nullc = 1;
	res = NULL;
	res = malloc(sizeof(unsigned char) * 1 + 1);
	if (res == NULL)
		return (NULL);
	res[0] = c;
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	long	len;
	char	*dest;
	long	n_bis;

	n_bis = n;
	len = get_len(n_bis);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	len--;
	if (n_bis == 0)
		dest[0] = '0';
	if (n_bis < 0)
	{
		dest[0] = '-';
		n_bis *= (-1);
	}
	while (n_bis > 0)
	{
		dest[len] = n_bis % 10 + 48;
		n_bis /= 10;
		len--;
	}
	return (dest);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	len;
	char			*dest;

	len = get_len(n);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	len--;
	if (n == 0)
		dest[0] = '0';
	while (n > 0)
	{
		dest[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (dest);
}
