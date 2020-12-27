/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_lst *lst)
{
	int	swap;

	if (lst && lst->next)
	{
		swap = lst->nr;
		lst->nr = lst->next->nr;
		lst->next->nr = swap;
		if (lst->next->next == NULL)
			lst->bottom = lst->next;
	}
}

void	push(t_lst **from, t_lst **to)
{
	t_lst	*swap;
	t_lst	*swap2;

	if (*from)
	{
		swap = *from;
		*from = swap->next;
		if (*to)
		{
			swap2 = *to;
			*to = swap;
			swap->next = swap2;
			if (swap2->next == NULL)
				swap->bottom = swap2;
			else
				swap->bottom = swap2->bottom;
		}
		else
		{
			*to = swap;
			swap->next = NULL;
			swap->bottom = swap;
		}
	}
}

void	rotate(t_lst *lst)
{
	t_lst	*tmp;
	int		swap;

	if (lst)
	{
		tmp = lst;
		swap = lst->nr;
		while (tmp->next != NULL)
		{
			tmp->nr = tmp->next->nr;
			tmp = tmp->next;
		}
		tmp->nr = swap;
	}
}

void	reverse_rotate(t_lst *lst)
{
	t_lst	*tmp;
	t_lst	*last;
	int		swap;
	int		swap2;

	if (lst)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			last = tmp;
			swap2 = last->nr;
			last->nr = swap;
			tmp = tmp->next;
			swap = swap2;
		}
		lst->nr = swap;
		lst->bottom = last;
	}
}
