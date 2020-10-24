/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 23:51:46 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/22 15:00:34 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	make_str(long long longnb)
{
	char c;

	c = '0' + longnb % 10;
	if (longnb > 0)
	{
		make_str(longnb / 10);
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	long long longnb;

	longnb = nb;
	if (longnb == 0)
		write(1, "0", 1);
	else if (longnb < 0)
	{
		write(1, "-", 1);
		make_str(-longnb);
	}
	else
		make_str(longnb);
}
