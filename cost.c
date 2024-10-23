/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:18:42 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/29 12:14:24 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cost(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *head_a;
	temp_b = *head_b;
	size_a = stack_size(temp_a);
	size_b = stack_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->pos) * -1;
		temp_b->cost_a = temp_b->correct_pos;
		if (temp_b->correct_pos > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->correct_pos) * -1;
		temp_b = temp_b->next;
	}
}

void	do_cheapest(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *head_b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (abso(temp->cost_a) + abso(temp->cost_b) < abso(cheapest))
		{
			cheapest = abso(temp->cost_a) + abso(temp->cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(head_a, head_b, cost_a, cost_b);
}
