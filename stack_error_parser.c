/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_error_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:15:26 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/08 18:15:57 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_option(char *s, t_options *options)
{
	if (ft_strequ(s,"-v") && options->v == 0)
	{
		options->v = 1;
		options->nbr = options->nbr + 1;
		return (1);
	}
	if (ft_strequ(s,"-d") && options->d == 0)
	{
		options->d = 1;
		options->nbr = options->nbr + 1;
		return (1);
	}
 
	return (0);
}

int		check_values(int ac, char **av, t_options *options)
{
	int		i;

	i = 1;
	while (is_option(av[i], options) && i < ac)
		i++;
	while (i < ac)
	{	
		if (!ft_strisvalidint(av[i]))
			return(0);
		i++;
	}
	if (options->nbr + 1 == ac)
		return (0);
	return (1);
}

