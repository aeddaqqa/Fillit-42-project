/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:53:51 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/23 16:40:01 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

size_t			ft_strlen(const char *str);
void			ft_putstr(char const *s);
char			*ft_strnew(size_t size);
void			ft_strdel(char	**as);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
