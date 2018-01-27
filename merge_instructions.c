/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:15:04 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/27 20:47:48 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int		is_rrr_possible(t_opp *opp)
{
	int i;
	
	i = 0;
	while (i < opp->nbr - 1)
	{
		if (ft_strequ(opp->opps[i], "rra") && ft_strequ(opp->opps[i + 1], "rrb"))
			return (i);
		i++;
	}
	return (-1);
}*/

int		is_rrr_possible(t_opp *opp)
{
	int i;
	int	rrb;

	rrb = 0;
	i = opp->nbr - 1;
	ft_printf("try: ");
	while (i)
	{
		while (ft_strequ(opp->opps[i - rrb], "rrb"))
			rrb++;
		while (rrb != 0 && ft_strequ(opp->opps[i - rrb], "rrr"))
			rrb++;
		ft_printf("rb : %d i : %d opp : %s\n", rrb, i, opp->opps[i - rrb]);
		if (rrb != 0 && ft_strequ(opp->opps[i - rrb], "rra"))
			return (i - rrb);
		else
			return (-1);
		i--;
	}
	return (-1);
}


int		is_rr_possible(t_opp *opp)
{
	int i;
	int	rb;

	rb = 0;
	i = opp->nbr - 1;
	ft_printf("try: ");
	while (i)
	{
		while (ft_strequ(opp->opps[i - rb], "rb"))
			rb++;
		while (rb != 0 && ft_strequ(opp->opps[i - rb], "rr"))
			rb++;
		ft_printf("rb : %d i : %d opp : %s\n", rb, i, opp->opps[i - rb]);
		if (rb != 0 && ft_strequ(opp->opps[i - rb], "ra"))
			return (i - rb);
		else
			return (-1);
		i--;
	}
	return (-1);
}

t_opp	*merge_ra_rb(t_opp *opp, int pos, char c)
{
	t_opp	*new;
//	t_opp	*tmp;
	int		i;
	int		added;
	
	if (!(new = create_opp(NULL)))
		return (NULL);
	ft_printf("MERGE pos : %d\n", pos);
	show_opps(opp);
	added = 0;
	i = 0;
	while (i < opp->nbr)
	{
		if (i == pos)
		{
			if (c == 'r')
			{
				if (!(new = save_opp(new, "rr")))
					return (NULL);
			}
			else if (c == 'R')
			{
				if (!(new = save_opp(new, "rrr")))
					return (NULL);
			}
			added = 1;
		}
		if (added)
		{
			if (c == 'r' && ft_strequ(opp->opps[i], "rb"))
				added = 0;
			else if (c == 'R' && ft_strequ(opp->opps[i], "rrb"))
				added = 0;
			else
			{
				if (!(new = save_opp(new, opp->opps[i])))
					return (NULL);
			}
		}
		else if  (i != pos)
		{
			if (!(new = save_opp(new, opp->opps[i])))
				return (NULL);
		}
		i++;	
	}
	free(opp);
	return (new);
}
