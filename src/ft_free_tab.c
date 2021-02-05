/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 02:11:13 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/20 04:14:42 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	ft_free_lst(t_tetri **lst)
{
	t_tetri *tmp;

	while ((*lst))
	{
		tmp = (*lst)->next;
		ft_free_tab((*lst)->tab);
		free((*lst)->c);
		(*lst)->c = NULL;
		free(*lst);
		*lst = tmp;
	}
}
