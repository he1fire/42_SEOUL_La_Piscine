/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:51:36 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/22 20:24:17 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int ret;

	ret = 1;
	if (nb < 0)
		return (0);
	else
	{
		while (nb > 0)
		{
			ret *= nb;
			nb--;
		}
		return (ret);
	}
}
