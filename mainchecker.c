/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 23:14:05 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/13 17:16:21 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char			**execution_or_save_while_read(char **opps, char *line, 
		int *nbr_opp, t_tab *tab)
{
	if ((tab->options)->d)
	{
		if (!(opps = save_opp(opps, line, nbr_opp)) ||
				!(use_instruction(line, tab)))
		{
			ft_printf("HERE Error\n");
			return (NULL);
		}
	}
	else if (!(opps = save_opp(opps, line, nbr_opp)))
	{
		{
			ft_printf("Error\n");
			return (NULL);
		}
	}
	if ((tab->options)->v && (tab->options)->d)
		show_piles(tab);
	if ((tab->options)->r)
		show_saved_opps(opps, *nbr_opp);
	return (opps);
}

int				execution_after_read(char **opps, t_tab *tab)
{
	while (*opps)
		{
			if (!(use_instruction(*opps, tab)))
				ft_printf("Error\n");
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
	int			nbr_opp;
	char		**opps;

	opps = NULL;
	nbr_opp = 0;
	if	(ac == 1)
		return (ft_printf("\n"));
	parse_checker_options(ac, av, &options);
	if (!(parse_arguments(ac, av, &options, &tab)))
		return (ft_printf("Error\n"));	
	//ft_printf("options : d: %d v: %d r: %d nbr: %d\n",options.d, options.v, options.r, options.nbr);
	//show_array(&tab);
	while (get_next_line(0,&line))
	{
		if (!(opps = execution_or_save_while_read(opps, line, &nbr_opp, &tab)))
			return (0);
	}
	if (options.d == 0 && opps)
	{
		if (!(execution_after_read(opps, &tab)))
			return (0);
	}
	check_if_pile_is_sorted(&tab);
	ft_printf("end\n");
	return (0);
}
