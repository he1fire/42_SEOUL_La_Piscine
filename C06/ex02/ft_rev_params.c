/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 09:56:27 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/25 09:57:18 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	main(int argc, char *argv[])
{
	int i;
	int len;

	i = argc - 1;
	while (i > 0)
	{
		len = 0;
		while (argv[i][len] != 0)
			len++;
		write(1, argv[i], len);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
