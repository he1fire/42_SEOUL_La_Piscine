/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:28:14 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/20 09:35:31 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int ret;
	int i;

	ret = 1;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 'A' || 'Z' < str[i])
			ret = 0;
		i++;
	}
	return (ret);
}
