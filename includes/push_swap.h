/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:42:34 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:42:36 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include "printf.h"
# include <limits.h>
# include <fcntl.h>

# define V_SIZE			200u

# define DEBUG			0b00000001u
# define TO_FILE		0b00000010u

# define RA		0b00000001u
# define RB		0b00000010u
# define RR		0b00000011u
# define SA		0b00000100u
# define SB		0b00001000u
# define SS		0b00001100u
# define RRA	0b00010000u
# define RRB	0b00100000u
# define RRR	0b00110000u
# define PB		0b01000000u
# define PA		0b10000000u

typedef struct		s_place
{
	int		steps_to_b;
	int		steps_to_a;
	int		rr;
	char	way_to_b;
	char	way_to_a;
}					t_place;

typedef struct		s_vector
{
	void			*arr;
	size_t			size;
	size_t			next;
}					t_vector;

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_info
{
	t_stack			*a;
	t_stack			*b;
	t_vector		*cmd_c;
	t_place			place;
	int				flag;
	char			*to_file;
}					t_info;

typedef struct		s_map
{
	int				beg;
	int				end;
	int				*begin;
	int				*size;
}					t_map;

void				info_init(t_info *info);
void				read_argv(int argc, char **argv, t_info *info);
int					is_flag(char *str);
void				add_flag(char *str, int *flag);
int					is_file(char *str);
void				add_file(t_info *info, char *str);
t_stack				*create_stack(void);
int					get_number(char *str, long long int *number);
int					push_in_stack(t_stack **stack, int value);
int					try_to_split(char *str, t_info *info);

void				run_command(char *command, t_info *info);
int					check_command(char *cmd);
void				check_duplicates(t_info *info);

t_vector			*create_vector(void);
int					push_in_vector(t_vector **v, int value, size_t size);

void				clean_and_exit(t_info *info, char option);
void				destroy_map(t_map **map);
void				destroy_vector(t_vector **v);
void				destroy_stack(t_stack **stack);

void				get_commands(t_info *info);
void				all_to_b(t_info *info);
int					check_mid(t_stack *a, int middle);
int					get_middle(t_info *info);
int					*timsort(int *arr, int size);
t_map				*set_map(t_map *map, int i);
int					*merge(int *arr, t_map **map);
int					*insertion_sort(int *arr, t_map *map);
int					is_slice(t_stack *a);
void				sort_slice(t_info *info);
void				do_rotate(t_info *info, int middle);
int					try_sa(t_info *info);
int					all_to_a(t_info *info);
void				steps_b(t_stack *b, t_place *cur, int value);
void				steps_a(t_stack *a, t_place *cur, int value);
void				set_rr(t_place *place);
int					check_asc_order(t_stack *a, t_stack *b);

void				print_info(t_info *info);
void				print_debug(t_info *info, char *command);

t_stack				*copy_stack(t_stack *src);
int					cat_vectors(t_vector **dest, t_vector *src);
t_vector			**create_varr(void);
int					push_in_varr(t_info **m, t_vector *tmp);

#endif
