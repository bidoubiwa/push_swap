/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 23:14:05 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/04 17:27:56 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		show_array(t_tab *tab)
{
	int i;

	i = 0;
	while (i < tab->size)
	{
		ft_printf("%d ", tab->stack_a[i]);
		i++;
	}
	ft_printf("\n");
}

int		main(int ac, char** av)
{
	char	*line;
	t_tab	*tab;

	if (!(tab = create_array(ac, av)))
	{
		ft_printf("Error\n");
		return (0);
	}
	show_array(tab);
	while (get_next_line(0,&line))
	{
		ft_printf("%s\n", line);
		// stock instruction
		
	}
	// check if b empty
	// check if a in order
	ft_printf("end\n");
	return (0);
}
