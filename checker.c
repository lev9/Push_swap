/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		error_c(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int		not_option(char *s, int i, char *split[], t_push *p)
{
	if (i > 1 && split[i + 1] == NULL && s[0] == '-' &&
		(s[1] == 'z' || s[1] == 'g') && s[2] == '\0')
	{
		if (s[1] == 'z')
			p->z_opt = 1;
		if (s[1] == 'g')
			p->g_opt = 1;
		return (0);
	}
	return (1);
}

/*
**	c_create_lst;
**	check that the argumnents in char **split are either valid
**	numbers or z/g-option, and add numbers to t_lst a.
*/

int		c_create_lst(char *split[], t_push *p)
{
	t_lst	*new;
	char	*s;
	int		i;
	int		nr;

	i = 0;
	while (split[i] != NULL)
	{
		s = &split[i][0];
		if (unvalid_argv(s, p))
		{
			if (not_option(s, i, split, p))
				return (error_c());
			break ;
		}
		nr = ft_atoi(s);
		if (nr > p->largest)
			p->largest = nr;
		new = lstnew(nr);
		lstadd(&p->a, new, p);
		i++;
	}
	return (0);
}

char	**handle_argv(int argc, char **argv, t_push *p)
{
	char **split;

	if (argv[argc - 1][0] == '-' && argv[argc - 1][1] == 'z' &&
		argv[argc - 1][2] == '\0')
		p->z_opt = 1;
	if (argv[argc - 1][0] == '-' && argv[argc - 1][1] == 'g' &&
		argv[argc - 1][2] == '\0')
		p->g_opt = 1;
	if (argc == 2 || (argc == 3 && (p->z_opt == 1 || p->g_opt == 1)))
		split = ft_strsplit(argv[1], ' ');
	else
		split = argv + 1;
	return (split);
}

/*
**	main;
**	-split the arguments and see if -z/g option is used.
**	-create a t_lst a.
**	-create a movelist of the moves given by push_swap or user.
**	-execute the moves.
**	-check that list a is in order, and b is empty and give the results.
*/

int		main(int argc, char *argv[])
{
	t_push	newpush;
	t_push	*p;
	char	**split;

	p = &newpush;
	p->z_opt = 0;
	p->g_opt = 0;
	if (argc < 2)
		return (0);
	split = handle_argv(argc, argv, p);
	if (split[0] == NULL)
		return (0);
	p->largest = ft_atoi(&split[0][0]);
	p->size = 0;
	p->a = NULL;
	c_create_lst(split, p);
	create_move_list(p);
	do_move(p);
	final_check(p->a, p);
	return (0);
}
