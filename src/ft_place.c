/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 09:58:36 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/20 04:16:06 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_cord		ft_possible(char **map, int i, int j, t_mps aba)
{
	int		z;
	t_cord	q;
	t_cord	e;
	t_tetri *t;

	t = aba.t;
	e.x = -1;
	e.y = -1;
	q.x = i - t->c[0].x;
	q.y = j - t->c[0].y;
	if (q.x < 0 || q.y < 0)
		return (e);
	z = 0;
	if (map[i][j] != '.')
		return (e);
	while (z < 4)
	{
		if (t->c[z].x + q.x > (aba.size - 1) ||
				t->c[z].y + q.y > (aba.size - 1))
			return (e);
		if (map[t->c[z].x + q.x][t->c[z].y + q.y] != '.')
			return (e);
		z++;
	}
	return (q);
}

void		ft_add_del(char **map, t_tetri *t, t_cord q, int v)
{
	int		z;
	int		c;

	z = 0;
	if (v)
	{
		c = t->tab[t->c[0].x][t->c[0].y];
		while (z < 4)
		{
			map[t->c[z].x + q.x][t->c[z].y + q.y] = c;
			z++;
		}
	}
	else
	{
		while (z < 4)
		{
			map[t->c[z].x + q.x][t->c[z].y + q.y] = '.';
			z++;
		}
	}
}
