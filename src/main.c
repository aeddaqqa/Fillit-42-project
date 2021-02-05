/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:20:02 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/20 04:16:16 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	print(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		i++;
	}
}

void	help(t_check t1)
{
	t_tetri	*te;
	char	**map;

	te = ft_lstetri(t1.t, t1.v);
	free(t1.t);
	map = ft_solve(t1.v, te);
	print(map);
	ft_free_tab(map);
	ft_free_lst(&te);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_check	t1;

	if (argc != 2)
	{
		ft_putstr("usage: fillit [file_name]\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	t1 = check_file(fd);
	if (t1.v && t1.v < 27)
		help(t1);
	else
	{
		ft_strdel(&t1.t);
		ft_putstr("error\n");
	}
	close(fd);
	return (0);
}
