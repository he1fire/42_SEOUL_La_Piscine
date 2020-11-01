/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:25:37 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/22 00:14:14 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	i = 0;
	while (src[len] != 0)
	{
		len++;
	}
	while (i < n)
	{
		if (i < len)
			dest[i] = src[i];
		else
			dest[i] = 0;
		i++;
	}
	return (dest);
}
