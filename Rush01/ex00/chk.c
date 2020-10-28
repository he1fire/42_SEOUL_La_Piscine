/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:43:13 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/25 17:01:21 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "chk.h"

int	chk_up(int (*g_arr)[4], int *g_chk)
{
	int i;
	int j;
	int cnt;
	int max;

	i = -1;
	while (++i < 4)
	{
		cnt = 0;
		max = 0;
		j = -1;
		while (++j < 4)
		{
			if (g_arr[j][i] > max)
			{
				cnt++;
				max = g_arr[j][i];
			}
		}
		if (cnt != g_chk[i])
			return (0);
	}
	return (1);
}

int	chk_down(int (*g_arr)[4], int *g_chk)
{
	int i;
	int j;
	int cnt;
	int max;

	i = -1;
	while (++i < 4)
	{
		cnt = 0;
		max = 0;
		j = 4;
		while (--j >= 0)
		{
			if (g_arr[j][i] > max)
			{
				cnt++;
				max = g_arr[j][i];
			}
		}
		if (cnt != g_chk[i])
			return (0);
	}
	return (1);
}

int	chk_left(int (*g_arr)[4], int *g_chk)
{
	int i;
	int j;
	int cnt;
	int max;

	i = -1;
	while (++i < 4)
	{
		cnt = 0;
		max = 0;
		j = -1;
		while (++j < 4)
		{
			if (g_arr[i][j] > max)
			{
				cnt++;
				max = g_arr[i][j];
			}
		}
		if (cnt != g_chk[i])
			return (0);
	}
	return (1);
}

int	chk_right(int (*g_arr)[4], int *g_chk)
{
	int i;
	int j;
	int cnt;
	int max;

	i = -1;
	while (++i < 4)
	{
		cnt = 0;
		max = 0;
		j = 4;
		while (--j >= 0)
		{
			if (g_arr[i][j] > max)
			{
				cnt++;
				max = g_arr[i][j];
			}
		}
		if (cnt != g_chk[i])
			return (0);
	}
	return (1);
}
