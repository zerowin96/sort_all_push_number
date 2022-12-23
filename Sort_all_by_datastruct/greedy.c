/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:29:58 by yeham             #+#    #+#             */
/*   Updated: 2022/10/01 21:11:56 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_ra(t_stack *a, int data)
{
	int		min;
	int		max;
	int		a_index;
	t_node	*now;

	a_index = 1;
	now = a->top;
	max = max0min1(a, 0);
	min = max0min1(a, 1);
	if (max < data || min > data)
		return (maxormin(a, min));
	if (a->top->data > data && a->bottom->data < data)
		return (0);
	while (1)
	{
		if (now->data < data && now->prev->data > data)
		{
			if (a_index > (a->size) / 2)
				return ((a->size - a_index) * -1);
			return (a_index);
		}
		now = now->prev;
		a_index++;
	}
}

void	count(t_stack *a, t_stack *b, int *ra_c, int *rb_c)
{
	int		b_index;
	int		new_ra_c;
	int		new_rb_c;
	t_node	*now;

	now = b->top;
	b_index = 0;
	while (b_index < b->size)
	{
		new_ra_c = count_ra(a, now->data);
		if (b_index > (b->size) / 2)
			new_rb_c = (b->size - b_index) * -1;
		else
			new_rb_c = b_index;
		if (b_index == 0 || best(*ra_c, *rb_c, new_ra_c, new_rb_c))
		{
			*ra_c = new_ra_c;
			*rb_c = new_rb_c;
		}
		now = now->prev;
		b_index++;
	}
}

void	btoa(t_stack *a, t_stack *b)
{
	int	ra_c;
	int	rb_c;

	ra_c = 0;
	rb_c = 0;
	count(a, b, &ra_c, &rb_c);
	rrrab(a, b, &ra_c, &rb_c);
	rrra(a, &ra_c);
	rrrb(b, &rb_c);
	pa(a, b);
}

void	finish(t_stack *a)
{
	int		min;
	int		a_index;
	t_node	*now;

	a_index = 0;
	now = a->top;
	min = max0min1(a, 1);
	while (now->data != min)
	{
		now = now->prev;
		a_index++;
	}
	if (a_index > a->size / 2)
	{
		a_index = a->size - a_index;
		while (a_index--)
			rra(a);
	}
	else
	{
		while (a_index--)
			ra(a);
	}
}
