/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:31:38 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/08 18:36:50 by cvermand         ###   ########.fr       */
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
				ft_printf("i : %d y : %d\n",tab->stack_a[i],tab->stack_b[y]);
				return (0);
			}
			y++;
		}
		i++;
	}
	return (1);
}

static int		copy_to_stack_a(t_tab *tab, char **av, t_options *options)
{
	int	i;
	int y;

	i = 1 + options->nbr;
	y = 0;
//	ft_printf("tab size : %d nbr optons : %d\n", tab->size, options->nbr);
	while (i < tab->size + 1 + options->nbr)
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

static t_tab	*create_struct(int ac, char **av, t_options *options)
{
	t_tab	*tab;
	if (!(tab = ft_memalloc(sizeof(t_tab))))
		return (NULL);
	tab->size = ac - options->nbr - 1;
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
	tab->index_b = 0;
	tab->index_a = tab->size - 1;
	tab->options = options;
	if (!copy_to_stack_a(tab, av, options))
	{
		ft_printf("copy to stack\n");
		return (NULL);
	}
	return (tab);
}

static t_options		*create_option_struct(void)
{
	t_options	*options;

	if (!(options = ft_memalloc(sizeof(t_options))))
		return (NULL);
	options->v = 0;
	options->d = 0;
	options->nbr = 0;
	return (options);
}

t_tab					*create_array(int ac, char **av)
{
	t_tab		*tab;
	t_options	*options;

	if (ac == 1)
	{
		ft_printf("\n");
		return (NULL);
	}
	if (!(options = create_option_struct()))
	{
		ft_printf("Create Options struct\n");
		return (NULL);
	}
	if (!(check_values(ac, av, options)))
	{
		ft_printf("check values\n");
		return (NULL);
	}
	if (!(tab = create_struct(ac, av, options)))
	{
		ft_printf("create struct\n");
		return (NULL);
	}
	return (tab);
}
