/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:23:54 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/01/11 15:52:22 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

char	*ft_if_null(t_list **lst, char *str)
{
	char	*tmp;

	if (str == NULL)
	{
		tmp = malloc(sizeof(char) * 6 + 1);
		ft_strlcpy(tmp, "(null)", 7);
		return (tmp);
	}
	else
		return (ft_strjoin((*lst)->ncontent, str));
}

char	*ft_if_nil(size_t nbr)
{
	char	*tmp;

	if (nbr == 0)
	{
		tmp = malloc (sizeof(char) * 5 + 1);
		ft_strlcpy(tmp, "(nil)", 6);
		return (tmp);
	}
	else
		return (ft_size_to_hex(nbr));
}

void	ft_free(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		if ((*lst)->content != NULL)
			free((*lst)->content);
		if (((*lst)->ncontent) != NULL)
			free((*lst)->ncontent);
		if (*lst != NULL)
			free(*lst);
		*lst = tmp;
	}
}

size_t	ft_print(t_list	*lst)
{
	size_t	i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	while (lst != NULL)
	{
		if (lst->ncontent != NULL || lst->nullc == 1)
		{
			if (lst->ncontent != NULL)
				i += ft_putstr_fd(lst->ncontent, 1);
			if (lst->nullc == 1)
			{
				ft_putchar_fd('\0', 1);
				i++;
			}
		}
		else
			i += ft_putstr_fd(lst->content, 1);
		lst = lst->next;
	}
	lst = tmp;
	ft_free(&lst);
	return (i);
}
