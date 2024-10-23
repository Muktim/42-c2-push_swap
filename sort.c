/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:31:42 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/29 12:12:58 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_exc_three(t_stack **head_a, t_stack **head_b)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_size(*head_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*head_a)->index <= size / 2)
		{
			push_b(head_a, head_b);
			pushed++;
		}
		else
			rot_a(head_a);
		i++;
	}
	while (size - pushed > 3)
	{
		push_b(head_a, head_b);
		pushed++;
	}
}

static void	shift_stack(t_stack **head_a)
{
	int	lowest_pos;
	int	size;

	size = stack_size(*head_a);
	lowest_pos = lowest_index_position(head_a);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rr_a(head_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rot_a(head_a);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **head_a, t_stack **head_b)
{
	push_exc_three(head_a, head_b);
	mini_sort(head_a);
	while (*head_b)
	{
		target_position(head_a, head_b);
		find_cost(head_a, head_b);
		do_cheapest(head_a, head_b);
	}
	if (!is_sorted(*head_a))
		shift_stack(head_a);
}
