/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	matching_move(char move)
{
	if (move == 'A')
		return ('B');
	else if (move == 'F')
		return ('G');
	else if (move == 'I')
		return ('J');
	else if (move == 'B')
		return ('A');
	else if (move == 'G')
		return ('F');
	else if (move == 'J')
		return ('I');
	else
		return ('O');
}

char	joined_move(char move)
{
	if (move == 'A' || move == 'B')
		return ('C');
	else if (move == 'F' || move == 'G')
		return ('H');
	else
		return ('K');
}

int		double_move(char c, t_push *p)
{
	int		check;
	int		i;
	char	match;
	char	join;

	check = 1;
	match = matching_move(c);
	if (match == 'O')
		return (0);
	join = joined_move(c);
	i = 1;
	while (p->list_tail - i > 0 && p->movelist[p->list_tail - i] == join)
		i++;
	if (p->movelist[p->list_tail - i] == match)
		p->movelist[p->list_tail - i] = join;
	else
		check = 0;
	return (check);
}

/*
**      put_to_list;
**      -in the function above, check for a matching move on
**	 recent moves on movelist.
**      -if found, replace the two moves with a double move.
**      -otherwise just add new move to the movelist.
*/

void	put_to_list(char c, t_push *p)
{
	int		check;
	char	*one;
	char	*temp;

	check = 0;
	if (p->list_tail > 0)
		check = double_move(c, p);
	if (check == 0)
	{
		one = ft_strnew(1);
		one[0] = c;
		temp = ft_strjoin(p->movelist, one);
		free(p->movelist);
		p->movelist = temp;
		free(one);
		p->list_tail++;
	}
}

void	do_the_right_move(char c, t_push *p, int print)
{
	if (c == 'A' || c == 'C')
		swap(p->a);
	if (c == 'B' || c == 'C')
		swap(p->b);
	if (c == 'D')
		push(&p->b, &p->a);
	if (c == 'E')
		push(&p->a, &p->b);
	if (c == 'F' || c == 'H')
		rotate(p->a);
	if (c == 'G' || c == 'H')
		rotate(p->b);
	if (c == 'I' || c == 'K')
		reverse_rotate(p->a);
	if (c == 'J' || c == 'K')
		reverse_rotate(p->b);
	if (print == 1)
		put_to_list(c, p);
}
