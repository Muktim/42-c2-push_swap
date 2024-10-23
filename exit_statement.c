/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_statement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:59:04 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/28 18:59:11 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arrays(int	*arr_a, int *arr_b)
{
	if (arr_a != NULL)
		free(arr_a);
	if (arr_b != NULL)
		free(arr_b);
}

static void	free_stack(t_stack **head_x)
{
	t_stack	*temp;

	if (head_x == NULL || *head_x == NULL)
		return ;
	while (*head_x)
	{
		temp = (*head_x)->next;
		free(*head_x);
		*head_x = temp;
	}
	*head_x = NULL;
}

void	exit_statement(int flag, t_stack **head_a, t_stack **head_b, int **ptr)
{
	if (ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	if (head_a != NULL && *head_a != NULL)
		free_stack(head_a);
	if (head_b != NULL && *head_b != NULL)
		free_stack(head_b);
	if (flag != 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
