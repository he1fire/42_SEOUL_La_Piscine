/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:02:17 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/20 10:05:36 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int ret;
	int i;

	ret = 1;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 'a' || 'z' < str[i])
			ret = 0;
		i++;
	}
	return (ret);
}
