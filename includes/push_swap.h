/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 00:14:30 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/13 18:37:18 by cvermand         ###   ########.fr       */
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

typedef struct		s_opp
{
	char			**opps;
	int				nbr;
}					t_opp;

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
void				parse_checker_options(int ac, char **av, t_options *options);
void				parse_swap_options(int ac, char **av, t_options *options);
t_tab				*parse_tab_struct(char **av, t_options *options,
		t_tab *tab);
int					parse_arguments(int ac, char **av, t_options *options, t_tab *tab);
/*
 * ERROR HANDLING
 */
int					check_values(char **av);
int					is_checker_option(char *s, t_options *options);
int					is_swap_option(char *s, t_options *options);
/*
 *	OPPERATIONS
 */
int					swap_a_b(t_tab *tab, char pile);
int					push_a_b(t_tab *tab, char pile);
int					rot_a_b(t_tab *tab, char pile);
int					rev_rot_a_b(t_tab *tab, char pile);
int					use_instruction(char *opp, t_tab *tab);
int					check_if_pile_is_sorted(t_tab *tab);

/*
 * SHOW FUNCTIONS
 */
void				show_piles(t_tab *tab);
void				show_saved_opps(char **opps,int nbr_opps);
void				show_array(t_tab *tab);
void				show_saved_nbr(char **opps, int nbr_opps);
/*static t_opp		g_opp[] =
{
	{"sa",&swap_a},
	{NULL,&swap_a}
};*/
#endif
