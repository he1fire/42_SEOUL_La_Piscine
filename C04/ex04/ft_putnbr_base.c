/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:55:24 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/22 21:06:36 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int		chk_valid(unsigned char *str)
{
	int len;
	int cnt[300];
	int i;

	len = 0;
	i = -1;
	while (++i < 300)
		cnt[i] = 0;
	while (str[len] != 0)
	{
		if (str[len] == '-' || str[len] == '+')
			return (0);
		cnt[(int)str[len]]++;
		len++;
	}
	i = -1;
	while (++i < 300)
	{
		if (cnt[i] > 1)
			return (0);
	}
	if (len < 2)
		return (0);
	return (1);
}

void	print_base(long long nbr, int len, unsigned char *str)
{
	if (nbr > 0)
	{
		print_base(nbr / len, len, str);
		write(1, &str[nbr % len], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	long long	longnbr;

	longnbr = nbr;
	len = 0;
	if (chk_valid((unsigned char*)base) == 1)
	{
		while (base[len] != 0)
			len++;
		if (longnbr == 0)
			write(1, &base[0], 1);
		else if (longnbr < 0)
		{
			write(1, "-", 1);
			print_base(-longnbr, len, (unsigned char*)base);
		}
		else
			print_base(longnbr, len, (unsigned char*)base);
	}
}
