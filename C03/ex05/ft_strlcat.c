/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 01:33:11 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/29 20:44:08 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int len_s;
	unsigned int len_d;
	unsigned int j;

	i = 0;
	len_s = 0;
	len_d = 0;
	while (dest[len_d] != 0)
		len_d++;
	while (src[len_s] != 0)
		len_s++;
	if (size <= len_d)
		return (len_s + size);
	if (len_s < size - len_d - 1)
		j = len_s;
	else
		j = size - len_d - 1;
	while (i < j)
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = 0;
	return (len_d + len_s);
}
