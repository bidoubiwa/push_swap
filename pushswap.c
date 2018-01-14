/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:21:12 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/14 20:01:03 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		real_tab_to_simplified(t_tab *old, t_tab *new)
{
	int	i;
	int	j;
	int new_nbr;

	i = 0;
	if (!(new->stack_a = ft_memalloc(sizeof(int) * old->size)))
		return (0);
	if(!(new->stack_b = ft_memalloc(sizeof(int) * old->size)))
		return (0);
	new->size = old->size;
	new->index_a = old->index_a;
	new->index_b = old->index_b;
	new->options = old->options;
	while (i < new->size)
	{
		j = 0;
		new_nbr = 0;
		while (j < new->size)
		{
		//	ft_printf("old i : %d old j : %d\n", old->stack_a[i], old->stack_a[j]);
			if (old->stack_a[i] > old->stack_a[j])
				new_nbr++;
			j++;
		}
		new->stack_a[i] = new_nbr;
		i++;
	}
	return (1);
}

t_tab	*copy_tab(t_tab *old)
{
	int		i;
	t_tab	*new;

	i = 0;
	if (!(new = ft_memalloc(sizeof(t_tab))))
		return (NULL);
	if (!(new->stack_a = ft_memalloc(sizeof(int) * old->size)))
		return (NULL);
	if(!(new->stack_b = ft_memalloc(sizeof(int) * old->size)))
		return (NULL);
	new->size = old->size;
	new->index_a = old->index_a;
	new->index_b = old->index_b;
	new->options = old->options;
	while (i < new->size)
	{
		new->stack_a[i] = old->stack_a[i];
		i++;
	}
	return (new);
}

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
	
	opp = simple_ra_sa_pb(simple_copy, opp);
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
