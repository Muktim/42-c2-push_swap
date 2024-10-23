/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:12:26 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/29 12:14:37 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr_rule(t_stack **head_x)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*sec_last;

	last = get_last_node(*head_x);
	sec_last = get_second_last(*head_x);
	temp = *head_x;
	*head_x = last;
	(*head_x)->next = temp;
	sec_last->next = NULL;
}

void	rr_a(t_stack **head_a)
{
	rr_rule(head_a);
	ft_putstr("rra\n");
}

void	rr_b(t_stack **head_b)
{
	rr_rule(head_b);
	ft_putstr("rrb\n");
}

void	rr_both(t_stack **head_a, t_stack **head_b)
{
	rr_rule(head_a);
	rr_rule(head_b);
	ft_putstr("rrr\n");
}
