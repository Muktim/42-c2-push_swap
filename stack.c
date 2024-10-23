/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:35:17 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/29 12:13:06 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last_node(t_stack *head_x)
{
	while (head_x && head_x->next != NULL)
		head_x = head_x->next;
	return (head_x);
}

t_stack	*get_second_last(t_stack *head_x)
{
	while (head_x && head_x->next && head_x->next->next != NULL)
		head_x = head_x->next;
	return (head_x);
}

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->pos = -1;
	node->correct_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	return (node);
}

void	add_node(t_stack **head_x, t_stack *node)
{
	t_stack	*tail;

	if (!node)
		return ;
	if (!*head_x)
	{
		*head_x = node;
		return ;
	}
	tail = get_last_node(*head_x);
	tail->next = node;
}

int	stack_size(t_stack	*head_x)
{
	int	size;

	size = 0;
	if (!head_x)
		return (0);
	while (head_x)
	{
		head_x = head_x->next;
		size++;
	}
	return (size);
}
