/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:17:13 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/16 14:18:29 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	final_size;
	char	*dest;
	size_t	i;

	if (ft_strlen(s) - start > len)
		final_size = len;
	else
		final_size = ft_strlen(s) - start;
	dest = (char *)malloc(final_size * sizeof(char));
	if (dest == '\0')
		return (NULL);
	i = 0;
	else
		ft_strlcpy(dest, s, final_size);
	return(dest);	
}
