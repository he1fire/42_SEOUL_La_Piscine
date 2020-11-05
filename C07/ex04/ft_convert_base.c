/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:29:33 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/03 22:14:50 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <stdlib.h>

extern int		is_space(char c);
extern int		chk_valid(unsigned char *str);
extern int		chk_base(char c, char *base);
extern int		ft_atoi_base(char *str, char *base);

int				len(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void			reverse_arr(int st, int ed, char *arr)
{
	char tmp;

	while (st < ed)
	{
		tmp = arr[st];
		arr[st] = arr[ed];
		arr[ed] = tmp;
		st++;
		ed--;
	}
}

void			mk_ret(long long nb, char *ret, char *base)
{
	int i;
	int j;

	i = 0;
	if (nb < 0)
	{
		ret[0] = '-';
		i++;
		nb *= -1;
	}
	j = i;
	while (nb > 0)
	{
		ret[j] = base[nb % len(base)];
		j++;
		nb /= len(base);
	}
	reverse_arr(i, j - 1, ret);
	ret[j] = 0;
}

int				cnt_numlen(long long long_nb, char *base)
{
	int cnt;

	cnt = 0;
	if (long_nb < 0)
	{
		cnt++;
		long_nb *= -1;
	}
	while (long_nb > 0)
	{
		cnt++;
		long_nb /= len(base);
	}
	return (cnt);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			nb;
	long long	long_nb;
	char		*ret;

	if (chk_valid((unsigned char *)base_from) == 0 ||
		chk_valid((unsigned char *)base_to) == 0)
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	if (nb == 0)
	{
		ret = (char *)malloc(sizeof(char) * 2);
		ret[0] = base_to[0];
		ret[1] = 0;
		return (ret);
	}
	long_nb = nb;
	ret = (char *)malloc(sizeof(char) * (cnt_numlen(long_nb, base_to) + 1));
	mk_ret(long_nb, ret, base_to);
	return (ret);
}
