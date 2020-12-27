/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <stdlib.h>
# define G "\033[0;32m"
# define P "\033[0;35m"
# define B "\033[0;34m"
# define C "\033[0;36m"
# define R "\033[0;31m"
# define Y "\033[0;33m"
# define N "\033[0;0m"

typedef struct	s_lst
{
	int				nr;
	struct s_lst	*prev;
	struct s_lst	*next;
	struct s_lst	*bottom;
}				t_lst;

typedef struct	s_push
{
	t_lst	*a;
	t_lst	*b;
	int		z_opt;
	int		g_opt;
	int		order;
	int		largest;
	int		size;
	t_lst	*last;
	char	*movelist;
	int		next;
	int		moves;
	int		b_max;
	int		b_min;
	int		b_size;
	int		count;
	int		list_tail;
	int		closest;
	int		choice;
	int		best;
	int		a_arrow;
	int		b_arrow;
	int		doubles;
}				t_push;

/*
*******************************************************************
**		PUSH_SWAP FILES:
**
**
**	push_swap.c
*/
int				error_push(void);
void			print_out(char c);
void			print_list(t_push *p);
int				p_create_lst(char *argv[], t_push *p);

/*
**	solve_small.c
*/
void			solve_small(t_push *p);
int				smallest(t_lst *lst);
void			turn_if_in_order(int i, int spot, t_push *p);
int				check_order(t_push *p);

/*
**	push_from_a.c
*/
void			roll_to_top(int choice, t_lst *a, t_lst *b, t_push *p);
int				distance(int nr, t_lst *b, t_push *p);
void			test_if_closer(int choice, int nr, t_lst *b, t_push *p);
void			move_from_a_to_b(t_lst *a, t_lst *b, t_push *p);
void			push_swap(t_push *p);

/*
**	push_to_b.c
*/
int				find(int nr, t_lst *b, t_push *p);
int				find_max(t_lst *b, t_push *p);
void			find_spot(int nr, t_lst *b, t_push *p);
void			put_to_b(t_lst *a, t_lst *b, t_push *p);

/*
*******************************************************************
**		CHECKER FILES:
**
**
**	checker.c
*/
int				error_c(void);
int				not_option(char *s, int i, char *split[], t_push *p);
int				c_create_lst(char *split[], t_push *p);
char			**handle_argv(int argc, char **argv, t_push *p);

/*
**	checker_mover.c
*/
char			move_char(char *str);
int				create_move_list(t_push *p);
void			visual(char c, t_push *p);
int				do_move(t_push *p);
int				final_check(t_lst *lst, t_push *p);

/*
********************************************************************
**		SHARED FILES:
**
**
**	moves.c
*/
void			swap(t_lst *lst);
void			push(t_lst **from, t_lst **to);
void			rotate(t_lst *lst);
void			reverse_rotate(t_lst *lst);

/*
**	mover.c
*/
char			matching_move(char move);
char			joined_move(char move);
int				double_move(char c, t_push *p);
void			put_to_list(char c, t_push *p);
void			do_the_right_move(char c, t_push *p, int print);

/*
**      shared.c
*/
void			print_a_list(t_push *p, int arrow);
void			print_both(t_push *p, int arrow);
int				unvalid_argv(char *s, t_push *p);
void			lstadd(t_lst **head, t_lst *new, t_push *p);
t_lst			*lstnew(int nr);

#endif
