/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:38:51 by skunz             #+#    #+#             */
/*   Updated: 2019/02/10 11:58:35 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "operations.h"
#include "checker.h"
#include "parser.h"
#include <stdio.h>

void	print_add_stack(t_stack stack)
{
	printf("Size: %u\n", stack.size);
	for (int i = 0; i < stack.size; i++)
	{
		printf("[%d] %d [this] %p [prev] %p [next] %p\n", i, stack.top->data, stack.top, stack.top->prev, stack.top->next);
		stack.top = stack.top->next;
	}
}

void	execute(t_stack *a, t_stack *b, int idx)
{
	idx == 0 ? swap(a) : 0;
	idx == 1 ? swap(b) : 0;
	idx == 2 ? swap_both(a, b) : 0;
	idx == 3 ? push_to(a, b) : 0;
	idx == 4 ? push_to(b, a) : 0;
	idx == 5 ? rotate(a, UP) : 0;
	idx == 6 ? rotate(b, UP) : 0;
	idx == 7 ? rotate_both(a, b, UP) : 0;
	idx == 7 ? rotate(a, DOWN) : 0;
	idx == 9 ? rotate(b, DOWN) : 0;
	idx == 10 ? rotate_both(a, b, DOWN) : 0;
}

int		get_index(char *op, char **tab)
{
	int i;

	i = -1;
	while (++i < 11)
		if (ft_strcmp(op, tab[i]) == 0)
			return (i);
	return (-1);
}

void	check_sorted(t_stack a, t_stack b)
{
	int i;

	i = 0;
	if (b.size != 0)
	{
		ft_putstr("KO\n");
		return ;
	}
	else
		while (++i < a.size)
		{
			if (a.top->data > a.top->next->data)
			{
				ft_putstr("KO\n");
				return ;
			}
			a.top = a.top->next;
		}
	ft_putstr("OK\n");
}

int		main(int argc, char **argv)
{
	int		index;
	char	**tab;
	char	*op;
	t_stack a;
	t_stack b;

	initialize_stack(&a);
	initialize_stack(&b);
	if (argc > 1)
	{
		if (!populate_stack(&a, argc, argv))
			return (ft_error(e_invalid));
		// print_stack(a, "A");
		tab = ft_strsplit("sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n",
			'\n');
		while (get_next_line(0, &op))
		{
			if ((index = get_index(op, tab)) == -1)
				exit(ft_error(e_invalid));
			execute(&a, &b, index);
			// print_stack(a, "A");
			// print_stack(b, "B");
			free(op);
		}
		// rotate(&a, DOWN);
		// print_stack(a, "A");
		// push_to(&b, &a);
		// print_stack(a, "A");
		// rotate(&a, UP);
		// print_stack(a, "A");
		check_sorted(a, b);
		ft_free2d((void**)tab, 11);
	}
}
