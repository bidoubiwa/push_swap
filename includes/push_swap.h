/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 00:14:30 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/11 14:15:01 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#include "../libft/includes/libft.h"

/*
 * OPTIONS = 
 */
typedef struct		s_options
{
	int				v;
	int				d;
	int				nbr;
}					t_options;	

typedef struct		s_tab
{
	int				*stack_a;
	int				index_a;
	int				*stack_b;
	int				index_b;
	int				size;
	t_options		*options;
}					t_tab;

/*typedef struct		s_opp
{
	char			*name;
	t_tab			*(*op)(t_tab *tab);
}					t_opp;*/

/*
 *	INITIALISE VALUES
 */
t_tab				*create_array(int ac, char **av);
/*
 * ERROR HANDLING
 */
int					check_values(int ac, char **av, t_options *options);
/*
 *	OPPERATIONS
 */
t_tab				*swap_a_b(t_tab *tab, char pile);
/*
 *	OPPERATIONS
 */
t_tab		*swap_a(t_tab *tab);

/*static t_opp		g_opp[] =
{
	{"sa",&swap_a},
	{NULL,&swap_a}
};*/
#endif
