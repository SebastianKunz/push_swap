/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:47:00 by skunz             #+#    #+#             */
/*   Updated: 2019/02/09 21:32:30 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	swap(t_stack *stack)
{
	int	a;

	if (stack->size > 1)
	{
		a = stack->top->data;
		stack->top->data = stack->top->next->data;
		stack->top->next->data = a;
	}
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	push_to(t_stack *dest, t_stack *src)
{
	if (src->size > 0)
	{
		push(dest, src->top->data);
		pop(src);
	}
}

void	rotate(t_stack *stack, int direction)
{
	if (stack->size > 1)
	{
		if (direction == UP)
			stack->top = stack->top->next;
		else if (direction == DOWN)
			stack->top = stack->top->prev;
	}
}

void	rotate_both(t_stack *a, t_stack *b, int direction)
{
	rotate(a, direction);
	rotate(b, direction);
}
