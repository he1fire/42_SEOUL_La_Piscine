/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:43:13 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/25 17:01:02 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHK_H
# define CHK_H

int	chk_up(int (*g_arr)[4], int *g_chk);
int	chk_down(int (*g_arr)[4], int *g_chk);
int	chk_left(int (*g_arr)[4], int *g_chk);
int	chk_right(int (*g_arr)[4], int *g_chk);

#endif
