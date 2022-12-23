/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:58:09 by yeham             #+#    #+#             */
/*   Updated: 2022/10/02 19:26:41 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned long long int	answer(unsigned long long int num, int buho)
{
	int	a;

	a = num * buho;
	if (buho == -1 && num > 2147483648)
		error();
	if (buho == 1 && num > 2147483647)
		error();
	return (a);
}

int	ft_atoi(char *str, int len)
{
	int						buho;
	int						i;
	unsigned long long int	num;

	num = 0;
	buho = 1;
	i = 0;
	str[len] = '\0';
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{	
		buho *= -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (answer(num, buho));
}
