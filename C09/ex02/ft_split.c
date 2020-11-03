/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:56:32 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/01 18:56:38 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <stdlib.h>

void	str_copy(char *str, char *st, char *ed)
{
	while (st < ed)
	{
		*str = *st;
		str++;
		st++;
	}
	*str = 0;
}

int		str_same(char *c, char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c[0])
			return (1);
		i++;
	}
	return (0);
}

int		find_set(char *str, char *charset)
{
	int ret;

	ret = 0;
	while (*str != 0)
	{
		if (str_same(str, charset) == 0)
		{
			ret++;
			while (*str != 0 && str_same(str, charset) == 0)
				str++;
		}
		str++;
	}
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	char	*cp;
	int		cnt;

	ret = (char **)malloc(sizeof(char *) * find_set(str, charset) + 1);
	cnt = 0;
	while (*str != 0)
	{
		if (str_same(str, charset) == 0)
		{
			cp = str;
			while (*str != 0 && str_same(str, charset) == 0)
				str++;
			ret[cnt] = (char *)malloc(str - cp + 1);
			str_copy(ret[cnt], cp, str);
			cnt++;
		}
		str++;
	}
	ret[cnt] = 0;
	return (ret);
}
