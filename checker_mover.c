/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_mover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	move_char(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return ('A');
	else if (ft_strcmp(str, "sb") == 0)
		return ('B');
	else if (ft_strcmp(str, "ss") == 0)
		return ('C');
	else if (ft_strcmp(str, "pa") == 0)
		return ('D');
	else if (ft_strcmp(str, "pb") == 0)
		return ('E');
	else if (ft_strcmp(str, "ra") == 0)
		return ('F');
	else if (ft_strcmp(str, "rb") == 0)
		return ('G');
	else if (ft_strcmp(str, "rr") == 0)
		return ('H');
	else if (ft_strcmp(str, "rra") == 0)
		return ('I');
	else if (ft_strcmp(str, "rrb") == 0)
		return ('J');
	else if (ft_strcmp(str, "rrr") == 0)
		return ('K');
	else
		return ('x');
}

/*
**	create_move_list;
**	-read all the moves from push_swap or mover, turn them to
**	 single chars and add to char *movelist.
*/

int		create_move_list(t_push *p)
{
	char	*str;
	char	*one;
	char	move;
	char	*temp;

	p->movelist = ft_strnew(0);
	one = ft_strnew(1);
	while (get_next_line(0, &str))
	{
		move = move_char(str);
		if (move == 'x')
		{
			free(one);
			free(p->movelist);
			return (error_c());
		}
		one[0] = move;
		temp = ft_strjoin(p->movelist, one);
		free(p->movelist);
		p->movelist = temp;
		free(str);
	}
	free(one);
	return (0);
}

void	visual(char c, t_push *p)
{
	if (c == 'A' || c == 'C')
		p->a_arrow = 1;
	if (c == 'B' || c == 'C')
		p->b_arrow = 1;
	if (c == 'D')
		p->a_arrow = 2;
	if (c == 'E')
		p->b_arrow = 2;
	if (c == 'F' || c == 'H')
		p->a_arrow = 3;
	if (c == 'G' || c == 'H')
		p->b_arrow = 3;
	if (c == 'I' || c == 'K')
		p->a_arrow = 4;
	if (c == 'J' || c == 'K')
		p->b_arrow = 4;
	if (c == 'C' || c == 'H' || c == 'K')
		p->doubles = 1;
	print_both(p, 1);
}

int		do_move(t_push *p)
{
	int		i;
	char	c;

	p->b = NULL;
	i = 0;
	while (p->movelist[i] != '\0')
	{
		c = p->movelist[i];
		p->a_arrow = 0;
		p->b_arrow = 0;
		p->doubles = 0;
		if (p->g_opt == 1)
			visual(c, p);
		do_the_right_move(c, p, 0);
		if (p->g_opt == 1 && (p->size < 100 || p->b == NULL))
			print_both(p, 0);
		i++;
	}
	p->moves = i;
	return (0);
}

int		final_check(t_lst *lst, t_push *p)
{
	if (p->b != NULL)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	while (lst && lst->next != NULL)
	{
		if (lst->next->nr < lst->nr)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		lst = lst->next;
	}
	if (p->z_opt == 1 || p->g_opt == 1)
	{
		ft_putstr_fd_col("OK ", 1, G);
		ft_putstr_fd_col("   MOVES: ", 1, Y);
		ft_putnbr_fd_col(p->moves, 1, N);
		ft_putstr_fd("\n", 1);
	}
	else
		write(1, "OK\n", 3);
	return (0);
}
