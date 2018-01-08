/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 00:27:29 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/08 21:44:51 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tab		*swap_a(t_tab *tab)
{
	int		*a;

	a = tab->stack_a;
	if (tab->index_a > 1)
	{
		ft_swap(&a[0], &a[1]);
	}
	return (tab);
}

void	push_b(int *a, int *b)
{
	*b = *b - 1;
	*a = *a - 1;
}

void	push_a(int *a, int *b)
{
	*b = *b + 1;
	*a = *a + 1;
}

/*void	rotate_a(int *a, int *liste, size_t size)
{
	int		tmp;
	int		i;

	i = 0;
	while (*a--)
	{
		if (i == size)
			i =  0;
		else
		{
			tmp = list[i + 1];
			list[i + 1] = list[i];
		}

	}
}*/
