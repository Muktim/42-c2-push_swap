/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:21:37 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/28 19:15:57 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *head_x)
{
	while (head_x->next != NULL)
	{
		if (head_x->value > head_x->next->value)
			return (0);
		head_x = head_x->next;
	}
	return (1);
}

static void	push_swap(t_stack **head_a, t_stack **head_b, int size_a)
{
	if (size_a == 2 && !is_sorted(*head_a))
		swap_a(head_a);
	else if (size_a == 3 && !is_sorted(*head_a))
		mini_sort(head_a);
	else if (size_a > 3 && !is_sorted(*head_a))
		sort(head_a, head_b);
}

int	main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		size_a;

	if (ac < 2)
		return (0);
	if (validate_input(ac, av) == -1)
		exit_statement(-1, NULL, NULL, NULL);
	head_a = update_stack_values(ac, av);
	head_b = NULL;
	size_a = stack_size(head_a);
	update_index(head_a, size_a + 1);
	push_swap(&head_a, &head_b, size_a);
	exit_statement(0, &head_a, &head_b, NULL);
	return (0);
}
