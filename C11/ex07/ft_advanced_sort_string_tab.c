/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:07:13 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/05 19:41:16 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		len(char **tab)
{
	int ret;

	ret = 0;
	while (tab[ret])
		ret++;
	return (ret);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*tmp;
	int		size;
	int		i;
	int		j;

	size = len(tab);
	i = 0;
	while (i++ < size)
	{
		j = 0;
		while (++j < size)
		{
			if (cmp(tab[j - 1], tab[j]) > 0)
			{
				tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}
