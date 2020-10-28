/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 22:30:15 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/27 01:29:01 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	ft_is_prime(int nb)
{
	long long long_nb;
	long long i;

	long_nb = nb;
	i = 2;
	if (long_nb < 2)
		return (0);
	while (i * i <= long_nb)
	{
		if (long_nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
