/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 23:14:05 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/08 21:51:32 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		show_piles(t_tab *tab)
{
	int i;

	i = 0;
	while (i <= tab->index_a || i <= tab->index_b)
	{
		if (i <= tab->index_a && tab->index_a != 0)
			ft_printf("\033[48;5;2m%d\033[0m\n", tab->stack_a[i]);
		if (i <= tab->index_b && tab->index_b != 0) 
			ft_printf("\033[48;5;6m%d\033[0m\n", tab->stack_b[i]);
		i++;
	}
//	ft_printf(" nbr options : %d", (tab->options)->nbr);
	ft_printf("\n");
}

static void		show_array(t_tab *tab)
{
	int i;

	i = 0;
	while (i <= tab->index_a)
	{
		if (i <= tab->index_a)
			ft_printf("%d ", tab->stack_a[i]);
		i++;
	}
	ft_printf(" nbr options : %d", (tab->options)->nbr);
	ft_printf("\n");
}

int		use_instruction(char **opp)
{
	
}

int		main(int ac, char** av)
{
	char		*line;
	t_tab		*tab;
	
	if (!(tab = create_array(ac, av)))
	{
		ft_printf("Error\n");
		return (0);
	}
	show_array(tab);
	while (get_next_line(0,&line))
	{
		ft_printf("%s\n", line);
		if ((tab->options)->d)
			if (use_instruction(line))
				return (ft_printf("Error\n"));
		else
			;// enregistrer

		if ((tab->options)->v)
			show_piles(tab);
			// show
		// stock instruction	
	}
	// check if b empty
	// check if a in order
	ft_printf("end\n");
	return (0);
}
