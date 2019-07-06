/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:35:14 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/15 19:11:45 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	char c;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if ((av[1][i] >= 'a' && av[1][i] <= 'a' + 12))
			{
				c = av[1][i] - 'a';
				c = 'z' - c;
				write(1, &c, 1);
			}
			else if ((av[1][i] >= 'A' && av[1][i] <= 'A' + 12))
			{
				c = av[1][i] - 'A';
				c = 'Z' - c;
				write(1, &c, 1);
			}
			else if ((av[1][i] >= 'a' + 13 && av[1][i] <= 'z'))
			{
				c = 'z' - av[1][i];
				c = 'a' + c;
				write(1, &c, 1);
			}
			else if ((av[1][i] >= 'A' + 13 && av[1][i] <= 'Z'))
			{
				c = 'Z' - av[1][i];
				c = 'A' + c;
				write(1, &c, 1);
			}
			else
				write(1, &av[1][i], 1);

			i++;
		}
	}
	write(1, "\n", 1);
}
