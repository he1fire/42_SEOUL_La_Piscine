/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:43:58 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/27 21:50:48 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	char *arr;

	arr = "\t\n\v\f\r ";
	while (*arr != 0)
	{
		if (c == *arr)
			return (1);
		arr++;
	}
	return (0);
}

int	chk_valid(unsigned char *str)
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
		if (str[len] == '-' || str[len] == '+' || is_space(str[len]) == 1)
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

int	chk_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != 0)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int minus;
	int ret;
	int len_b;

	minus = 1;
	ret = 0;
	len_b = 0;
	if (chk_valid((unsigned char*)base) == 0)
		return (0);
	while (base[len_b] != 0)
		len_b++;
	while (is_space(*str) == 1)
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			minus *= -1;
	while (*str != 0)
	{
		if (chk_base(*str, base) == -1)
			break ;
		ret = ret * len_b + minus * chk_base(*str, base);
		str++;
	}
	return (ret);
}
