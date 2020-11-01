/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:25:56 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/25 17:22:44 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	print_str(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (32 <= str[i] && str[i] != 127)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_hexadecimal_addr(long long num, int size)
{
	char	*hexa;
	char	arr[16];
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		arr[i] = hexa[num % 16];
		if (num > 0)
			num /= 16;
		i++;
	}
	while (--i >= 0)
		write(1, &arr[i], 1);
}

void	print_hexadecimal_char(unsigned char *str, int size)
{
	char	*hexa;
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		write(1, &hexa[str[i] / 16], 1);
		write(1, &hexa[str[i] % 16], 1);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*str;
	int		i_size;
	int		len;

	i_size = size;
	len = 0;
	str = addr;
	while (i_size > 0)
	{
		if (i_size > 16)
			len = 16;
		else
			len = i_size;
		print_hexadecimal_addr((long long)str, 16);
		write(1, ": ", 2);
		print_hexadecimal_char((unsigned char*)str, len);
		print_str(str, len);
		write(1, "\n", 1);
		str += len;
		i_size -= len;
	}
	return (addr);
}
