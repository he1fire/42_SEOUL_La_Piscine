/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 03:51:17 by minylee           #+#    #+#             */
/*   Updated: 2020/11/04 03:59:04 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct			s_info
{
	int		row;
	int		col;
	char	empty;
	char	obs;
	char	full;
}						t_info;
typedef struct			s_xy
{
	int x;
	int y;
	int len;
}						t_xy;

void					str_copy(char *str, char *st, char *ed);
int						find_set(char *str);
void					file_input_fill_map(char **map, char *str);
int						min(int **arr, int x, int y);
void					print_square(char **map, t_info *info, t_xy xy);
void					fill_arr(char **map, int **arr, t_info *info);
void					solve_square(char **map, t_info *info);
int						simple_atoi(char *c, int size);
int						chk_info(char *tmp, t_info *info);
int						chk_map(char **map, t_info *info);
void					std_input_fill_map(char **map, t_info *info, char *tmp);
void					std_input(t_info *info);
char					*file_input_str(t_info *info, char *argv);
int						file_input(t_info *info, char *argv);

#endif
