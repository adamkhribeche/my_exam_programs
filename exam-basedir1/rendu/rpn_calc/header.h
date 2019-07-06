/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 01:36:58 by nkhribec          #+#    #+#             */
/*   Updated: 2019/07/05 15:11:29 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_elem
{
	int etat; // etat 0 -> vide, etat 1 -> nbr, etat 2 -> op
	int content;
}				t_elem;

int is_nbr(char c);
int is_op(char c);
int check(char *s, int *p);
void add_in_tab(t_elem *elem, char *s);
int do_op(int a, int b, char op);
int	eval_is_finish(t_elem *elem, int size);
int result(t_elem *elem, int size);

#endif
