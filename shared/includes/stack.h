/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:38:54 by skunz             #+#    #+#             */
/*   Updated: 2019/02/09 20:10:07 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef	struct		s_node
{
	struct s_node	*prev;
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	t_node			*top;
	int				size;
	int				min;
	int				max;

}					t_stack;

void				initialize_stack(t_stack *stack);
t_node				*new_node(int data);
void				push(t_stack *stack, int data);
void				pop(t_stack *stack);
void	print_stack(t_stack stack, char *name);

#endif
