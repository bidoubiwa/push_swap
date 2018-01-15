/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions_fct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:01:22 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/16 00:09:23 by cvermand         ###   ########.fr       */
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
int		rab_until_x_number_on_top(t_tab *tab, t_opp *opp, char c, int x)
{
	if (c == 'b')
	{
		while (!(tab->stack_b[tab->index_b] == x))
		{
			if (!(use_save_instruction("rb", tab, opp)))
				return (0);
		}
	}
//	ft_printf("x : %d index b : %d begin b : %d\n", x, tab->stack_b[tab->index_b], tab->stack_b[tab->size - 1]);
	return (opp->nbr);
}

int		rrab_until_x_number_on_top(t_tab *tab, t_opp *opp, char c, int x)
{
	if (c == 'b')
	{
		while (!(tab->stack_b[tab->index_b] == x))
		{
			//show_piles(tab);
			if (!(use_save_instruction("rrb", tab, opp)))
				return (0);
		}
	}
//	ft_printf("x : %d index b : %d begin b : %d\n", x, tab->stack_b[tab->index_b], tab->stack_b[tab->size - 1]);
	return (opp->nbr);
}


int		rab_until_x_number_on_top_greater(t_tab *tab, t_opp *opp, char c, int x)
{
	if (c == 'b')
	{
		show_piles(tab);
		while (!(tab->stack_b[tab->index_b] > x && tab->stack_b[tab->size - 1] < x))
		{
			if (!(use_save_instruction("rb", tab, opp)))
				return (0);
		}
	}
	ft_printf("x : %d index b : %d begin b : %d\n", x, tab->stack_b[tab->index_b], tab->stack_b[tab->size - 1]);
	return (opp->nbr);
}

int		rrab_until_x_number_on_top_greater(t_tab *tab, t_opp *opp, char c, int x)
{
	if (c == 'b')
	{
		while (!(tab->stack_b[tab->index_b] > x && tab->stack_b[tab->size - 1] < x))
		{
			if (!(use_save_instruction("rrb", tab, opp)))
				return (0);
		}
	}
	ft_printf("x : %d index b : %d begin b : %d\n", x, tab->stack_b[tab->index_b], tab->stack_b[tab->size - 1]);
	return (opp->nbr);
}

int		empty_b_pile(t_tab *tab, t_opp *ope)
{
	while (tab->index_b != tab->size)
	{
		if (!(use_save_instruction("pa", tab, ope)))
			return (0);
	}
	return (ope->nbr);
}

int		ra_until_sorted(t_tab *tab, t_opp *ope, char c)
{
	while (!(pile_is_strictly_sorted(tab, c)))
	{
		if (!(use_save_instruction("ra", tab, ope)))
			return (0);
	}
	return (ope->nbr);
}

int		rra_until_sorted(t_tab *tab, t_opp *ope, char c)
{
	while (!(pile_is_strictly_sorted(tab, c)))
	{
		if (!(use_save_instruction("rra", tab, ope)))
			return (0);
	}
	return (ope->nbr);
}

