/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 23:14:05 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/11 22:54:55 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static	int		use_instruction(char *opp, t_tab *tab)
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


int				main(int ac, char** av)
{
	char		*line;
	t_tab		*tab;
	int			nbr_opp;
	char		**opps;

	opps = NULL;
	nbr_opp = 0;
	if (!(tab = create_array(ac, av)))
	{
		ft_printf("Error\n");
		return (0);
	}
	show_array(tab);
	while (get_next_line(0,&line))
	{
		if ((tab->options)->d)
		{
			if (!(opps = save_opp(opps, line, &nbr_opp)) ||
						!(use_instruction(line, tab)))
				return (ft_printf("Error\n"));
		}
		else
		{
			if (!(opps = save_opp(opps, line, &nbr_opp)))
				return (ft_printf("Error\n"));
		}
		if ((tab->options)->v && (tab->options)->d)
			show_piles(tab);
		if ((tab->options)->r)
			show_saved_opps(opps, nbr_opp);
	}
	if ((tab->options)->d == 0 && opps)
	{
		while (*opps)
		{
			if (!(use_instruction(*opps, tab)))
				return (ft_printf("Error\n"));
			if ((tab->options)->v)
				show_piles(tab);
			if ((tab->options->r))
				ft_printf("%s\n", *opps);
			opps++;
		}
	}

	// check if b empty
	// check if a in order
	ft_printf("end\n");
	return (0);
}
