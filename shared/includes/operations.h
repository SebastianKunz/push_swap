/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:53:03 by skunz             #+#    #+#             */
/*   Updated: 2019/02/09 18:26:26 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

# define UP 1
# define DOWN 0

void	swap(t_stack *stack);
void	swap_both(t_stack *a, t_stack *b);
void	push_to(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack, int direction);
void	rotate_both(t_stack *a, t_stack *b, int direction);

#endif
