/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:25:04 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/29 22:23:27 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (src[len] != 0)
		len++;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (i <= len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
