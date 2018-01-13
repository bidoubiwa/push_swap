/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:11:42 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/13 18:06:58 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_checker_option(char *s, t_options *options)
{
	//ft_printf("in is_options nbr : %d\n", options->nbr);
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
	if (ft_strequ(s,"-r") && options->r == 0)
	{
		options->r = 1;
		options->nbr = options->nbr + 1;
		return (1);
	}
	return (0);
}


void	parse_checker_options(int ac, char **av, t_options *options)
{
//	t_options	*options;
	int			i;

	i = 1;
	options->v = 0;
	options->d = 0;
	options->r = 0;
	options->nbr = 0;
	while (i < ac && is_checker_option(av[i], options))
		i++;
}
