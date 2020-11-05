/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:09:11 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/04 03:06:32 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_func.h"

int		chk_operator(char *str)
{
	int		i;
	int		len;
	char	*operator;

	operator = "+-*/%";
	len = 0;
	if (str[len] != 0)
		len++;
	if (len != 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	i = 0;
	while (operator[i] != 0)
	{
		if (str[0] == operator[i])
			return (1);
		i++;
	}
	write(1, "0\n", 2);
	return (0);
}

void	calculate(int x, int y, char op)
{
	int ret;

	if (op == '+')
		ret = x + y;
	if (op == '-')
		ret = x - y;
	if (op == '*')
		ret = x * y;
	if (op == '/')
		ret = x / y;
	if (op == '%')
		ret = x % y;
	ft_putnbr(ret);
}

int		main(int argc, char *argv[])
{
	int		x;
	int		y;
	char	op;

	if (argc != 4)
		return (0);
	if (chk_operator(argv[2]) == 0)
		return (0);
	op = argv[2][0];
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[3]);
	if (y == 0 && op == '/')
		write(1, "Stop : division by zero", 23);
	else if (y == 0 && op == '%')
		write(1, "Stop : modulo by zero", 21);
	else
		calculate(x, y, op);
	write(1, "\n", 1);
	return (0);
}
