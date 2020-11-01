/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:55:31 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/25 17:21:55 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	print_hexadecimal(unsigned char c)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &hexa[c / 16], 1);
	write(1, &hexa[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (32 <= str[i] && str[i] != 127)
			write(1, &str[i], 1);
		else
			print_hexadecimal((unsigned char)str[i]);
		i++;
	}
}
