/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_opperations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:58:48 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/14 17:48:28 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		correct_instruction(char *opp)
{
	int		ret;

	ret = 0;
	if (ft_strequ(opp, "sa") || ft_strequ(opp, "sb") || ft_strequ(opp, "ss"))
		return (1);
	else if (ft_strequ(opp, "pa") || ft_strequ(opp, "pb" ))
		return (1);
	else if (ft_strequ(opp, "ra") || ft_strequ(opp, "rb") || 
			ft_strequ(opp,"rr"))
		return (1);
	else if (ft_strequ(opp, "rra") || ft_strequ(opp, "rrb") || 
			ft_strequ(opp,"rrr"))
		return (1);
	return (ret);
}

static char		**create_opp_list(char *opp, int nbr_opp)
{
	char	**tab_opp;

	if (!(tab_opp = ft_memalloc(sizeof(char *) * (nbr_opp + 1))))
		return (NULL);
	tab_opp[nbr_opp - 1] = opp;
	tab_opp[nbr_opp] = NULL;
	return tab_opp;
}

static char		**merge_opp_tabs(char **old, char **new)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = new;
	while (old[i] != NULL)
	{
		tmp[i] = old[i];
		i++;
	}	
	return (new);
}

t_opp			*create_opp(t_opp *old)
{
	t_opp	*new;

	if (!(new = ft_memalloc((sizeof(t_opp)))))
		return (NULL);
	if (old != NULL)
		old->next = new;
	new->next = NULL;
	new->opps = NULL;
	new->nbr = 0;
	return (new);
}

t_opp			*copy_opps(t_opp *old)
{
	t_opp	*new;

	if (!(new = create_opp(NULL)))
		return (NULL);
	new->next = old->next;
	new->nbr = old->nbr;
	new->opps = ft_strtabdup(old->opps);
	return (new);
}

void			free_opp(t_opp *ope)
{
	//show_saved_opps(ope->opps, ope->nbr);
	/*while (i < ope->nbr)
	{
		strtmp = tmp[i];
//		ft_printf("FREE : %s\n", tmp[i]);
		if (strtmp)
			free(strtmp);
		strtmp = NULL;
		i++;
	}*/
	free(ope->opps);
	free(ope);
}

t_opp			*save_opp(t_opp *opps, char *opp)
{
	char	**new;
	
	if (!correct_instruction(opp))
		return (NULL);

	opps->nbr = opps->nbr + 1;
	//ft_printf("nbr opp: %d\n", *nbr_opp);
	if (!(new = create_opp_list(opp, opps->nbr)))
		return (NULL);
	if (opps->opps)
		opps->opps = merge_opp_tabs(opps->opps, new);
	else
		opps->opps = new;
	return (opps);
}
