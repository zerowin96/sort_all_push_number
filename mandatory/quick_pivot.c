/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_pivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:20:37 by yeham             #+#    #+#             */
/*   Updated: 2023/04/01 20:58:16 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pibot(t_stack *list, int num)
{
	int		*arr;
	int		pi[4];
	int		i;
	t_node	*now;

	arr = (int *)malloc(sizeof(int) * list->size);
	i = 0;
	now = list->top;
	while (i < list->size)
	{
		arr[i] = now->data;
		now = now->prev;
		i++;
	}
	quick(0, i - 1, arr);
	pi[0] = (arr[(i - 1) / 5]);
	pi[1] = (arr[(((i - 1) / 5) * 2)]);
	pi[2] = (arr[(((i - 1) / 5) * 3)]);
	pi[3] = (arr[(((i - 1) / 5) * 4)]);
	free(arr);
	return (pi[num]);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick(int start, int end, int *arr)
{
	int	p;
	int	i;
	int	j;

	if (start >= end)
		return ;
	p = end;
	i = start;
	j = end - 1;
	while (i <= j)
	{
		while (i <= end && arr[i] < arr[p])
			++i;
		while (j >= start && arr[j] > arr[p])
			--j;
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[i], &arr[p]);
	quick(start, i - 1, arr);
	quick(i + 1, end, arr);
}
