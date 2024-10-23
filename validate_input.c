/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:46:21 by mcoskune          #+#    #+#             */
/*   Updated: 2024/06/21 15:55:55 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sign_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!(is_digit(av[i][j]) || is_sign(av[i][j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	has_number(char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (av[i])
	{
		j = 0;
		count = 0;
		while (av[i][j] != '\0')
		{
			if (is_digit(av[i][j]))
				count++;
			j++;
		}
		if (count == 0)
			return (1);
		i++;
	}
	return (0);
}

static int	is_duplicate(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] && i < ac - 1)
	{
		j = i + 1;
		while (av[j] && j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	out_int_bounds(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	validate_input(int ac, char **av)
{
	if (is_sign_digit(ac, av) == 1 || has_number(av) == 1 || \
		is_duplicate(ac, av) == 1 || out_int_bounds(ac, av) == 1)
		return (-1);
	return (0);
}
