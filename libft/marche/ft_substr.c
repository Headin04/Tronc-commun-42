/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:17:13 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/17 14:40:45 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	final_size;
	char	*dest;

	dest = NULL;
	if (s != NULL)
	{
		if (ft_strlen(s) - start >= len)
			final_size = len;
		else
			final_size = ft_strlen(s) - start;
		dest = (char *)malloc((final_size +1) * sizeof(char));
		if (dest != NULL)
			ft_strlcpy(dest, s + start, final_size + 1);
	}
	return(dest);	
}
