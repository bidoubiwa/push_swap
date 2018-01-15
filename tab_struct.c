/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:31:38 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/15 23:11:31 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		real_tab_to_simplified(t_tab *old, t_tab *new)
{
	int	i;
	int	j;
	int new_nbr;

	i = 0;
	if (!(new->stack_a = ft_memalloc(sizeof(int) * old->size)))
		return (0);
	if(!(new->stack_b = ft_memalloc(sizeof(int) * old->size)))
		return (0);
	new->size = old->size;
	new->index_a = old->index_a;
	new->index_b = old->index_b;
	new->options = old->options;
	while (i < new->size)
	{
		j = 0;
		new_nbr = 0;
		while (j < new->size)
		{
		//	ft_printf("old i : %d old j : %d\n", old->stack_a[i], old->stack_a[j]);
			if (old->stack_a[i] > old->stack_a[j])
				new_nbr++;
			j++;
		}
		new->stack_a[i] = new_nbr;
		i++;
	}
	return (1);
}

t_tab	*copy_tab(t_tab *old)
{
	int		i;
	t_tab	*new;

	if (!(new = ft_memalloc(sizeof(t_tab))))
		return (NULL);
	if (!(new->stack_a = ft_memalloc(sizeof(int) * old->size)))
		return (NULL);
	if(!(new->stack_b = ft_memalloc(sizeof(int) * old->size)))
		return (NULL);
	new->size = old->size;
	new->index_a = old->index_a;
	new->index_b = old->index_b;
	new->options = old->options;
	i = new->index_a;
	while (i < new->size)
	{
		new->stack_a[i] = old->stack_a[i];
		i++;
	}
	i = new->index_b;
	while (i < new->size)
	{
		new->stack_b[i] = old->stack_b[i];
		i++;
	}
	return (new);
}


void			free_tab(t_tab *tab)
{
	free(tab->stack_a);
	free(tab->stack_b);
	free(tab);
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
		i++;
		y++;
	}
	if (!check_for_dubble(tab))
	{
		free(tab->stack_a);
		free(tab->stack_b);
		return (0);
	}
	return (1);
}

t_tab	*parse_tab_struct(char **av, t_options *options,
		t_tab *tab)
{
	tab->size = ft_strtablen(av);
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
	tab->index_b = (int) tab->size;
	tab->index_a = 0;
	tab->options = options;
	if (!(copy_to_stack_a(tab, av)))
	{
		ft_printf("copy to stack\n");
		return (NULL);
	}
	return (tab);
}
