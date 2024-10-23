/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:20:14 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/29 12:14:53 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_index(t_stack *head_x)
{
	int	i;

	i = head_x->index;
	while (head_x)
	{
		if (head_x->index > i)
			i = head_x->index;
		head_x = head_x->next;
	}
	return (i);
}

void	mini_sort(t_stack **head_x)
{
	int	max;

	if (is_sorted(*head_x))
		return ;
	max = max_index(*head_x);
	if ((*head_x)->index == max)
		rot_a(head_x);
	else if ((*head_x)->next->index == max)
		rr_a(head_x);
	if ((*head_x)->index > (*head_x)->next->index)
		swap_a(head_x);
}
