/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:32:19 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/22 11:04:38 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (dest[len] != 0)
	{
		len++;
	}
	while (i < nb && src[i] != 0)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = 0;
	return (dest);
}
