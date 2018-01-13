/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions_fct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:01:22 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/13 17:08:18 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		use_instruction(char *opp, t_tab *tab)
{
	int		ret;

	ret = 0;
	if (ft_strequ(opp, "sa") || ft_strequ(opp, "sb") || ft_strequ(opp, "ss"))
		ret = swap_a_b(tab, opp[1]);
	else if (ft_strequ(opp, "pa") || ft_strequ(opp, "pb" ))
		ret = push_a_b(tab, opp[1]);
	else if (ft_strequ(opp, "ra") || ft_strequ(opp, "rb") || 
			ft_strequ(opp,"rr"))
		ret = rot_a_b(tab, opp[1]);
	else if (ft_strequ(opp, "rra") || ft_strequ(opp, "rrb") || 
			ft_strequ(opp,"rrr"))
		ret = rev_rot_a_b(tab, opp[2]);
	return (ret);
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


