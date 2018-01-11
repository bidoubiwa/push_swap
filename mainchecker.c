/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 23:14:05 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/11 17:43:06 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		show_piles(t_tab *tab)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (i < tab->size || y < tab->size)
	{
		if (i >= tab->index_a)
			ft_printf("\033[38;5;34m%5d\033[0m", tab->stack_a[i]);
		else
			ft_printf("%5c",'.');
		if (y >= tab->index_b) 
			ft_printf("\033[38;5;33m%5d\033[0m", tab->stack_b[i]);
		else
			ft_printf("%5c",'.');
		ft_printf("\n");
		i++;
		y++;
	}
//	ft_printf(" nbr options : %d", (tab->options)->nbr);
	ft_printf("index_a = %d index_b = %d",tab->index_a, tab->index_b);
	ft_printf("\n");
}

// a supprimer
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
		ft_printf("%s\n", line);
		if ((tab->options)->d)
		{
			if (!use_instruction(line, tab))
				return (ft_printf("Error\n"));
		}
		else
		{
			if (!(opps = save_opp(opps, line, &nbr_opp)))
				return (ft_printf("Error\n"));
		}
		if ((tab->options)->v && (tab->options)->d)
			show_piles(tab);
	}
	// check if b empty
	// check if a in order
	ft_printf("end\n");
	return (0);
}
