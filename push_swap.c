/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		error_push(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	print_out(char c)
{
	if (c == 'A')
		write(1, "sa\n", 3);
	if (c == 'B')
		write(1, "sb\n", 3);
	if (c == 'C')
		write(1, "ss\n", 3);
	if (c == 'D')
		write(1, "pa\n", 3);
	if (c == 'E')
		write(1, "pb\n", 3);
	if (c == 'F')
		write(1, "ra\n", 3);
	if (c == 'G')
		write(1, "rb\n", 3);
	if (c == 'H')
		write(1, "rr\n", 3);
	if (c == 'I')
		write(1, "rra\n", 4);
	if (c == 'J')
		write(1, "rrb\n", 4);
	if (c == 'K')
		write(1, "rrr\n", 4);
}

/*
**	print_list;
**	-print out the actual instruction on the movelist
**	 according to the char on the list (function above).
*/

void	print_list(t_push *p)
{
	int		i;
	char	c;

	i = 0;
	while (p->movelist[i])
	{
		c = p->movelist[i];
		print_out(c);
		i++;
	}
}

/*
**	p_create_lst;
**	-check that each number in char **split is valid and add them
**	 to the list t_lst a.
*/

int		p_create_lst(char *split[], t_push *p)
{
	t_lst	*new;
	char	*s;
	int		i;
	int		nr;

	p->a = NULL;
	p->size = 0;
	i = 0;
	while (split[i] != NULL)
	{
		s = &split[i][0];
		if (unvalid_argv(s, p))
			return (error_push());
		nr = ft_atoi(s);
		if (nr > p->largest)
			p->largest = nr;
		new = lstnew(nr);
		lstadd(&p->a, new, p);
		i++;
	}
	p->a->bottom = p->last;
	p->b_size = 0;
	return (0);
}

/*
**	main;
**	-create struct t_push *p.
**	-split the arguments to a **char depending on the way
**	 they were given (ARG=" 1 2 3", 1 2 3, "`cat test100`"...).
**	-split[0] == NULL -check is for case of "`cat test100`"
**	 being unable to read the test file.
**	-set some default values for p.
**	-if the numbers are in order but start at wrong point,
**	 just arrange them in check_order.
**	-in push_swap(p), if not in order, proceed to arrange either
**	 less than 7 numbers or more.
*/

int		main(int argc, char *argv[])
{
	t_push	newpush;
	t_push	*p;
	char	**split;

	if (argc < 2)
		return (error_push());
	if (argc == 2)
		split = ft_strsplit(argv[1], ' ');
	else
	{
		split = argv;
		split++;
	}
	if (split[0] == NULL)
		return (error_push());
	p = &newpush;
	p->order = 1;
	p_create_lst(split, p);
	p->movelist = ft_strnew(0);
	p->list_tail = 0;
	if (p->size > 1)
		p->order = check_order(p);
	push_swap(p);
	print_list(p);
	return (0);
}
