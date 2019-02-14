/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:05:06 by skunz             #+#    #+#             */
/*   Updated: 2019/02/13 21:54:24 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"
#include "parser.h"
#include "libft.h"

#include <stdio.h> // delete

int	get_direction(t_stack stack, int dimension)
{
	int i;

	i = -1;
	dimension = dimension == MIN_DIM ? stack.min : stack.max;
	while (++i < stack.size + 1)
	{
		if (stack.top->data == dimension)
		{
			return (i > stack.size / 2);
			break ;
		}
		stack.top = stack.top->next;
	}
	return (0);
}

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

int	decide_dimension(t_stack stack)
{
	int	pos_min;
	int	pos_max;
	int	i;

	i = -1;
	while (++i < stack.size)
	{
		if (stack.top->data == stack.min)
			pos_min = i;
		if (stack.top->data == stack.max)
			pos_max = i;
		stack.top = stack.top->next;
	}
	i = -1;
	while (++i < stack.size)
	{
		if (stack.top->data == stack.min)
			pos_min = i < pos_min ? i : pos_min;
		if (stack.top->data == stack.max)
			pos_max = i < pos_max ? i : pos_max;
		stack.top = stack.top->prev;
	}
	return (pos_max < pos_min);
}

void	push_from_dim(t_stack *a, t_stack *b, int dim)
{
	int dim_value;

	dim_value = dim == MIN_DIM ? a->min : a->max;
	if (get_direction(*a, dim))
		while (a->top->data != dim_value)
		{
			rotate(a, DOWN);
			ft_putstr("rra\n");
		}
	else
		while (a->top->data != dim_value)
		{
			rotate(a, UP);
			ft_putstr("ra\n");
		}
	if (b->size > 0 && b->top->data > a->top->data)
	{
		rotate(b, UP);
		ft_putstr("rb\n");
	}
	push_to(b, a);
	ft_putstr("pb\n");
}

void	max_min_idc_sort(t_stack *a, t_stack *b)
{
	while (!is_sorted(*a))
	{
		if (decide_dimension(*a))
			push_from_dim(a, b, MIN_DIM);
		else
			push_from_dim(a, b, MAX_DIM);
	}
	if (get_direction(*b, MAX_DIM))
		while (b->top->data != b->max)
		{
			rotate(b, DOWN);
			ft_putstr("rrb\n");
		}
	else
		while (b->top->data != b->max)
		{
			rotate(b, UP);
			ft_putstr("rb\n");
		}
	if (get_direction(*a, MIN_DIM))
		while (a->top->data != a->min)
		{
			rotate(a, DOWN);
			ft_putstr("rrb\n");
		}
	else
		while (a->top->data != a->min)
		{
			rotate(a, UP);
			ft_putstr("rb\n");
		}
	while (b->size)
	{
		if (b->top->data > a->top->data)
		{
			rotate(a, DOWN);
			ft_putstr("rra\n");
			push_to(a, b);
			ft_putstr("pa\n");
			if (get_direction(*a, MIN_DIM))
				while (a->top->data != a->min)
				{
					rotate(a, DOWN);
					ft_putstr("rrb\n");
				}
			else
				while (a->top->data != a->min)
				{
					rotate(a, UP);
					ft_putstr("rb\n");
				}
		}
		else
		{
			push_to(a, b);
			ft_putstr("pa\n");
		}
	}
}


int	min_sort(t_stack *a, t_stack *b)
{
	if (get_direction(*a, MIN_DIM))
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
		if (argc < 6)
			while (!billo_sort(&a));
		// else
			// while (!min_sort(&a, &b));
		else
			max_min_idc_sort(&a, &b);
	}
}