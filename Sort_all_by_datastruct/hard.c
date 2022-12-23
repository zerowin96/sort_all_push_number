/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:51:12 by yeham             #+#    #+#             */
/*   Updated: 2022/10/02 14:58:18 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	harda(t_stack *a)
{
	t_node	*now;

	now = a->top;
	if (now->data > now->prev->data && now->prev->data > a->bottom->data)
	{
		sa(a);
		rra(a);
	}
	else if (now->data > a->bottom->data && a->bottom->data > now->prev->data)
		ra(a);
	else if (a->bottom->data > now->data && now->data > now->prev->data)
		sa(a);
	else if (now->prev->data > now->data && now->data > a->bottom->data)
		rra(a);
	else if (now->prev->data > a->bottom->data && a->bottom->data > now->data)
	{
		rra(a);
		sa(a);
	}
	else
		return ;
}

void	sortcheck(t_stack *a)
{
	t_node	*now;

	now = a->top;
	while (now->prev)
	{
		if (now->data < now->prev->data)
			now = now->prev;
		else
			return ;
	}
	exit(0);
}

void	hardcoding(t_stack *a)
{
	if (a->size <= 1)
		return ;
	else if (a->size == 2)
	{
		if (a->top->data > a->bottom->data)
			sa(a);
	}
	else
		harda(a);
}
