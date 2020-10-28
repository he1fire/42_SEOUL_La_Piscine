/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 22:26:46 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/27 01:26:32 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	ft_sqrt(int nb)
{
	long long long_nb;
	long long i;

	long_nb = nb;
	i = 0;
	while (i * i <= long_nb)
	{
		if (i * i == long_nb)
			return (i);
		i++;
	}
	return (0);
}
