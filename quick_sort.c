/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:05:39 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/27 19:04:36 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	toto(void)
{
	ft_printf("toto\n");
}

int		sort_b(t_tab **tab, t_opp **ope, char c)
{
	int		x;
	int		greatest;

	greatest = 0;	
	x = (*tab)->stack_a[(*tab)->index_a];
	if ((*tab)->index_b > (*tab)->size - 2)
	{
//		ft_printf("first elems\n");
		return (1);
	}
	greatest = greatest_in_ab(*tab, 'b');
	if (smallest_in_ab(*tab, 'b') > x || greatest < x)
	{
		if (c == 'r')
			rab_until_x_number_on_top(*tab, *ope, 'b', greatest);
		else if (c == 'R')
			rrab_until_x_number_on_top(*tab, *ope, 'b', greatest);
	//	show_piles(*tab);
		return (1);
	}
	greatest = find_number_just_under_x(*tab, 'b', x);
//	ft_printf("find : %d\n", greatest);
	if (c == 'r')
		rab_until_x_number_on_top(*tab, *ope, 'b', greatest);
	else if (c == 'R')
		rrab_until_x_number_on_top(*tab, *ope, 'b', greatest);
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
		if (x < tab->stack_b[i] && x > tab->stack_b[y])
		{
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

/*t_opp	*push_back_in_a(t_tab *tab, t_opp *ope)
{
	

}*/

t_opp	*quick_sort(t_tab *tab, t_opp *ope, int marge)
{
	t_opp	*cpy_ope;
	t_tab	*cpy_tab;
	int		index_marge;
	int		tmp_marge;

	tmp_marge = marge;
	index_marge = 0;
//	show_piles(tab);
	while (!(pile_a_sorted_b_empty(tab)))
	{
//		show_piles(tab);
//		ft_printf("index_marge : %d tmp_marge = %d tab->size : %d\n",index_marge, tmp_marge, tab->size);
		if (pile_a_is_sorted(tab) || tab->index_a == tab->size)
		{
			show_piles(tab);
			show_opps(ope);
			return (ope);
		}
		/*else if (tmp_marge  > tab->size - marge)
		{
			
			show_piles(tab);
			show_opps(ope);
			return (ope);
		}*/
		else
		{
			if (!(cpy_tab = copy_tab(tab)))
				return (0);
			if (!(cpy_ope = copy_opps(ope)))
				return (0);
			ope = find_next_marge("ra", &tab, &ope, tmp_marge);
			cpy_ope = find_next_marge("rra", &cpy_tab, &cpy_ope, tmp_marge);
			free_biggest_tab_ope(&tab, cpy_tab, &ope, cpy_ope);
			index_marge++;
			if (index_marge == tmp_marge)
			{
				tmp_marge = tmp_marge + marge;
				ft_printf("nbr opp : %d \n", ope->nbr);
			}
		}
	}	
	ft_printf("SORI");
	return (ope);
}
