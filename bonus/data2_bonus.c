/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:46:26 by yeham             #+#    #+#             */
/*   Updated: 2023/04/01 20:55:26 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	c_ra(t_stack *a)
{
	if (a->size < 2)
		return ;
	push_bottom(a, a->top->data);
	pop_top(a);
}

void	c_rb(t_stack *b)
{
	if (b->size < 2)
		return ;
	push_bottom(b, b->top->data);
	pop_top(b);
}

void	c_rra(t_stack *a)
{
	if (a->size < 2)
		return ;
	push_top(a, a->bottom->data);
	pop_bottom(a);
}

void	c_rrb(t_stack *b)
{
	if (b->size < 2)
		return ;
	push_top(b, b->bottom->data);
	pop_bottom(b);
}

void	c_rrr(t_stack *a, t_stack *b)
{
	push_top(a, a->bottom->data);
	pop_bottom(a);
	push_top(b, b->bottom->data);
	pop_bottom(b);
}
