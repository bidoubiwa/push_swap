/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 23:14:05 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/15 18:00:04 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_opp		*exec_or_save_while_read(t_opp *opps, char *line, t_tab *tab)
{
	if ((tab->options)->d)
	{
		if (!(opps = save_opp(opps, line)) ||
				!(use_instruction(line, tab)))
		{
			ft_printf("HERE Error\n");
			return (NULL);
		}
	}
	else if (!(opps = save_opp(opps, line)))
	{
			ft_printf("Error\n");
			return (NULL);
	}
	if ((tab->options)->v && (tab->options)->d)
		show_piles(tab);
	if ((tab->options)->r)
		show_saved_opps(opps->opps, opps->nbr);
	return (opps);
}

int				execution_after_read(char **opps, t_tab *tab)
{
	while (*opps)
		{
			if (!(use_instruction(*opps, tab)))
				return (0);
			if ((tab->options)->v)
				show_piles(tab);
			if ((tab->options->r))
				ft_printf("%s\n", *opps);
			opps++;
		}
	return (1);
}

int				main(int ac, char** av)
{
	char		*line;
	t_tab		tab;
	t_options	options;
	t_opp		*opps;

	opps = create_opp(NULL);
	if	(ac == 1)
		return (ft_printf("ICI\n"));
	parse_checker_options(ac, av, &options);
	if (!(parse_arguments(ac, av, &options, &tab)))
		return (ft_printf("Ici Error\n"));	
	//ft_printf("options : d: %d v: %d r: %d nbr: %d\n",options.d, options.v, options.r, options.nbr);
//	show_array(&tab);
	while (get_next_line(0,&line))
	{
		if (!(opps = exec_or_save_while_read(opps, line, &tab)))
			return (ft_printf("Error\n"));
	}
	if (options.d == 0 && opps)
	{
		if (!(execution_after_read(opps->opps, &tab)))
			return (ft_printf("Error\n"));
	}
	if (!(pile_a_sorted_b_empty(&tab)))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (0);
}
