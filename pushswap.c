/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:21:12 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/15 23:13:28 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_opp		*push_swap(t_tab	*real_tab, t_opp *opp)
{
	t_tab	simple_tab;
	t_tab	*simple_copy;
//	t_opp	*opp1;

//	(void) opp;
	if (!(real_tab_to_simplified(real_tab, &simple_tab)))
		return (NULL);
	if (!(simple_copy = copy_tab(&simple_tab)))
		return (NULL);
//	show_piles(&simple_copy);
	// FIRST TRY
	if (simple_tab.size <= 3)
		opp = simple_no_pb(simple_copy, opp);
	else if (simple_tab.size > 3 && simple_tab.size < 10)	
		opp = simple_ra_sa_pb(simple_copy, opp);
	else if (simple_tab.size >= 10)
		opp = quick_sort(simple_copy, opp, 50);
	return (opp);
}

int		main(int ac, char **av)
{
	t_options	options;
	t_tab		tab;
	t_opp		*begin_opp;
	t_opp		*best_opp;

	if (ac == 1)
		return (ft_printf("\n"));
	if (!(begin_opp = create_opp(NULL)))
		return (ft_printf("Error\n"));
	parse_swap_options(ac, av, &options);
	if (!(parse_arguments(ac, av, &options, &tab)))
		return (ft_printf("Error\n"));
	show_array(&tab);
//	show_piles(&tab);
	if (!(begin_opp = push_swap(&tab, begin_opp)))
		return (ft_printf("Error in Push\n"));
	// REGARDER PARMIS TOUTES LES OPP POSSIBLE LA MOINS LOURD
	best_opp = execute_best_opps(begin_opp, &tab);
	show_piles(&tab);
	show_saved_opps(best_opp->opps, best_opp->nbr);
	return (0);
}
