/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_error_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:15:26 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/15 13:35:41 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_for_dubble(t_tab *tab)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < tab->size)
	{
		y = i + 1;
		while (y < tab->size)
		{
			if (tab->stack_a[i] == tab->stack_a[y])
			{
				ft_printf("DOUBLE DOUBLE i : %d y : %d\n",tab->stack_a[i],tab->stack_b[y]);
				return (0);
			}
			y++;
		}
		i++;
	}
	return (1);
}

int		check_values(char **av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (!ft_strisvalidint(av[i]))
		{
			ft_printf("int too big or invalid int");
			return(0);
		}
		i++;
	}
	return (1);
}

int		parse_arguments(int ac, char **av, t_options *options, t_tab *tab)
{
	//char	**tmp;
	if	(ac - options->nbr == 2)
		av	= ft_strsplit(av[ac - 1], ' ');
	else
		av	= &av[options->nbr + 1];
	//show_saved_nbr(av, 0);
	if (!(check_values(av)))
	{
		ft_printf("check_values\n");
		return (0);
	}
	if (!(parse_tab_struct(av, options, tab)))
		return (0);
	
	return (1);
}
