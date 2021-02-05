/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:36:03 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/20 04:15:43 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_nbrcars(char *str, unsigned int i, char c)
{
	int		k;

	k = 0;
	if (str)
	{
		if (!*str)
			return (0);
		while (str[i] != c && str[i])
		{
			k++;
			i++;
		}
	}
	return (k);
}

int		ft_nbrmots(char *str, char c)
{
	int		i;
	int		cmp;

	i = 0;
	cmp = 0;
	if (str)
	{
		if (!*str)
			return (0);
		if (str[i] != c)
			cmp = 1;
		while (str[i])
		{
			if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
				cmp++;
			i++;
		}
	}
	return (cmp);
}

char	**ft_strsplit_i(char const *s, char c, int x)
{
	int		i;
	int		j;
	int		k;
	char	**t;

	i = 0;
	k = 0;
	t = NULL;
	if ((t = (char **)malloc(sizeof(char *) * ft_nbrmots((char *)s, c) + 1)))
	{
		while (k < ft_nbrmots((char *)s, c))
		{
			j = 0;
			while (s[i + x] == c)
				i++;
			t[k] = (char *)malloc(sizeof(char) * ft_nbrcars((char *)s,
						i, c) + 1);
			while (s[i + x] != c && s[i + x] != '\0')
				t[k][j++] = s[(i++) + x];
			t[k][j] = '\0';
			k++;
		}
		t[k] = NULL;
	}
	return (t);
}
