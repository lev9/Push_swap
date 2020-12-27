/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	roll_to_top(int choice, t_lst *a, t_lst *b, t_push *p)
{
	int		a_size;

	a_size = p->size - p->b_size;
	if (choice != 0)
	{
		if (choice <= a_size / 2)
		{
			while (a->nr != p->best)
				do_the_right_move('F', p, 1);
		}
		else
		{
			while (a->nr != p->best)
				do_the_right_move('I', p, 1);
		}
	}
	put_to_b(a, b, p);
	push_swap(p);
}

int		distance(int nr, t_lst *b, t_push *p)
{
	int		count;

	if (nr <= p->b_min || nr >= p->b_max)
		p->count = find_max(b, p);
	else
		find(nr, b, p);
	if (p->count > p->b_size / 2)
		p->count = p->b_size - p->count;
	count = p->count;
	return (count);
}

void	test_if_closer(int choice, int nr, t_lst *b, t_push *p)
{
	int		dist;
	int		a_size;

	a_size = p->size - p->b_size;
	if (choice <= a_size / 2)
		dist = choice;
	else
		dist = a_size - choice;
	dist += distance(nr, b, p);
	if (dist < p->closest)
	{
		p->closest = dist;
		p->choice = choice;
		p->best = nr;
	}
}

/*
**	move_from_a_to_b;
**	-for each number in a, find the distance to their
**	 right place in b;
**	-move the number with shortest distance to top of a in
**	 function roll_to_top, and from there proceed to put the number
**	 to b in put_to_b. After that return to push_swap to see there are
**	 numbers left to move to b.
*/

void	move_from_a_to_b(t_lst *a, t_lst *b, t_push *p)
{
	t_lst	*tmp;
	int		i;

	if (b == NULL || !b->bottom)
		roll_to_top(0, a, b, p);
	else
	{
		p->closest = distance(a->nr, b, p);
		p->choice = 0;
		p->best = a->nr;
		i = 1;
		tmp = a->next;
		while (tmp)
		{
			test_if_closer(i, tmp->nr, b, p);
			tmp = tmp->next;
			i++;
		}
		roll_to_top(p->choice, a, b, p);
	}
}

/*
**	push_swap;
**	-if the list is <7, go solve_small;
**	-else if  there are numbers left in a, find the next one to move to b;
**	-else, find the spot of the largest number in b.
**	-roll it to the end the shortest way.
**	-push all back to a.
*/

void	push_swap(t_push *p)
{
	int	i;

	if (p->order == 0)
	{
		if (p->size < 7)
			solve_small(p);
		else
		{
			if (p->a)
				move_from_a_to_b(p->a, p->b, p);
			else
			{
				i = find_max(p->b, p);
				while (!(p->b->nr == p->b_max && p->b->bottom->nr == p->b_min))
				{
					if (i < p->b_size / 2)
						do_the_right_move('G', p, 1);
					else
						do_the_right_move('J', p, 1);
				}
				while (p->b != NULL)
					do_the_right_move('D', p, 1);
			}
		}
	}
}
