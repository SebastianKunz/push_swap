/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:38:57 by skunz             #+#    #+#             */
/*   Updated: 2019/02/10 11:53:46 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>//delete

void	initialize_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
	stack->min = INT_MAX;
	stack->max = INT_MIN;
}

t_node	*new_node(int data)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->prev = new;
	new->data = data;
	new->next = new;
	return (new);
}

void	push(t_stack *stack, int data)
{
	t_node	*head;
	t_node	*last;

	head = new_node(data);
	if (data < stack->min)
		stack->min = data;
	if (data > stack->max)
		stack->max = data;
	if (!stack->top)
		stack->top = head;
	else
	{
		last = stack->top->prev;
		head->next = stack->top;
		stack->top->prev = head;
		head->prev = last;
		last->next = head;
		stack->top = head;
	}
	stack->size++;
}

void	pop(t_stack *stack)
{
	int	i;
	t_node			*tmp;
	t_node			*beg;

	i = -1;
	if (stack->size > 0)
	{
		beg = stack->top;
		tmp = stack->top->next;
		tmp->prev = stack->top->prev;
		tmp->prev->next = tmp;
		stack->size--;
		if (stack->top->data == stack->min || stack->top->data == stack->max)
		{
			stack->top = stack->top->next;
			stack->min = INT_MAX;
			stack->max = INT_MIN;
			while (++i < stack->size)
			{
				if (stack->top->data < stack->min)
					stack->min = stack->top->data;
				if (stack->top->data > stack->max)
					stack->max = stack->top->data;
				stack->top = stack->top->next;
			}
		}
		free(beg);
		stack->top = tmp;
	}
}

void	print_stack(t_stack stack, char *name)
{
	int i;

	i = 0;
	printf("==%s==\n", name);
	printf("SIZE %d\n", stack.size);
	printf("MIN %d\n", stack.min);
	printf("MAX %d\n", stack.max);
	while (++i < stack.size + 1)
	{
		printf("%d\n", stack.top->data);
		stack.top = stack.top->next;
	}
	printf("=====\n");
}
