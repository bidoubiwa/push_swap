/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 00:27:29 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/15 23:58:11 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap_a_b(t_tab *tab, char pile)
{
	int		*tmp;

	if (pile == 'a' && tab->index_a < tab->size - 1)
	{
		tmp = tab->stack_a;
		ft_swap(&tmp[tab->index_a], &tmp[tab->index_a + 1]);
	}
	else if (pile == 'b' && tab->index_b < tab->size - 1)
	{
		tmp = tab->stack_b;
		ft_swap(&tmp[tab->index_b], &tmp[tab->index_b + 1]);
	}
	else if (pile == 's')
	{
		swap_a_b(tab, 'a');
		swap_a_b(tab, 'b');
	}
	return (1);
}

int		push_a_b(t_tab *tab, char pile)
{
	if (pile == 'a' && tab->index_b < tab->size)
	{
		tab->index_a = tab->index_a - 1;
		tab->stack_a[tab->index_a] = tab->stack_b[tab->index_b];
		tab->index_b = tab->index_b + 1;
	}
	else if (pile == 'b' && tab->index_a < tab->size)
	{
		tab->index_b = tab->index_b - 1;
		tab->stack_b[tab->index_b] = tab->stack_a[tab->index_a];
		tab->index_a = tab->index_a + 1;
	}
	return (1);
}

int		rot_a_b(t_tab *tab, char pile)
{
	int		i;
	int		tmp;

	if (pile == 'a' && tab->index_a < tab->size - 1)
	{
		i = tab->index_a - 1;
		tmp = tab->stack_a[tab->index_a];
		while (++i < tab->size - 1)
			tab->stack_a[i] = tab->stack_a[i + 1];
		tab->stack_a[i] = tmp;
	}
	else if (pile == 'b' && tab->index_b < tab->size - 1)
	{
		i = tab->index_b - 1;
		tmp = tab->stack_b[tab->index_b];
		while (++i < tab->size - 1)
			tab->stack_b[i] = tab->stack_b[i + 1];
		tab->stack_b[i] = tmp;
	}
	else if (pile == 'r')
	{
		rot_a_b(tab, 'a');
		rot_a_b(tab, 'b');
	}
	return (1);
}

int		rev_rot_a_b(t_tab *tab, char pile)
{
	int		i;
	int		tmp;

	if (pile == 'a' && tab->index_a < tab->size - 1)
	{
		i = tab->size;
		tmp = tab->stack_a[tab->size - 1];
		while (--i > tab->index_a)
			tab->stack_a[i] = tab->stack_a[i - 1];
		tab->stack_a[i] = tmp;
	}
	else if (pile == 'b' && tab->index_b < tab->size - 1)
	{
		
		i = tab->size;
		tmp = tab->stack_b[tab->size - 1];
		while (--i > tab->index_b)
		{
			tab->stack_b[i] = tab->stack_b[i - 1];
		}
		tab->stack_b[i] = tmp;
	}
	else if (pile == 'r')
	{
		rev_rot_a_b(tab, 'a');
		rev_rot_a_b(tab, 'b');
	}
	return (1);
}
