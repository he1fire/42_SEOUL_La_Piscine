/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:20:43 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/01 18:20:57 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		str_len(char *str)
{
	int ret;

	ret = 0;
	while (str[ret] != 0)
		ret++;
	return (ret);
}

void	str_copy(char *str, char *st, char *ed)
{
	while (st < ed)
	{
		*str = *st;
		st++;
		str++;
	}
	*str = 0;
}
