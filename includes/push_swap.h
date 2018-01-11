/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 00:14:30 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/11 22:34:30 by cvermand         ###   ########.fr       */
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
	int				r;
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
char				**save_opp(char **opps, char *opp, int *nbr_opp);

/*
 * ERROR HANDLING
 */
int					check_values(int ac, char **av, t_options *options);
/*
 *	OPPERATIONS
 */
int					swap_a_b(t_tab *tab, char pile);
int					push_a_b(t_tab *tab, char pile);
int					rot_a_b(t_tab *tab, char pile);
int					rev_rot_a_b(t_tab *tab, char pile);

/*
 * SHOW FUNCTIONS
 */
void				show_piles(t_tab *tab);
void				show_saved_opps(char **opps,int nbr_opps);
void				show_array(t_tab *tab);

/*static t_opp		g_opp[] =
{
	{"sa",&swap_a},
	{NULL,&swap_a}
};*/
#endif
