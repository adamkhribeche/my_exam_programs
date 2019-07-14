/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 22:58:59 by nkhribec          #+#    #+#             */
/*   Updated: 2019/07/14 00:38:10 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	 palindrom(char *s)
{
	int i0;
	int i1;
	int i;
	int j;
	int count;
	int max;
	char *p;

	max = 0;
	p = s;
	if (*s)
	{
		i = 1;
		max = 1;
		while (s[i])
		{
			i0 = i;
			i1 = i;
			count = 1;
			while (s[i1 + 1] && s[i1] == s[i1 + 1])
			{
				i1++;
				count++;
			}
			while (s[i0 - 1] && s[i0] == s[i0 - 1])
			{
				i0--;
				count++;
			}
			j = 1;
			while ((i0 - j >= 0) && s[i1 + j] && s[i0 - j] == s[i1 + j])
			{
				count = count + 2;
				j++;
			}
			if (count >= max)
			{
				max = count;
				p = &s[i0 - j + 1];
			}
			i++;
		}
	}
	i = 0;
	while (i < max)
	{
		write(1, &p[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		palindrom(av[1]);
	write(1, "\n", 1);
}
