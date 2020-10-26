/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 09:50:23 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/25 09:53:22 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	main(int argc, char *argv[])
{
	int i;
	int len;

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
