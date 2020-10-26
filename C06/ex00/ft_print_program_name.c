/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 09:45:48 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/25 09:55:06 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int	main(int argc, char *argv[])
{
	int len;

	argc = 0;
	len = 0;
	while (argv[0][len] != 0)
		len++;
	write(1, argv[0], len);
	write(1, "\n", 1);
	return (0);
}
