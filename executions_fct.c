/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions_fct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:01:22 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/14 19:27:51 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_opp		*execute_best_opps(t_opp *ope, t_tab *tab)
{
	t_opp	*min_nbr;
	t_opp	*tmp;
	int		i;

	i = 0;
	tmp = ope;
	min_nbr = NULL;
	while (tmp)
	{
		if (tmp->nbr == 0)
			return (ope);
		if (min_nbr == NULL)
			min_nbr = tmp;
		else
			min_nbr = (min_nbr->nbr < tmp->nbr) ? min_nbr : tmp;
		tmp = tmp->next;
	}
	while (min_nbr->opps[i])
	{
		use_instruction(min_nbr->opps[i], tab);
		i++;
	}
	return (min_nbr);
}

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
int		use_save_instruction(char *opp, t_tab *tab, t_opp *ope)
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
	if (!(save_opp(ope, opp)))
		return (0);
	return (ret);
}

int		empty_b_pile(t_tab *tab, t_opp *ope)
{
	while (tab->index_b != tab->size)
	{
		use_instruction("pa", tab);
		if (!(save_opp(ope, "pa")))
			return (0);
	}
	return (ope->nbr);
}

int		ra_until_sorted(t_tab *tab, t_opp *ope, char c)
{
//	show_piles_alligned(tab);
	while (!(pile_is_strictly_sorted(tab, c)))
	{
		//ft_printf("NEED RA IN SORTED");
		use_instruction("ra", tab);
		if (!(save_opp(ope, "ra")))
			return (0);
//		show_piles_alligned(tab);
//		show_saved_opps(ope->opps, ope->nbr);
	}
	return (ope->nbr);
}

int		rra_until_sorted(t_tab *tab, t_opp *ope, char c)
{
//	show_piles_alligned(tab);
	while (!(pile_is_strictly_sorted(tab, c)))
	{
		use_instruction("rra", tab);
		if (!(save_opp(ope,"rra")))
			return (0);
//		show_piles_alligned(tab);
//		show_saved_opps(ope->opps, ope->nbr);
	}
	return (ope->nbr);
}

