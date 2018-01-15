/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:05:39 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/15 20:10:56 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_opp	*sort_b(t_tab **tab, t_opp **ope)
{
	t_opp	*cpy_ope;
	t_tab	*cpy_tab;

	if ((*tab)->stack_a[(*tab)->index_a] == 0)
	{
		use_save_instruction("pb", *tab, *ope);
		return (*ope);
	}
	if (!(cpy_tab = copy_tab(*tab)))
		return (NULL);
	if (!(cpy_ope = copy_opps(*ope)))
		return (NULL);
	rab_until_x_number_on_top(*tab, *ope, 'b', (*tab)->stack_a[(*tab)->index_a]);
	rrab_until_x_number_on_top(cpy_tab, cpy_ope, 'b', (*tab)->stack_a[(*tab)->index_a]);
	free_biggest_tab_ope(tab, cpy_tab, ope, cpy_ope);
	return (*ope);
}

t_opp	*quick_sort(t_tab *tab, t_opp *ope, int marge)
{
	//t_opp	*cpy_ope;
	//t_tab	*cpy_tab;
	int		index_marge;
	int		tmp_marge;

	tmp_marge = marge;
	index_marge = marge;
		show_piles(tab);
	while (!(pile_a_sorted_b_empty(tab)) && tmp_marge < tab->size)
	{
		show_piles(tab);
		show_saved_opps(ope->opps, ope->nbr);
//		ft_printf("index_marge : %d tmp_marge = %d tab->size : %d\n",index_marge, tmp_marge, tab->size);
		if (pile_a_is_sorted(tab))
		{
			ft_printf("TRIEE PLUZOUMOINS");
			return (ope);
		}
		if (index_marge == 0)
		{
			index_marge = marge;
			tmp_marge += marge;
		}
		else if (tab->stack_a[tab->index_a] < 480)
		{
			sort_b(&tab, &ope);
			// inserer dans b le moins cher possible
			use_save_instruction("pb", tab, ope);
			index_marge--;
		}
		else
			use_save_instruction("ra", tab, ope);
	}	
	ft_printf("SORI");
	return (ope);
}
