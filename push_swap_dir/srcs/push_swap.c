/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:05:06 by skunz             #+#    #+#             */
/*   Updated: 2019/02/09 22:11:14 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"
#include "parser.h"
#include "libft.h"

#include <stdio.h>

int	is_sorted(t_stack stack)
{
	int i;

	i = 0;
	while (++i < stack.size)
	{
		if (stack.top->data > stack.top->next->data)
			return (0);
		stack.top = stack.top->next;
	}
	return (1);
}

int	find_min(t_stack stack)
{
	int i;

	i = -1;
	// printf("enter\n");
	while (++i < stack.size + 1)
	{
		if (stack.top->data == stack.min)
		{
			// printf("Pos: %d\n", i);
			return (i > stack.size / 2);
			break ;
		}
		stack.top = stack.top->next;
	}
	return (0);
}

int	min_sort(t_stack *a, t_stack *b)
{
	if (find_min(*a))
		while (a->top->data != a->min)
		{
			rotate(a, DOWN);
			ft_putstr("rra\n");
			// print_stack(*a, "A");
			// print_stack(*b, "B");
		}
	else
		while (a->top->data != a->min)
		{
			rotate(a, UP);
			ft_putstr("ra\n");
			// print_stack(*a, "A");
			// print_stack(*b, "B");
		}
	if (!is_sorted(*a))
	{
		push_to(b, a);
		ft_putstr("pb\n");
		// print_stack(*a, "A");
		// print_stack(*b, "B");
	}
	else
	{
		while (b->size)
		{
			push_to(a, b);
			ft_putstr("pa\n");
			// print_stack(*a, "A");
			// print_stack(*b, "B");
		}
		return (1);
	}
	return (0);
}

int	billo_sort(t_stack *a)
{
	if ((a->top->data == a->min && a->top->next->data == a->max)
	|| (a->top->data == a->max && a->top->next->data == a->min))
	{
		rotate(a, UP);
		ft_putstr("ra\n");
	}
	else if (a->top->data > a->top->next->data)
	{
		swap(a);
		ft_putstr("sa\n");
	}
	else
	{
		rotate(a, UP);
		ft_putstr("ra\n");
	}
	return (is_sorted(*a));
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	initialize_stack(&a);
	initialize_stack(&b);
	if (argc > 1)
	{
		if (!populate_stack(&a, argc, argv))
			return (ft_error(e_invalid));
		if (is_sorted(a))
			return (0);
		// while (!billo_sort(&a));
		while (!min_sort(&a, &b));
	}
}