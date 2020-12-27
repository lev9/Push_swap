/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_a_list(t_push *p, int arrow)
{
	t_lst *temp;

	temp = p->a;
	if (arrow == 0)
		ft_putstr_fd("\n\n\n", 1);
	ft_putstr_fd_col("A:", 1, R);
	if (p->doubles == 1)
		ft_putstr_fd_col("        💥 DOUBLE MOVE💥\n", 1, B);
	else
		ft_putstr_fd("\n", 1);
	while (temp)
	{
		ft_putnbr_fd_col(temp->nr, 1, G);
		ft_putstr_fd(" ", 1);
		temp = temp->next;
	}
	if (arrow == 1 && p->a_arrow == 1)
		ft_putstr_fd_col("\n◄ ► swap\n", 1, Y);
	if (arrow == 1 && p->a_arrow == 3)
		ft_putstr_fd_col("\n     ◄ ◄ ◄ ◄ rotate\n", 1, P);
	if (arrow == 1 && p->a_arrow == 4)
		ft_putstr_fd_col("\n     ► ► ► ► rotate\n", 1, C);
	if (arrow == 1 && p->a_arrow == 0)
		ft_putstr_fd("\n\n", 1);
	ft_putstr_fd("\n\n\n", 1);
}

void	print_both(t_push *p, int arrow)
{
	t_lst	*temp;

	temp = p->b;
	usleep(10000000 / p->size);
	system("clear");
	ft_putstr_fd_col("\nB:\n", 1, R);
	while (temp)
	{
		ft_putnbr_fd_col(temp->nr, 1, G);
		ft_putstr_fd(" ", 1);
		temp = temp->next;
	}
	if (arrow == 1 && p->b_arrow == 1)
		ft_putstr_fd_col("\n◄ ► swap\n\n", 1, Y);
	if (arrow == 1 && p->b_arrow == 2)
		ft_putstr_fd_col("\n▲ push\n▲\n", 1, Y);
	if (arrow == 1 && p->a_arrow == 2)
		ft_putstr_fd_col("\n▼ push\n▼\n", 1, Y);
	if (arrow == 1 && p->b_arrow == 3)
		ft_putstr_fd_col("\n     ◄ ◄ ◄ ◄ rotate\n\n", 1, P);
	if (arrow == 1 && p->b_arrow == 4)
		ft_putstr_fd_col("\n     ► ► ► ► rotate\n\n", 1, C);
	if (arrow == 1 && p->b_arrow == 0 && p->a_arrow != 2)
		ft_putstr_fd("\n\n\n", 1);
	print_a_list(p, arrow);
}

/*
**	unvalid_argv;
**	-while 1: check for a non-digit that is not a proper -.
**	-check if atoi returns -1 (nr not within integer limits).
**	-while 2: check for duplicates.
*/

int		unvalid_argv(char *s, t_push *p)
{
	int		i;
	int		nr;
	t_lst	*tmp;

	i = 0;
	while (s[i] != '\0')
	{
		if (!(ft_isdigit(s[i])) && (!(i == 0 && s[i] == '-' &&
		ft_isdigit(s[i + 1]) && s[i + 1] != '0')))
			return (1);
		i++;
	}
	nr = ft_atoi(s);
	if (nr == -1 && !(s[0] == '-' && s[1] == '1'))
		return (1);
	tmp = p->a;
	while (tmp != NULL)
	{
		if (tmp->nr == nr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	lstadd(t_lst **head, t_lst *new, t_push *p)
{
	t_lst	*temp;

	if (*head)
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
		p->last = new;
	}
	else
	{
		*head = new;
		p->last = new;
	}
	p->size++;
}

t_lst	*lstnew(int nr)
{
	t_lst	*new;

	new = (t_lst*)malloc(sizeof(t_lst));
	if (new)
	{
		new->nr = nr;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
