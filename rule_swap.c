/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:52:30 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/29 12:12:50 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_rule(t_stack *head_x)
{
	int	temp;

	if (head_x == NULL || head_x->next == NULL)
		return ;
	temp = head_x->value;
	head_x->value = head_x->next->value;
	head_x->next->value = temp;
	temp = head_x->index;
	head_x->index = head_x->next->index;
	head_x->next->index = temp;
}

void	swap_a(t_stack **stack_a)
{
	swap_rule(*stack_a);
	ft_putstr("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	swap_rule(*stack_b);
	ft_putstr("sb\n");
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap_rule(*stack_a);
	swap_rule(*stack_b);
	ft_putstr("ss\n");
}
