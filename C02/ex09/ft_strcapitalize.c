/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:52:21 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/20 09:39:33 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int		chk_alphanumeric(char c)
{
	int ret;

	ret = 0;
	if ('a' <= c && c <= 'z')
		ret = 1;
	if ('A' <= c && c <= 'Z')
		ret = 1;
	if ('0' <= c && c <= '9')
		ret = 1;
	return (ret);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			if (i == 0 || chk_alphanumeric(str[i - 1]) == 0)
				str[i] = str[i] - 'a' + 'A';
		}
		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			if (i != 0 && chk_alphanumeric(str[i - 1]) == 1)
				str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
	return (str);
}
