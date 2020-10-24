/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcombn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 09:35:11 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/21 15:38:18 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	make_combn(char *printch, char now, int depth, int max)
{
	if (depth == max)
	{
		write(1, printch, max);
		if (printch[0] < '0' + 10 - max)
			write(1, ", ", 2);
	}
	else
	{
		while (++now <= '9')
		{
			printch[depth] = now;
			make_combn(printch, now, depth + 1, max);
		}
	}
}

void	ft_print_combn(int n)
{
	char c[20];

	make_combn(c, '0' - 1, 0, n);
}
