/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:31:08 by nkhribec          #+#    #+#             */
/*   Updated: 2019/07/08 15:03:17 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

int 	is_top_also(char **tab, char c, t_point size, t_point begin)
{
	(void)size;
	return ((begin.y - 1 >= 0) && (tab[begin.y - 1][begin.x] == c));
}

int 	is_left_also(char **tab,char c, t_point size, t_point begin)
{
	(void)size;
	return ((begin.x - 1 >= 0) && (tab[begin.y][begin.x - 1] == c));
}

int 	is_right_also(char **tab, char c, t_point size, t_point begin)
{
	return ((begin.x + 1 < size.x) && (tab[begin.y][begin.x + 1] == c));
}

int 	is_down_also(char **tab, char c, t_point size, t_point begin)
{
	return ((begin.y + 1 < size.y) && (tab[begin.y + 1][begin.x] == c));
}

void 	flood_fill(char **tab, t_point size, t_point begin)
{
	t_point beg2;
	char c;

	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	printf("-------------\n");
	if (is_top_also(tab, c, size, begin))
	{
		beg2 = begin;
		beg2.y -= 1;
		flood_fill(tab, size, beg2);
	}
	if (is_down_also(tab, c, size, begin))
	{
		beg2 = begin;
		beg2.y += 1;
		flood_fill(tab, size, beg2);
	}
	if (is_right_also(tab, c, size, begin))
	{
		beg2 = begin;
		beg2.x += 1;
		flood_fill(tab, size, beg2);
	}
	if (is_left_also(tab, c, size, begin))
	{
		beg2 = begin;
		beg2.x -= 1;
		flood_fill(tab, size, beg2);
	}
}

void print_tab(char **area)
{
	int i;
	int j;

	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < 8)
		{
			printf("%c ", area[i][j]);
		}
		printf("\n");
	}
}

void cpy(char *d, char *s)
{
	while (*s)
	{
		*d = *s;
		d++;
		s++;
	}
}
int main(void)
{
	int i;
	char **area;
	t_point size = { 8, 5 };
	t_point begin = { 2, 2 };
	char *zone[] = {
		"01111111",
		"10011001",
		"10010001",
		"10110001",
		"11100001"
	};


	area = (char**)malloc(sizeof(char*) * 5);
	i = -1;
	while (++i < 5)
	{
		area[i] = (char*)malloc(sizeof(char) * 8);
		cpy(area[i], zone[i]);
	}
	print_tab(area);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area);
	return (0);
}
