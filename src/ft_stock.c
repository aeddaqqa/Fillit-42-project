/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:20:15 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/20 04:20:55 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_cord			*ft_find_cord(char **tab)
{
	int		i;
	int		j;
	int		k;
	t_cord	*x;

	if (!(x = (t_cord *)malloc(sizeof(t_cord) * 4)))
		return (NULL);
	i = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#' || (tab[i][j] >= 'A' && tab[i][j] <= 'Z'))
			{
				x[k].x = i;
				x[k].y = j;
				k++;
			}
			j++;
		}
		i++;
	}
	return (x);
}

t_cord			ft_cordcmp(t_cord *t)
{
	int		i;
	int		z;
	t_cord	k;

	i = 1;
	k.x = t[0].x;
	z = t[0].y;
	while (i < 4)
	{
		if (t[i].y < z)
			z = t[i].y;
		i++;
	}
	k.y = z;
	return (k);
}

char			**ft_stock(char **tab)
{
	char		**fraiche;
	int			i;
	t_cord		*c;
	t_cord		k;
	static char	n;

	if (!n)
		n = 'A';
	c = ft_find_cord(tab);
	fraiche = ft_creat_map(4);
	i = 0;
	k = ft_cordcmp(c);
	while (i < 4)
	{
		fraiche[c[i].x - k.x][c[i].y - k.y] = n;
		i++;
	}
	n++;
	free(c);
	return (fraiche);
}

t_tetri			*ft_newtetri(char *str)
{
	t_tetri		*f;
	static int	j;
	char		**tmp;

	if (!j)
		j = 0;
	if (!(f = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	str[20 + j] = '\0';
	tmp = ft_strsplit_i(str, '\n', j);
	j += 21;
	f->tab = ft_stock(tmp);
	f->c = ft_find_cord(f->tab);
	f->next = NULL;
	ft_free_tab(tmp);
	return (f);
}

t_tetri			*ft_lstetri(char *str, int c)
{
	t_tetri		*fraiche;
	t_tetri		*tmp;

	fraiche = ft_newtetri(str);
	tmp = fraiche;
	while (--c)
	{
		tmp->next = ft_newtetri(str);
		tmp = tmp->next;
	}
	return (fraiche);
}
