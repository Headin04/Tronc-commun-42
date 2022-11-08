/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:57:19 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/08 19:21:31 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
		return (c);
	}
	else
		return (c);
}

/*
#include <ctype.h>
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_toupper('a'));
	printf("%d\n", toupper('a'));
	printf("%d\n", ft_toupper('C'));
	printf("%d\n", toupper('C'));
	printf("%d\n", ft_toupper(' '));
	printf("%d\n", toupper(' '));
	printf("%d\n", ft_toupper('d'));
	printf("%d\n", toupper('d'));
}
*/
