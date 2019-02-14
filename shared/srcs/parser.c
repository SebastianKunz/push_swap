/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:07:04 by skunz             #+#    #+#             */
/*   Updated: 2019/02/13 14:29:15 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int		ft_error(int code)
{
	if (code == e_invalid)
		ft_putstr_fd("Error\n", 2);
	return (code);
}

int		is_valid(char *arg)
{
	char	*cmp;
	int		j;

	j = -1;
	while (arg[++j])
		if (!ft_isdigit(arg[j]) && !(arg[j] == '-' &&
			ft_isdigit(arg[j + 1])))
			return (0);
	if (ft_strcmp(cmp = ft_itoa(ft_atoi(arg)), arg) != 0)
	{
		free(cmp);
		return (0);
	}
	free(cmp);
	return (1);
}

int		populate_stack(t_stack *a, int argc, char **argv) // bottleneck in checking for dups
{
	int j;
	
	while (--argc > 0)
	{
		j = -1;
		if (!is_valid(argv[argc]))
			return (0);
		push(a, ft_atoi(argv[argc]));
		// while (a->size > 1 && ++j < a->size)
		// {
		// 	if (a->top->data == a->top->next->data)
		// 		return (0);
		// 	a->top = a->top->next;
		// }
	}
	return (1);
}
