/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 10:08:41 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/25 13:37:47 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int		cmp_str(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	else if (s1[i] == 0)
		return (-1);
	else
		return (1);
}

void	sort_arr(int argc, char *argv[])
{
	char	*str;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (cmp_str(argv[i], argv[j]) == 1)
			{
				str = argv[i];
				argv[i] = argv[j];
				argv[j] = str;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int i;
	int len;

	sort_arr(argc, argv);
	i = 1;
	while (i < argc)
	{
		len = 0;
		while (argv[i][len] != 0)
			len++;
		write(1, argv[i], len);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
