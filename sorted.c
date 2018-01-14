/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:41:10 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/14 18:08:41 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				pile_a_is_sorted(t_tab *tab)
{
	int	i;
	int	y;

//	ft_printf("size : %zu\n", tab->size);
//	show_piles(tab);
	i = tab->index_a;
	while (i < tab->size - 2 && tab->stack_a[i] == tab->stack_a[i + 1] - 1)
	{
	//	ft_printf("i bef: %d val : %d, val + 1 : %d i : %d\n",i, tab->stack_a[i], tab->stack_a[i + 1], i+ 1);
		i++;
	}
//	ft_printf("i : %d y : %d \n", i, i + 1);
	y = i + 1;
	while (y < tab->size - 2 && tab->stack_a[y] == tab->stack_a[y + 1] - 1)
		y++;
//	ft_printf("y : %d \n", y);
	if (tab->stack_a[tab->index_a] == tab->stack_a[tab->size - 1] + 1 && i + 2 != tab->size)
		y++;
//	ft_printf("y : %d \n", y);
	if (y == tab->size - 1)
		return (1);
	//		ft_printf("i : %d i + 1 : %d", tab->)
	return (0);
}

int				pile_a_sorted_b_empty(t_tab *tab)
{
	int	i;

	i = 0;
	if (tab->index_a == 0 && tab->index_b == tab->size)
	{
	//	ft_printf("index_a : %d index_b : %d", tab->index_a, tab->index_b);
		while (i < tab->size - 1)
		{
	//		ft_printf("i : %d i + 1 : %d", tab->)
			if (tab->stack_a[i] >= tab->stack_a[i + 1])
				return (0);
			i++;
		}
//		ft_printf("\033[38;5;40mSORTED FROM START\033[0m\n");
		return (1);
	}
	else
		return (0);
}

int				pile_is_strictly_sorted(t_tab *tab,char c)
{
	int	i;

	if (c == 'a')
	{
		i = tab->index_a;
		while (i < tab->size - 1)
		{
	//		ft_printf("i : %d i + 1 : %d", tab->)
			if (tab->stack_a[i] >= tab->stack_a[i + 1])
				return (0);
			i++;
		}
	}
	else if (c == 'b')
	{
		i = tab->index_b;
		while (i < tab->size - 1)
		{
	//		ft_printf("i : %d i + 1 : %d", tab->)
			if (tab->stack_b[i] >= tab->stack_b[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

int				check_if_pile_is_sorted(t_tab *tab)
{
	int	i;

	i = 0;
	if (tab->index_a == 0 && tab->index_b == tab->size)
	{
	//	ft_printf("index_a : %d index_b : %d", tab->index_a, tab->index_b);
		while (i < tab->size - 1)
		{
	//		ft_printf("i : %d i + 1 : %d", tab->)
			if (tab->stack_a[i] >= tab->stack_a[i + 1])
				return (ft_printf("KO\n"));
			i++;
		}
		return (ft_printf("OK\n"));
	}
	else
		return (ft_printf("KO\n"));
}


