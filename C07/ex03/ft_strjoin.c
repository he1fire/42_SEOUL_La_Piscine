/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:17:30 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/29 22:47:04 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <stdlib.h>

int		cnt_len(int size, char **strs, char *sep)
{
	int i;
	int j;
	int ret;

	ret = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != 0)
		{
			ret++;
			j++;
		}
		i++;
	}
	i = 0;
	while (sep[i] != 0)
		i++;
	if (size > 0)
		ret += i * (size - 1);
	return (ret);
}

void	cp_str(char *ret, int size, char **strs, char *sep)
{
	int i;
	int j;
	int cnt;

	cnt = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != 0)
		{
			ret[cnt] = strs[i][j];
			j++;
			cnt++;
		}
		j = 0;
		while (i < size - 1 && sep[j] != 0)
		{
			ret[cnt] = sep[j];
			j++;
			cnt++;
		}
		i++;
	}
	ret[cnt] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		cnt;

	if (size == 0)
	{
		ret = (char *)malloc(1 * sizeof(char));
		ret[0] = 0;
		return (ret);
	}
	cnt = cnt_len(size, strs, sep);
	ret = (char *)malloc((cnt + 1) * sizeof(char));
	cp_str(ret, size, strs, sep);
	return (ret);
}
