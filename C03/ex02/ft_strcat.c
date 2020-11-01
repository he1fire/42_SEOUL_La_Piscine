/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:56:41 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/22 11:04:21 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (dest[len] != 0)
	{
		len++;
	}
	while (src[i] != 0)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = 0;
	return (dest);
}
