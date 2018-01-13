/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:21:12 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/13 20:21:38 by cvermand         ###   ########.fr       */
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

int		push_swap(t_tab	*real_tab, t_opp *opp)
{
	t_tab	simple_tab;

	(void) opp;
	if (!(real_tab_to_simplified(real_tab, &simple_tab)))
		return (0);

	show_piles(&simple_tab);
	return (1);
}

int		main(int ac, char **av)
{
	t_options	options;
	t_tab		tab;
	t_opp		opp;

	if (ac == 1)
		return (ft_printf("\n"));
	parse_swap_options(ac, av, &options);
	if (!(parse_arguments(ac, av, &options, &tab)))
		return (ft_printf("Error\n"));
	show_array(&tab);
//	show_piles(&tab);
	opp.nbr = 0;
	opp.opps = NULL;
	if (!(push_swap(&tab, &opp)))
		return (ft_printf("Error\n"));
	return (0);
}
