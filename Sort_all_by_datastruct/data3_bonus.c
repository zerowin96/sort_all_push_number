/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_data3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:02:33 by yeham             #+#    #+#             */
/*   Updated: 2022/10/02 17:33:47 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	c_rr(t_stack *a, t_stack *b)
{
	push_bottom(a, a->top->data);
	pop_top(a);
	push_bottom(b, b->top->data);
	pop_top(b);
}
