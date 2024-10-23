/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:57:00 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/26 11:28:44 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*update_stack_values(int ac, char **av)
{
	t_stack	*head_a;
	int		i;
	int		num;

	head_a = NULL;
	num = 0;
	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (i == 1)
			head_a = new_node(num);
		else
			add_node(&head_a, new_node(num));
		i++;
	}
	return (head_a);
}

void	update_index(t_stack *head_a, int size_a)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--size_a > 0)
	{
		ptr = head_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = head_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size_a;
	}
}
