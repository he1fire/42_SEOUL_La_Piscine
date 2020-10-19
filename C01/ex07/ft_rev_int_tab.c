/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:00:40 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/18 18:51:07 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int rev[size];

	i = 0;
	while (i < size)
	{
		rev[size - i - 1] = tab[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = rev[i];
		i++;
	}
}
