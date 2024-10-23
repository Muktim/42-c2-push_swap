/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:51:36 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/29 12:14:00 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rr_both(t_stack **h_a, t_stack **h_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rr_both(h_a, h_b);
	}
}

static void	do_rot_both(t_stack **h_a, t_stack **h_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rot_both(h_a, h_b);
	}
}

static void	do_rotate_a(t_stack **head_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rot_a(head_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rr_a(head_a);
			(*cost)++;
		}
	}
}

static void	do_rotate_b(t_stack **head_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rot_b(head_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rr_b(head_b);
			(*cost)++;
		}
	}
}

void	do_move(t_stack **head_a, t_stack **head_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rr_both(head_a, head_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rot_both(head_a, head_b, &cost_a, &cost_b);
	do_rotate_a(head_a, &cost_a);
	do_rotate_b(head_b, &cost_b);
	push_a(head_a, head_b);
}
