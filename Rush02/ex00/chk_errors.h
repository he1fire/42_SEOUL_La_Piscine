/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_errors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:10:33 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/01 18:12:14 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHK_ERRORS_H
# define CHK_ERRORS_H

int		chk_dict(char **dict);
int		chk_num(char *str);
int		chk_dict_error(char **dict, char *str, int argc, char *argv[]);
int		chk_error(int argc, char *argv[], int *fd);

#endif
