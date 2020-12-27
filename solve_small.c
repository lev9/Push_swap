/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		smallest(t_lst *lst)
{
	int		smallest;
	t_lst	*tmp;

	tmp = lst;
	smallest = tmp->nr;
	while (tmp->next)
	{
		if (tmp->next->nr < smallest)
			smallest = tmp->next->nr;
		tmp = tmp->next;
	}
	return (smallest);
}

/*
**	solve_small;
**	-rotate smallest nr to top of a and push it to b, until 3 nrs are left in a.
**	-rotate the largest nr to bottom of a.
**	-swap the two top nrs if neceaary.
**	-push the smallest nrs back to a.
*/

void	solve_small(t_push *p)
{
	int		i;

	if (p->size > 1)
	{
		while (p->size > 2 && p->a->next->next->next)
		{
			i = smallest(p->a);
			while (p->a->next->next->next->nr == i ||
			(p->a->next->next->next->next &&
			(p->a->next->next->next->next->nr == i ||
			(p->a->next->next->next->next->next &&
			p->a->next->next->next->next->next->nr == i))))
				do_the_right_move('I', p, 1);
			while (p->a->next->nr == i || p->a->next->next->nr == i)
				do_the_right_move('F', p, 1);
			do_the_right_move('E', p, 1);
		}
		while (p->size > 2 && !(p->a->next->next->nr == p->largest))
			do_the_right_move('F', p, 1);
		if (p->a->nr > p->a->next->nr)
			do_the_right_move('A', p, 1);
		while (p->b)
			do_the_right_move('D', p, 1);
	}
}

void	turn_if_in_order(int i, int spot, t_push *p)
{
	while (spot > p->size / 2 && p->a->nr != i)
		do_the_right_move('I', p, 1);
	while (spot <= p->size / 2 && p->a->nr != i)
		do_the_right_move('F', p, 1);
}

/*
**	check_order;
**	-find the spot where the list is not in ascending order anymore.
**	-see if the rest is in order. If so, roll the smallest number to
**	 the top (function above).
*/

int		check_order(t_push *p)
{
	t_lst	*tmp;
	int		i;
	int		spot;

	spot = 1;
	i = smallest(p->a);
	tmp = p->a;
	while (tmp->nr != i && tmp->next->nr != i)
	{
		if (tmp->next->nr < tmp->nr)
			return (0);
		tmp = tmp->next;
		spot++;
	}
	tmp = tmp->next;
	while (tmp->next)
	{
		if (tmp->next->nr < tmp->nr)
			return (0);
		tmp = tmp->next;
	}
	if (p->a->nr != i && tmp->nr > p->a->nr)
		return (0);
	turn_if_in_order(i, spot, p);
	return (1);
}
