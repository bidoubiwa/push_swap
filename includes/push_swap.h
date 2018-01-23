/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 00:14:30 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/23 11:07:47 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#include "../libft/includes/libft.h"

/*enum				e_action
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}*/
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
	struct s_opp	*next;
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
t_opp				*save_opp(t_opp *opps, char *opp);
void				parse_checker_options(int ac, char **av, t_options *options);
void				parse_swap_options(int ac, char **av, t_options *options);
t_tab				*parse_tab_struct(char **av, t_options *options,
		t_tab *tab);
int					parse_arguments(int ac, char **av, t_options *options, t_tab *tab);
int					real_tab_to_simplified(t_tab *old, t_tab *new);
t_opp				*create_opp(t_opp *opp);
t_opp				*copy_opps(t_opp *old);
t_tab				*copy_tab(t_tab *old);
void				free_opp(t_opp *ope);
void				free_tab(t_tab *tab);
t_opp				*find_last_opp(t_opp *opp);
/*
 * ERROR HANDLING
 */
int					check_values(char **av);
int					is_checker_option(char *s, t_options *options);
int					is_swap_option(char *s, t_options *options);
int					check_for_dubble(t_tab *tab);
/*
 *	OPPERATIONS
 */
int					use_save_instruction(char *opp, t_tab *tab, t_opp *ope);
t_opp				*execute_best_opps(t_opp *ope, t_tab *tab);
void				free_biggest_tab_ope(t_tab **tab, t_tab *tab_c, t_opp **opp, t_opp *opp_c);
int					swap_a_b(t_tab *tab, char pile);
int					push_a_b(t_tab *tab, char pile);
int					rot_a_b(t_tab *tab, char pile);
int					rev_rot_a_b(t_tab *tab, char pile);
int					use_instruction(char *opp, t_tab *tab);
int					empty_b_pile(t_tab *tab, t_opp *ope);
int					ra_until_sorted(t_tab *tab, t_opp *ope, char c);
int					rra_until_sorted(t_tab *tab, t_opp *ope, char c);
int					rab_until_x_number_on_top(t_tab *tab, t_opp *opp, char c, int x); 
int					rab_until_x_number_on_top_greater(t_tab *tab, t_opp *opp, char c, int x); 
int					rrab_until_x_number_on_top(t_tab *tab, t_opp *opp, char c, int x);
int					rrab_until_x_number_on_top_greater(t_tab *tab, t_opp *opp, char c, int x);
/*
 * SORTING FUNCTIONS
 */
t_opp				*simple_ra_sa_pb(t_tab *tab, t_opp *ope);
t_opp				*simple_no_pb(t_tab *tab, t_opp *opp);
t_opp				*quick_sort(t_tab *tab, t_opp *opp, int marge);
int					pile_a_sorted_b_empty(t_tab *tab);
int					pile_a_is_sorted(t_tab *tab);
int					check_if_pile_is_sorted(t_tab *tab);
int					pile_is_strictly_sorted(t_tab *tab, char c);
int					is_there_greater_or_smaller(t_tab *tab, char c, int x);

/*
 * FIND FUNCTIONS
 */
int					smallest_in_ab(t_tab *tab, char c);
int					greatest_in_ab(t_tab *tab, char c);
int					find_number_just_under_x(t_tab *tab, char c, int x);
t_opp				*find_next_marge(char *ope, t_tab *tab, t_ope *ope, int limit);
/*
 * SHOW FUNCTIONS
 */
void				show_piles(t_tab *tab);
void				show_piles_alligned(t_tab *tab);
void				show_saved_opps(char **opps,int nbr_opps);
void				show_array(t_tab *tab);
void				show_saved_nbr(char **opps, int nbr_opps);
/*static t_opp		g_opp[] =
{
	{"sa",&swap_a},
	{NULL,&swap_a}
};*/
#endif
