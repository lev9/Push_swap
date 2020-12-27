/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		find(int nr, t_lst *b, t_push *p)
{
	int		c;
	t_lst	*tmp;

	p->count = 0;
	tmp = b;
	while (tmp->next != NULL)
	{
		c = tmp->nr;
		tmp = tmp->next;
		p->count++;
		if (c > nr && tmp->nr <= nr)
			return (tmp->nr);
	}
	return (b->nr);
}

int		find_max(t_lst *b, t_push *p)
{
	t_lst	*tmp;
	int		s;

	tmp = b;
	s = 0;
	while (tmp->next != NULL)
	{
		if (tmp->nr == p->b_max)
			return (s);
		s++;
		tmp = tmp->next;
	}
	return (s);
}

void	find_spot(int nr, t_lst *b, t_push *p)
{
	int	s;

	if (nr <= p->b_min || nr >= p->b_max)
	{
		s = find_max(b, p);
		while ((b->nr != p->b_max && b->bottom->nr != p->b_min))
		{
			if (s < p->b_size / 2)
				do_the_right_move('G', p, 1);
			else
				do_the_right_move('J', p, 1);
		}
	}
	else
	{
		s = find(nr, b, p);
		while (b->nr != s)
		{
			if (p->count < p->b_size / 2)
				do_the_right_move('G', p, 1);
			else
				do_the_right_move('J', p, 1);
		}
	}
}

/*
**	put_to_b;
**	-keep track of smallest and largest number in b.
**	-find the right spot for the number in b and move the spot
**	 to the top of b.
**	-push the number from a to top of b.
*/

void	put_to_b(t_lst *a, t_lst *b, t_push *p)
{
	if (!b || (b && a->nr < p->b_min))
		p->b_min = a->nr;
	if (!b || (b && a->nr > p->b_max))
		p->b_max = a->nr;
	if (b && p->b_size > 1)
		find_spot(a->nr, b, p);
	do_the_right_move('E', p, 1);
	p->b_size++;
}
