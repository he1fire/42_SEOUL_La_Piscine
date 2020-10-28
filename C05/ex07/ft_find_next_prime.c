/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 22:38:30 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/27 01:32:20 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	is_prime(int nb)
{
	long long long_nb;
	long long i;

	long_nb = nb;
	i = 2;
	while (i * i <= long_nb)
	{
		if (long_nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (1)
	{
		if (is_prime(nb) == 1)
			return (nb);
		nb++;
	}
}
