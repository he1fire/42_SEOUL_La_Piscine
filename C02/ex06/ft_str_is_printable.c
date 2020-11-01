/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:42:16 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/20 09:37:05 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int ret;
	int i;

	ret = 1;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 32 || str[i] == 127)
			ret = 0;
		i++;
	}
	return (ret);
}
