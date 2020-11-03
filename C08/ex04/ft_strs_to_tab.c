/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:34:39 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/01 22:50:18 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <stdlib.h>
#	include "ft_stock_str.h"

void				str_copy(char *s1, char *s2)
{
	while (*s2 != 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str	*ret;

	i = 0;
	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (ret == 0)
		return (0);
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != 0)
			j++;
		ret[i].size = j;
		ret[i].str = (char *)malloc(sizeof(char) * (j + 1));
		ret[i].copy = (char *)malloc(sizeof(char) * (j + 1));
		str_copy(ret[i].str, av[i]);
		str_copy(ret[i].copy, av[i]);
		i++;
	}
	ret[i].str = 0;
	return (ret);
}
