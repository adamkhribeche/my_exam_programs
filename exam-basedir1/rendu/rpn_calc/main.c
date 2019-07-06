/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 23:55:47 by nkhribec          #+#    #+#             */
/*   Updated: 2019/07/05 21:17:20 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int is_nbr(char c)
{
	return (c >= '0' && c <= '9');
}

int is_op(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int skip_space(char *s, int i)
{
	int j;

	j = i;
	while (s[j] && s[j] == ' ')
		j++;
	return(j);
}

int check(char *s, int *p)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i] == ' ')
		i++;
	if (!s[i] || !is_nbr(s[i]))
		return (0);
	while (s[i])
	{
		if (count < 0)
			return (0);
		i = skip_space(s, i);
		if (is_nbr(s[i]))
		{
			p[1]++;
			while (is_nbr(s[i]))
				i++;
			if (s[i] != ' ' && s[i] != '\0')
				return (0);
			count++;
		}
		else if (is_op(s[i]))
		{
			p[0]++;
			if (s[i + 1] != ' ' && s[i + 1] != '\0')
				return (0);
			i++;
			i = skip_space(s, i);
			count--;
		}
		else
			return (0);
	}
	if (p[1] != p[0] + 1)
		return (0);
	return (1);
}

void add_in_tab(t_elem *elem, char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (is_nbr(*s))
		{
			elem[i].content = atoi(s);
			elem[i].etat = 1;
			while (is_nbr(*s))
				s++;
		}
		else
		{
			elem[i].content = (int)*s;
			elem[i].etat = 2;
			s++;
		}
		i++;
	}
}

int do_op(int a, int b, char op)
{
	if(op == '+')
		return (a + b);
	if(op == '-')
		return (a - b);
	if(op == '/')
		return (a / b);
	if(op == '%')
		return (a % b);
	if(op == '*')
		return (a * b);
	else
		return (0);
}

int	eval_is_finish(t_elem *elem, int size)// file is already valid
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (elem[i].etat == 2)
			return (0);
		if (elem[i].etat == 1)
			count++;
		if (count > 1)
			return (0);
		i++;
	}
	return (count == 1);
}

int result(t_elem *elem, int size)
{
	int i;

	i = 0;
	while (size--)
	{
		if (elem[i].etat == 1)
			break ;
		i++;
	}
	return (elem[i].content);
}

int next(t_elem *elem, int size, int i)
{
	int next;

	next = i + 1;
	while (next < size)
	{
		if (elem[next].etat != 0)
			return (next);
		next++;
	}
	return (0);
}

void rpn_calc(char *s, int size)
{
	t_elem	*elem;
	int 	i;
	int 	next1;
	int 	next2;

	elem = (t_elem*)malloc(sizeof(*elem) * size);
	add_in_tab(elem, s);
	i = 0;
	while (!eval_is_finish(elem, size))
	{
		next1 =	next(elem, size, i);
		next2 = next(elem, size, next1);
		if (next2 < size && elem[i].etat == 1 && elem[next1].etat == 1 && elem[next2].etat == 2)
		{
			elem[i].content = do_op(elem[i].content, elem[next1].content, (char)elem[next2].content);
			printf("---------%d------\n", elem[i].content);
			elem[next1].etat = 0;
			elem[next2].etat = 0;
			i = -1;
		}
		i++;
	}
	printf("%d\n", result(elem, size));
}

int main(int ac, char **av)
{
	char	*s;
	int		size;
	int		cop_cnb[2] = {0, 0};

	s = av[1];
	if (ac == 2 && check(s, cop_cnb))
	{
		size = cop_cnb[0] + cop_cnb[1];
		rpn_calc(s, size);
	}
	else
		printf("Error\n");
}
