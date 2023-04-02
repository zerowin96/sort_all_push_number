/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:15:44 by yeham             #+#    #+#             */
/*   Updated: 2023/04/01 20:55:24 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	c_sa(t_stack *a)
{
	int	tmp;

	tmp = a->top->data;
	a->top->data = a->top->prev->data;
	a->top->prev->data = tmp;
}

void	c_sb(t_stack *b)
{
	int	tmp;

	tmp = b->top->data;
	b->top->data = b->top->prev->data;
	b->top->prev->data = tmp;
}

void	c_ss(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->top->data;
	a->top->data = a->top->prev->data;
	a->top->prev->data = tmp;
	tmp = b->top->data;
	b->top->data = b->top->prev->data;
	b->top->prev->data = tmp;
}

void	c_pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	push_top(a, b->top->data);
	pop_top(b);
}

void	c_pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	push_top(b, a->top->data);
	pop_top(a);
}
