/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 00:56:49 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/04 07:46:03 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int j;
	int ret[2];

	ret[0] = 0;
	ret[1] = 0;
	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (f(tab[i], tab[j]) < 0)
				ret[0]++;
			if (f(tab[i], tab[j]) > 0)
				ret[1]++;
			j++;
		}
		i++;
	}
	if (ret[0] == 0 || ret[1] == 0)
		return (1);
	return (0);
}
