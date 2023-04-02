/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:32:15 by yeham             #+#    #+#             */
/*   Updated: 2022/10/03 14:19:39 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

t_stack	*stack_init(void);
t_node	*getnode(int data);
void	push_top(t_stack *list, int data);
void	pop_top(t_stack *list);
void	push_bottom(t_stack *list, int data);
void	pop_bottom(t_stack *list);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		pibot(t_stack *list, int num);
void	atob(t_stack *a, t_stack *b);
void	btoa(t_stack *a, t_stack *b);
void	quick(int start, int end, int *arr);
int		count_ra(t_stack *a, int data);
int		best(int ra_c, int rb_c, int new_ra_c, int new_rb_c);
int		cal(int ra, int rb);
void	count(t_stack *a, t_stack *b, int *ra_c, int *rb_c);
void	rrrab(t_stack *a, t_stack *b, int *ra_c, int *rb_c);
void	rrra(t_stack *a, int *ra_c);
void	rrrb(t_stack *b, int *rb_c);
void	finish(t_stack *a);
int		max0min1(t_stack *list, int num);
int		maxormin(t_stack *a, int min);
void	swap(int *a, int *b);
int		ft_atoi(char *str, int len);
void	insert_check(int argc, char *argv[]);
void	samesame(t_stack *a);
size_t	ft_strlen(const char *s);
void	error(void);
void	trance(t_stack *a, char *str);
void	hardcoding(t_stack *a);
void	sortcheck(t_stack *a);
void	clear(t_stack *list);
char	*get_next_line(int fd);
int		gnl_strlen(const char *s);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char const *s1, char const *s2);
void	sort(t_stack *a, t_stack *b);
void	c_sa(t_stack *a);
void	c_sb(t_stack *b);
void	c_ss(t_stack *a, t_stack *b);
void	c_pa(t_stack *a, t_stack *b);
void	c_pb(t_stack *a, t_stack *b);
void	c_ra(t_stack *a);
void	c_rb(t_stack *b);
void	c_rr(t_stack *a, t_stack *b);
void	c_rra(t_stack *a);
void	c_rrb(t_stack *b);
void	c_rrr(t_stack *a, t_stack *b);

#endif