/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:14:26 by yeham             #+#    #+#             */
/*   Updated: 2022/10/02 19:44:48 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	insert_check(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')
					j++;
				else
					error();
			}
			else if ((argv[i][j] >= '0' && argv[i][j] <= '9')
				|| argv[i][j] == ' ')
				j++;
			else
				error();
		}
		i++;
	}
}

void	trance(t_stack *a, char *str)
{
	int	i;
	int	j;
	int	num;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (str[i] == ' ')
			i++;
		while (str[i + j] != '\0' && str[i + j] != ' ')
			j++;
		num = ft_atoi(&str[i], j);
		push_bottom(a, num);
		i = i + j;
		i++;
	}
}

void	samesame(t_stack *a)
{
	int		temp;
	t_node	*i;
	t_node	*j;

	i = a->top;
	while (i)
	{
		temp = i->data;
		j = i->prev;
		while (j)
		{
			if (temp == j->data)
			{
				clear(a);
				error();
			}
			j = j->prev;
		}
		i = i->prev;
	}
}
