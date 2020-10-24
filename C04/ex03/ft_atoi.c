/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:01:43 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/23 01:12:37 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	is_space(char c)
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

int	ft_atoi(char *str)
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
