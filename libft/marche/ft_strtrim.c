/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:26:11 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/17 12:40:30 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start(char const *s1, char const *set)
{
	int	start;
	size_t	i;

	i = 0;
	start = -1;
	while (s1[i] != '\0' && start == -1)
	{
		if (ft_strchr(set, s1[i]) != NULL)
			i++;
		else
			start = i;
	}
//	if (s1[i] == '\0')
//		start = ft_strlen(s1);
	return (start);
}

int	ft_end(char const *s1, char const *set, int start, size_t i)
{
	int	end;

	end = -1;
	while (s1[i] != s1[start] && end == -1)
	{
		if (ft_strchr(set, s1[i]) != NULL)
			i--;
		else
			end = i;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*s2;
	int	start;
	int	end;
	int	j;

	if (s1 != NULL)
	{
		start = ft_start(s1, set);
		i = ft_strlen(s1) - 1;
		end = ft_end(s1, set, start, i);
		s2 = (char *)malloc((end - start + 2) * sizeof(char));
		if (s2 == NULL)
			return (NULL);
		j = 0;
		while (j != (end - start + 1))
		{
			s2[j] = s1[start + j];
			j++;
		}
		s2[j] = '\0';
		return (s2);
	}
	return (NULL);

}
