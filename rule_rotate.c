/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:32:26 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/29 12:12:43 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot_rule(t_stack **head_x)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *head_x;
	*head_x = (*head_x)->next;
	last = get_last_node(*head_x);
	temp->next = NULL;
	last->next = temp;
}

void	rot_a(t_stack **head_a)
{
	rot_rule(head_a);
	ft_putstr("ra\n");
}

void	rot_b(t_stack **head_b)
{
	rot_rule(head_b);
	ft_putstr("rb\n");
}

void	rot_both(t_stack **head_a, t_stack **head_b)
{
	rot_rule(head_a);
	rot_rule(head_b);
	ft_putstr("rr\n");
}
