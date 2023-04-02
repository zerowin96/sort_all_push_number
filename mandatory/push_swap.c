/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:31:50 by yeham             #+#    #+#             */
/*   Updated: 2023/04/01 20:58:13 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	division3(t_stack *a, t_stack *b)
{
	int	max;
	int	min;
	int	asize;
	int	p1;

	asize = a->size;
	max = max0min1(a, 0);
	min = max0min1(a, 1);
	p1 = (max + min) / 3;
	while (asize--)
	{
		if (a->top->data > p1 * 2)
			ra(a);
		else
		{
			pb(a, b);
			if (b->top->data < p1)
				rb(b);
		}
	}
}

void	division2(t_stack *a, t_stack *b, int p3, int p0)
{
	int	asize;

	asize = a->size;
	while (asize--)
	{
		if (a->top->data > p3)
			ra(a);
		else
		{
			pb(a, b);
			if (b->top->data <= p0)
				rb(b);
		}
	}
}

void	 division(t_stack *a, t_stack *b)
{
	int	p[4];
	int	asize;

	p[0] = pibot(a, 0);
	p[1] = pibot(a, 1);
	p[2] = pibot(a, 2);
	p[3] = pibot(a, 3);
	asize = a->size;
	while (asize--)
	{
		if (a->top->data > p[2] || a->top->data <= p[0])
			ra(a);
		else if (a->top->data <= p[2] && a->top->data > p[0])
		{
			pb(a, b);
			if (b->top->data < p[1])
				rb(b);
		}
	}
	division2(a, b, p[3], p[0]);
}

void	atob(t_stack *a, t_stack *b)
{
	sortcheck(a);
	if (a->size >= 100)
		division(a, b);
	else if (a->size < 100 && a->size > 10)
		division3(a, b);
	while (a->size > 3)
		pb(a, b);
	hardcoding(a);
	while (b->size)
		btoa(a, b);
	finish(a);
	return ;
}

void	trance_string(int argc, char *argv[], t_stack *a)
{
	int	len;
	int	i;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (len == 0)
			error();
		else
			trance(a, argv[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = stack_init();
	b = stack_init();
	insert_check(argc, argv);
	trance_string(argc, argv, a);
	samesame(a);
	atob(a, b);
	clear(a);
	clear(b);
}
