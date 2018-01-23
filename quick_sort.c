/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:05:39 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/23 11:09:31 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int		sort_b(t_tab **tab, t_opp **ope)
{
	t_opp	*cpy_ope;
	t_tab	*cpy_tab;
	int		x;
	int		greatest;

//	ft_printf("SORT B");
	greatest = 100;	
	x = (*tab)->stack_a[(*tab)->index_a];
	if ((*tab)->index_b > (*tab)->size - 2)
	{
//		ft_printf("first elems\n");
		return (1);
	}
	greatest = greatest_in_ab(*tab, 'b');
	if (smallest_in_ab(*tab, 'b') > x || greatest < x)
	{
//		ft_printf("greatest = %d x : %d \n", greatest, x);
	//	show_piles(*tab);
		if (!(cpy_tab = copy_tab(*tab)))
			return (0);
		if (!(cpy_ope = copy_opps(*ope)))
			return (0);
		rab_until_x_number_on_top(*tab, *ope, 'b', greatest);
		rrab_until_x_number_on_top(cpy_tab, cpy_ope, 'b', greatest);
		free_biggest_tab_ope(tab, cpy_tab, ope, cpy_ope);
//		ft_printf("before pb");
	//	show_piles(*tab);
		return (1);
	}
//	ft_printf("between\n");
	greatest = find_number_just_under_x(*tab, 'b', x);
//	ft_printf("find : %d\n", greatest);
	if (!(cpy_tab = copy_tab(*tab)))
		return (0);
	if (!(cpy_ope = copy_opps(*ope)))
		return (0);
	rab_until_x_number_on_top(*tab, *ope, 'b', greatest);
	rrab_until_x_number_on_top(cpy_tab, cpy_ope, 'b', greatest);
	free_biggest_tab_ope(tab, cpy_tab, ope, cpy_ope);
//	ft_printf("FOUND\n");
	return (1);
}

int		find_number_just_under_x(t_tab *tab, char c, int x)
{
	int		i;
	int		y;
//	int		above;

	(void)c;
	i = tab->index_b;
	while (i < tab->size)
	{
		if (i == tab->size - 1)
			y = tab->index_b;
		else 
			y = i + 1;
//		ft_printf("between i : %d and y : %d\n",  tab->stack_b[i],  tab->stack_b[y]);
		if (x < tab->stack_b[i] && x > tab->stack_b[y])
		{
//			ft_printf("FOUND between i : %d and y : %d\n",  tab->stack_b[i],  tab->stack_b[y]);
			return (tab->stack_b[y]);
		}
		i++;
	}
	return (0);
}

int		smallest_in_ab(t_tab *tab, char c)
{
	int		i;
	int		smallest;

	i = tab->index_b;
	smallest = tab->size;
	if (c == 'b')
	{
		while (i < tab->size)
		{
			if (tab->stack_b[i] < smallest)
				smallest = tab->stack_b[i]; 
			i++;
		}
	}
	return (smallest);
}

int		greatest_in_ab(t_tab *tab, char c)
{
	int		i;
	int		greatest;

	i = tab->index_b;
	greatest = 0;
	if (c == 'b')
	{
		while (i < tab->size)
		{
			if (tab->stack_b[i] > greatest)
				greatest = tab->stack_b[i]; 
			i++;
		}
	}
	return (greatest);
}


int		is_there_greater_or_smaller(t_tab *tab, char c, int x)
{
	int		i;
	int		greater;
	int		smaller;

	i = tab->index_b; 
	smaller = 1;
	greater = 1;

	if (c == 'b')
	{
		while (i < tab->size)
		{
			if (tab->stack_b[i] > x)
				greater = 0;
			if (tab->stack_b[i] < x)
				smaller = 0;
			i++;
		}
	}
	//show_piles(tab);
//	ft_printf("GREATER : %d, SMALLER : %d\n", smaller, greater);
	return (smaller == 1 || greater == 1)? 1 : 0;
}

t_opp	*quick_sort(t_tab *tab, t_opp *ope, int marge)
{
	//t_opp	*cpy_ope;
	//t_tab	*cpy_tab;
	int		index_marge;
	int		tmp_marge;

	tmp_marge = marge;
	index_marge = marge;
//	show_piles(tab);
	while (!(pile_a_sorted_b_empty(tab)))
	{
//		show_piles(tab);
//		ft_printf("index_marge : %d tmp_marge = %d tab->size : %d\n",index_marge, tmp_marge, tab->size);
		if (pile_a_is_sorted(tab) || tab->index_b <= 20)
		{
			//show_piles(tab);
			//show_saved_opps(ope->opps, ope->nbr);
//			ft_printf("TRIEE PLUZOUMOINS");
			return (ope);
		}
		else if (tab->stack_a[tab->index_a] < 480)
		{
//			ft_printf("pb time\n");
			sort_b(&tab, &ope);
			use_save_instruction("pb", tab, ope);
		}
		else if (find_next_marge("ra", tab, ope)))

		else if (find_next_marge("rra", tab, ope))
			use_save_instruction("ra", tab, ope);
	}	
	ft_printf("SORI");
	return (ope);
}
