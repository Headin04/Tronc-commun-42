/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:18:44 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/28 11:07:21 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc((size + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	else
	{
		ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
		ft_strlcat(s3, s2, size + 1);
	}
	return (s3);
}
