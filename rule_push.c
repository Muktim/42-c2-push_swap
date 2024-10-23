/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:47:46 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/24 19:52:11 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_rule(t_stack **head_s, t_stack **head_d)
{
	t_stack	*temp;

	if (*head_s == NULL)
		return ;
	temp = (*head_s)->next;
	(*head_s)->next = *head_d;
	*head_d = *head_s;
	*head_s = temp;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push_rule(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push_rule(stack_a, stack_b);
	ft_putstr("pb\n");
}
