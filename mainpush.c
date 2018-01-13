/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:13:25 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/12 16:17:15 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
//	char		*line;
	t_tab		*tab;
	int			nbr_opp;
//	char		**opps;

	opps = NULL;
	nbr_opp = 0;
	if (!(tab = create_array(ac, av)))
		return (ft_printf("Error\n"));
	show_array(tab);
	show_piles(tab);
	check_if_pile_is_sorted(tab);
	ft_printf("end\n");
	return (0);
}
