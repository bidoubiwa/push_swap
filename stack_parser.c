/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:31:38 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/04 17:30:36 by cvermand         ###   ########.fr       */
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
			if (tab->stack_a[i] == tab->stack_b[y])
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

static int		copy_to_stack_a(t_tab *tab, char **av)
{
	int	i;
	int y;

	i = 1;
	y = 0;
	while (i < tab->size + 1)
	{
		ft_printf("str : %s atoi : %d\n",av[i], ft_atoi(av[i]));
		tab->stack_a[y] = ft_atoi(av[i]);
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

static t_tab	*create_struct(int ac, char **av)
{
	t_tab	*tab;
	if (!(tab = ft_memalloc(sizeof(t_tab))))
		return (NULL);
	if (!(tab->stack_a = ft_memalloc(sizeof(int) * ac - 1)))
	{
		free(tab);
		return(NULL);
	}
	if (!(tab->stack_b = ft_memalloc(sizeof(int) * ac - 1)))
	{
		free(tab->stack_a);
		free(tab);
		return (NULL);
	}
	tab->index_b = 0;
	tab->size = ac - 1;
	tab->index_a = tab->size - 1;
	if (!copy_to_stack_a(tab,av))
	{
		ft_printf("copy to stack\n");
		return (NULL);
	}
	return (tab);
}

static int		check_values(int ac, char **av)
{
	int		i;
	int		y;

	(void) ac;
	y = 0;
	i = 1;
	while (i < ac)
	{
		if (!ft_strisvalidint(av[i]))
			return(0);
		i++;
	}
	return (1);
}

t_tab	*create_array(int ac, char **av)
{
	t_tab	*tab;
	
	if (ac == 1)
	{
		ft_printf("\n");
		return (NULL);
	}
	if (!(check_values(ac, av)))
	{
		ft_printf("check values\n");
		return (NULL);
	}
	if (!(tab = create_struct(ac, av)))
	{
		ft_printf("create struct\n");
		return (NULL);
	}
	return (tab);
}
