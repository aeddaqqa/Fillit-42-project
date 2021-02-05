/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:37:32 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/23 16:53:20 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef	struct	s_check
{
	int		v;
	char	*t;
}				t_check;

typedef	struct	s_cord
{
	int x;
	int y;
}				t_cord;

typedef struct	s_tetri
{
	char			**tab;
	t_cord			*c;
	struct s_tetri	*next;
}				t_tetri;

typedef	struct	s_mps
{
	t_tetri *t;
	int		size;
}				t_mps;

t_tetri			*ft_newtetri(char *str);
t_cord			ft_cordcmp(t_cord *t);
void			ft_free_tab(char **tab);
char			**ft_stock(char **tab);
t_cord			*ft_find_cord(char **tab);
char			**ft_strsplit_i(char const *s, char c, int x);
t_tetri			*ft_lstetri(char *str, int c);
t_check			check_file(int fd);
char			**ft_solve(int c, t_tetri *l);
char			**ft_creat_map(int n);
void			print(char **tab);
t_cord			ft_possible(char **map, int i, int j, t_mps aba);
int				ft_backtracking(char **map, t_tetri *lst, int size, int i);
void			ft_add_del(char **map, t_tetri *lst, t_cord q, int v);
void			ft_free_lst(t_tetri **lst);
#endif
