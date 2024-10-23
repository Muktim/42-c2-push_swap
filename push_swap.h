/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:24:41 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/29 12:15:35 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				correct_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/*------------- INPUT VALIDATION -------------*/
int		validate_input(int ac, char **av);
int		is_sign(char c);
int		is_digit(int c);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);

/*------------- EXIT STATEMENT -------------*/
void	exit_statement(int flag, t_stack **head_a, t_stack **head_b, int **ptr);
void	free_arrays(int	*arr_a, int *arr_b);

/*------------- INITIALIZATION -------------*/
t_stack	*update_stack_values(int ac, char **av);
t_stack	*new_node(int value);
void	add_node(t_stack **head_x, t_stack *node);
int		stack_size(t_stack	*head_x);
t_stack	*get_last_node(t_stack *head_x);
t_stack	*get_second_last(t_stack *head_x);
void	update_index(t_stack *head_a, int size_a);

/*------------- ACTION!!! -------------*/
int		is_sorted(t_stack *head_x);
void	mini_sort(t_stack **head_x);
void	sort(t_stack **head_a, t_stack **head_b);
void	find_cost(t_stack **head_a, t_stack **head_b);
void	do_cheapest(t_stack **head_a, t_stack **head_b);
void	do_move(t_stack **head_a, t_stack **head_b, int cost_a, int cost_b);
int		lowest_index_position(t_stack **stack);
void	target_position(t_stack **head_a, t_stack **head_b);

/*------------- RULES -------------*/
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rr_a(t_stack **head_a);
void	rr_b(t_stack **head_b);
void	rr_both(t_stack **head_a, t_stack **head_b);
void	rot_a(t_stack **head_a);
void	rot_b(t_stack **head_b);
void	rot_both(t_stack **head_a, t_stack **head_b);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);

void	ft_putstr(char *str);
int		abso(int num);

#endif