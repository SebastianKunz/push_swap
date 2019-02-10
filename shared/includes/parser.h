/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:07:30 by skunz             #+#    #+#             */
/*   Updated: 2019/02/08 19:24:34 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "stack.h"

enum	e_error
{
	e_none,
	e_invalid,
};

int		ft_error(int code);
int		populate_stack(t_stack *a, int argc, char **argv);

#endif
