/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:37:40 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/27 20:47:37 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_biggest_tab_ope(t_tab **tab, t_tab *tab_c, t_opp **opp, 
		t_opp *opp_c)
{
	if (opp_c->nbr < (*opp)->nbr)
	{
		free_opp(*opp);
		free_tab(*tab);
		*opp = opp_c;
		*tab = tab_c;
	}
	else 
	{
		free_opp(opp_c);
		free_tab(tab_c);
	}
}

t_opp	*find_next_marge(char *instruct, t_tab **tab, t_opp **ope, int limit)
{	
	int	pos;

	while ((*tab)->stack_a[(*tab)->index_a] > limit)
		use_save_instruction(instruct, *tab, *ope);
	//ft_printf("Apres ra \n");
	//show_opps(*ope);
	//ft_printf("first opp : %s\n", (*ope)->opps[0]);
	if (ft_strequ(instruct, "ra"))
	{
		sort_b(tab, ope, 'r');
	//	ft_printf("retour sort b\n");
		ft_printf("RR\n");
		while ((pos = is_rr_possible(*ope)) >= 0)
		{
			ft_printf("rr possible : \n");
			show_opps(*ope);
			*ope = merge_ra_rb(*ope, pos, 'r');
			ft_printf("rr apres merge: \n");
			show_opps(*ope);
		}
		ft_printf("FIN : \n");
		show_opps(*ope);
		ft_printf("----------------------\n\n");
		use_save_instruction("pb", (*tab), (*ope));
	}
	else if (ft_strequ(instruct, "rra"))
	{
		sort_b(tab, ope, 'R');
	//	ft_printf("retour sort b\n");
		ft_printf("RR\n");
		while ((pos = is_rrr_possible(*ope)) >= 0)
		{
			ft_printf("rrr possible : \n");
			show_opps(*ope);
			*ope = merge_ra_rb(*ope, pos, 'R');
		}
		ft_printf("FIN : \n");
		show_opps(*ope);
		ft_printf("----------------------\n\n");
		use_save_instruction("pb", (*tab), (*ope));
	}
	//ft_printf("retour merge\n");
	//show_opps(*ope);
	return (*ope);
}

/*t_opp	*merge_ra_rb(t_opp *ope)
{
	

}*/
