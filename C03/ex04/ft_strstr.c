/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:40:53 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/22 18:41:57 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int		chk_same(char *s1, char *s2, int len1, int len2)
{
	int i;
	int j;
	int chk;

	i = 0;
	while (i <= len1 - len2)
	{
		chk = 1;
		j = 0;
		while (j < len2)
		{
			if (s1[i + j] != s2[j])
				chk = 0;
			j++;
		}
		if (chk == 1)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int len_str;
	int len_find;
	int ans;

	len_str = 0;
	len_find = 0;
	while (str[len_str] != 0)
		len_str++;
	while (to_find[len_find] != 0)
		len_find++;
	ans = chk_same(str, to_find, len_str, len_find);
	if (ans != -1)
		return (&str[ans]);
	else
		return (0);
}
