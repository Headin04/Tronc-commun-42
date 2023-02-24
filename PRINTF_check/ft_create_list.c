/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:15:33 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/01/10 17:38:21 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

void	ft_nn_text(const char **str, t_list **lst)
{
	char	*dest;
	int		i;
	t_list	*tmp;

	i = 1;
	while (((*str)[i]) != '%' && ((*str)[i]) != '\0')
		i++;
	tmp = NULL;
	dest = NULL;
	tmp = ft_lstnew(ft_strnjoin(dest, *str, i));
	ft_lstadd_back(lst, tmp);
	*str += i;
}

void	ft_nn_percent(const char **str, t_list **lst)
{
	char	*dest;
	size_t	i;
	t_list	*tmp;

	dest = NULL;
	i = 1;
	while (ft_strchr("cspiudxXi%", ((*str)[i])) == NULL && ((*str)[i]) != '\0')
		++i;
	tmp = ft_lstnew(ft_strnjoin(dest, *str, i + 1));
	ft_lstadd_back(lst, tmp);
	*str += i + 1;
}

t_list	*ft_lst(const char *str)
{
	t_list	*lst;

	lst = NULL;
	while (*str != '\0')
	{
		if (*str == '%')
			ft_nn_percent(&str, &lst);
		else
			ft_nn_text(&str, &lst);
	}
	return (lst);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	t_list	*lst;
	va_list	args;

	va_start(args, str);
	i = 0;
	lst = NULL;
	if (str == NULL)
		return (-1);
	lst = ft_lst(str);
	ft_scan_list(&lst, args);
	i = ft_print(lst);
	va_end(args);
	return (i);
}
