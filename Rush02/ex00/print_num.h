/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:25:27 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/01 18:27:34 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_NUM_H
# define PRINT_NUM_H

void	print_str(char *str);
int		find_str(char **dict, char *str);
void	print_ten(char **dict, int num, int cnt);
void	print_hundred(char **dict, int num, int zero);
void	print_numerical_unit(char **dict, int cnt, int depth);

#endif
