/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_opperations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:31:04 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/08 21:38:30 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_opp	*new_opperation(char *name, t_tab *(*op)(t_tab *tab))
{
	t_opp	new;

	if (!(new = ft_memalloc(sizeof(t_opp))))
		return (NULL);
	new->name = name;
	new->op = op;
	return (new);
}

t_opp	**create_opp_list(void)
{
	int		nbr_opp;
	int		i;
	t_opp	**opp;

	i = 0;
	nbr_opp = 11;
	opp = malloc(sizeof(t_opp*) * nbr_opp + 1);
	opp[0] = new_opperation("") 
}
