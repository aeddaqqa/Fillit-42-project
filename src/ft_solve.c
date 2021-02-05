/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 05:12:54 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/20 04:15:14 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_backtracking(char **map, t_tetri *lst, int size, int i)
{
	int			j;
	t_cord		q;
	t_mps		aba;

	if (!lst)
		return (1);
	aba.t = lst;
	aba.size = size;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			q = ft_possible(map, i, j, aba);
			if (q.x != -1 && q.y != -1)
			{
				ft_add_del(map, lst, q, 1);
				if ((ft_backtracking(map, lst->next, size, -1)) == 1)
					return (1);
				ft_add_del(map, lst, q, 0);
			}
		}
	}
	return (0);
}

int		ft_sqrt(int n)
{
	int i;

	i = 2;
	while (i * i < n)
		i++;
	return (i);
}

char	**ft_solve(int c, t_tetri *l)
{
	size_t		i;
	char		**map;

	i = ft_sqrt(4 * c);
	map = ft_creat_map(i);
	while (!ft_backtracking(map, l, i, -1))
	{
		i++;
		ft_free_tab(map);
		map = ft_creat_map(i);
	}
	return (map);
}

char	**ft_creat_map(int n)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char *) * n + 1)))
		return (NULL);
	while (i < n)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * n + 2)))
			return (NULL);
		j = 0;
		while (j < n)
			map[i][j++] = '.';
		map[i][j++] = '\n';
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}
