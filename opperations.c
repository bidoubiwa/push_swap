/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 00:27:29 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/11 14:13:18 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tab		*swap_a_b(t_tab *tab, char pile)
{
	int		*tmp;

	if ( pile == 'a' && tab->index_a > 1)
	{
		tmp = tab->stack_a;
		ft_swap(&tmp[0], &tmp[1]);
	}
	else if (pile == 'b' && tab->index_b > 1)
	{
		tmp = tab->stack_b;
		ft_swap(&tmp[0], &tmp[1]);
	}
	else if (pile == 's')
	{
		tab = swap_a_b(tab, 'a');
		tab = swap_a_b(tab, 'b');
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
