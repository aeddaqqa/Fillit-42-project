/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:52:49 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/20 04:14:28 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			check_sides(char *str)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) <= 20 && str[i + 1] == '#')
				c++;
			if ((i + 5) <= 20 && str[i + 5] == '#')
				c++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				c++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				c++;
		}
		i++;
	}
	if (c == 6 || c == 8)
		return (1);
	return (0);
}

int			check_titro(char *buf)
{
	int		c;
	int		i;
	int		j;

	c = 0;
	i = 0;
	while (i < 20)
	{
		j = -1;
		while (++j < 4)
		{
			if (buf[i + j] != '#' && buf[i + j] != '.')
				return (0);
			if (buf[i + j] == '#')
			{
				c++;
				if (c > 4)
					return (0);
			}
		}
		if (buf[i + j] != '\n')
			return (0);
		i = i + 5;
	}
	return ((c == 4) ? 1 : 0);
}

t_check		check_file(int fd)
{
	int			r;
	char		buf[22];
	char		*tmp;
	t_check		str;
	int			c;

	c = 0;
	str.t = ft_strnew(0);
	str.v = 0;
	while ((r = read(fd, buf, 21)) >= 20)
	{
		c++;
		buf[r] = '\0';
		if (!check_titro(buf) || !check_sides(buf))
			return (str);
		tmp = ft_strjoin(str.t, buf);
		ft_strdel(&str.t);
		str.t = tmp;
	}
	if (((ft_strlen(str.t) + 1) % 21 != 0))
		return (str);
	str.v = c;
	return (str);
}
