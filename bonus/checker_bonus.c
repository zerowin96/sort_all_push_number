/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:07:36 by yeham             #+#    #+#             */
/*   Updated: 2023/04/01 20:55:21 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	t_node	*now;

	now = a->top;
	while (now->prev)
	{
		if (now->data < now->prev->data)
			now = now->prev;
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	if (b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (-1);
	}
	if (s1[i] == '\n' || s1[i] == '\0')
		return (1);
	return (-1);
}

void	output(t_stack *a, t_stack *b, char *s)
{
	if (ft_strcmp(s, "sa") == 1)
		c_sa(a);
	else if (ft_strcmp(s, "sb") == 1)
		c_sb(b);
	else if (ft_strcmp(s, "ss") == 1)
		c_ss(a, b);
	else if (ft_strcmp(s, "pa") == 1)
		c_pa(a, b);
	else if (ft_strcmp(s, "pb") == 1)
		c_pb(a, b);
	else if (ft_strcmp(s, "ra") == 1)
		c_ra(a);
	else if (ft_strcmp(s, "rb") == 1)
		c_rb(b);
	else if (ft_strcmp(s, "rr") == 1)
		c_rr(a, b);
	else if (ft_strcmp(s, "rra") == 1)
		c_rra(a);
	else if (ft_strcmp(s, "rrb") == 1)
		c_rrb(b);
	else if (ft_strcmp(s, "rrr") == 1)
		c_rrr(a, b);
	else
		error();
}

void	go_check(t_stack *a, t_stack *b)
{
	char	*order;

	while (1)
	{
		order = get_next_line(0);
		if (order == NULL)
			break ;
		output(a, b, order);
		free(order);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		len;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = stack_init();
	b = stack_init();
	i = 1;
	insert_check(argc, argv);
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (len == 0)
			error();
		else
			trance(a, argv[i]);
		i++;
	}
	samesame(a);
	go_check(a, b);
	sort(a, b);
	clear(a);
	clear(b);
}
