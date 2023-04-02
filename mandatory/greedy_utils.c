/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:31:10 by yeham             #+#    #+#             */
/*   Updated: 2023/04/01 20:57:57 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max0min1(t_stack *list, int num)
{
	int		max;
	int		min;
	int		p[2];
	t_node	*now;

	now = list->top;
	max = list->top->data;
	min = list->top->data;
	while (now)
	{
		if (now->data > max)
			max = now->data;
		if (now->data < min)
			min = now->data;
		now = now->prev;
	}
	p[0] = max;
	p[1] = min;
	return (p[num]);
}

int	maxormin(t_stack *a, int min)
{
	int		a_index;
	t_node	*now;

	now = a->top;
	a_index = 0;
	while (now->data != min)
	{
		now = now->prev;
		a_index++;
	}
	if (a_index > (a->size) / 2)
		return ((a->size - a_index) * -1);
	return (a_index);
}

int	best(int ra_c, int rb_c, int new_ra_c, int new_rb_c)
{
	int	old;
	int	new;

	old = cal(ra_c, rb_c);
	new = cal(new_ra_c, new_rb_c);
	if (new < old)
		return (1);
	else
		return (0);
}

int	cal(int ra, int rb)
{
	int	ra_buho;
	int	rb_buho;

	ra_buho = 1;
	rb_buho = 1;
	if (ra < 0)
		ra_buho = -1;
	if (rb < 0)
		rb_buho = -1;
	if (ra_buho * rb_buho == -1)
		return (ra * ra_buho + rb * rb_buho);
	else if (ra * ra_buho < rb * rb_buho)
		return (rb * rb_buho);
	else
		return (ra * ra_buho);
}
