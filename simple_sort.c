/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:47:04 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/15 19:22:50 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_opp	*simple_no_pb(t_tab *tab, t_opp *ope)
{
	t_opp	*cpy_ope;
	t_tab	*cpy_tab;
	
	while (!(pile_a_sorted_b_empty(tab)))
	{
		if (pile_a_is_sorted(tab))
		{
			if (!(cpy_tab = copy_tab(tab)))
				return (NULL);
			if (!(cpy_ope = copy_opps(ope)))
				return (NULL);
			ra_until_sorted(tab, ope, 'a');	
			rra_until_sorted(cpy_tab, cpy_ope, 'a');
			free_biggest_tab_ope(&tab, cpy_tab, &ope, cpy_ope);		
			return (ope);
		}
		else
			use_save_instruction("sa", tab, ope);
	}	
	return (ope);
}

t_opp	*simple_ra_sa_pb(t_tab *tab, t_opp *ope)
{
	t_opp	*cpy_ope;
	t_tab	*cpy_tab;
	
	while (!(pile_a_sorted_b_empty(tab)))
	{
		show_piles(tab);
		show_saved_opps(ope->opps, ope->nbr);
		if (pile_a_is_sorted(tab))
		{
			if (!(cpy_tab = copy_tab(tab)))
				return (NULL);
			if (!(cpy_ope = copy_opps(ope)))
				return (NULL);
			ra_until_sorted(tab, ope, 'a');	
			rra_until_sorted(cpy_tab, cpy_ope, 'a');
			free_biggest_tab_ope(&tab, cpy_tab, &ope, cpy_ope);
			empty_b_pile(tab, ope);
			return (ope);	
		}
	else if (tab->stack_a[tab->index_a] + tab->index_b == tab->size)
			use_save_instruction("pb", tab, ope);
		else if (tab->index_a < tab->size - 1 && 
				tab->stack_a[tab->index_a] > tab->stack_a[tab->index_a + 1] &&
				tab->stack_a[tab->index_a] - 1 != tab->stack_a[tab->size - 1])
		{
			use_save_instruction("sa", tab, ope);
		}
		else
		{
			use_save_instruction("ra", tab, ope);
		}
	}
	return (ope);
}
