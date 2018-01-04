/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 00:14:30 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/04 17:50:09 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#include "../libft/includes/libft.h"

typedef struct s_tab
{
	int		*stack_a;
	int		index_a;
	int		*stack_b;
	int		index_b;
	int		size;
}				t_tab;
/*
 * -v = 
 */
typedef struct s_options
{
	char		v;
	char		d;
}				t_options;
/*
 *	INITIALISE VALUES
 */
t_tab	*create_array(int ac, char **av);
#endif
