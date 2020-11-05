/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 03:04:31 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/04 03:48:31 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int		is_space(char c)
{
	char	*arr;

	arr = "\t\n\v\f\r ";
	while (*arr != 0)
	{
		if (c == *arr)
			return (1);
		arr++;
	}
	return (0);
}

int		ft_atoi(char *str)
{
	int minus;
	int ret;

	minus = 0;
	ret = 0;
	while (is_space(*str) == 1)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus++;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	if (minus % 2 == 1)
		ret *= -1;
	return (ret);
}
