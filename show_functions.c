/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:37:38 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/13 18:15:15 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		show_piles(t_tab *tab)
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
	//ft_printf("index_a = %d index_b = %d",tab->index_a, tab->index_b);
	//ft_printf("\n");
}

void			show_saved_opps(char **opps, int nbr_opps)
{
	char **tmp;

	if (opps)
	{
		tmp = opps;	
		ft_printf("\033[38;5;33mOpperations : \033[0m");
		while (*tmp)
		{
			ft_printf("%s ", *tmp);
			tmp++;
		}
		ft_printf("\n");
	}
	ft_printf("\033[38;5;93mNombre opperations : \033[0m%d\n", nbr_opps);

}

void			show_saved_nbr(char **opps, int nbr_opps)
{
	char **tmp;

	(void) nbr_opps;
	if (opps)
	{
		tmp = opps;	
		ft_printf("\033[38;5;33mAll numbers : \033[0m");
		while (*tmp)
		{
			ft_printf("%s ", *tmp);
			tmp++;
		}
		ft_printf("\n");
	}
	ft_printf("\033[38;5;93mSize list : \033[0m%d\n", ft_strtablen(opps));

}


// a supprimer
void		show_array(t_tab *tab)
{
	int i;

	i = 0;
	while (i < tab->size)
	{
		ft_printf("%d ", tab->stack_a[i]);
		i++;
	}
	//ft_printf(" nbr options : %d", (tab->options)->nbr);
	ft_printf("\n");
}


