/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:37:40 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/15 13:38:54 by cvermand         ###   ########.fr       */
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

