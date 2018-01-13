/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:31:38 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/13 18:12:01 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_for_dubble(t_tab *tab)
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

static int		copy_to_stack_a(t_tab *tab, char **av)
{
	int	i;
	int y;

	i = 0;
	y = 0;
//	ft_printf("tab size : %d nbr optons : %d\n", tab->size, options->nbr);
	while (i < tab->size)
	{
		tab->stack_a[y] = ft_atoi(av[i]);
//		ft_printf("tab : %d\n", tab->stack_a[y]);
		i++;
		y++;
	}
	if (!check_for_dubble(tab))
	{
		free(tab->stack_a);
		free(tab->stack_b);
		free(tab);
		return (0);
	}
	return (1);
}

t_tab	*parse_tab_struct(char **av, t_options *options,
		t_tab *tab)
{
	tab->size = ft_strtablen(av);
//	ft_printf("tab len : %zu", tab->size);
	if (!(tab->stack_a = ft_memalloc(sizeof(int) * tab->size)))
	{
		free(tab);
		return(NULL);
	}
	if (!(tab->stack_b = ft_memalloc(sizeof(int) * tab->size)))
	{
		free(tab->stack_a);
		free(tab);
		return (NULL);
	}
	tab->index_b = tab->size;
	tab->index_a = 0;
	tab->options = options;
	if (!copy_to_stack_a(tab, av))
	{
		ft_printf("copy to stack\n");
		return (NULL);
	}
	return (tab);
}
