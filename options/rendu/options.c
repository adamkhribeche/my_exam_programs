/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 02:36:48 by nkhribec          #+#    #+#             */
/*   Updated: 2019/07/25 04:05:48 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_lower_case(char c)
{
	return (c >= 'a' && c <= 'z');
}

int is_alpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int main(int ac, char **av)
{
	char tab[32] = "00000000000000000000000000000000";
	char *s;
	int i;
	int j;

	if (ac > 1)
	{
		i = 0;
		while (++i < ac)
		{
			s = av[i];
			j = -1;
			if (!s[j + 1])
			{
				write(1, "Invalid Option\n", 15);
				return (0);
			}
			if (s[j + 1] == '-')
				j++;
			else
			{
				while (s[++j])
				{
					if (!is_alpha(s[j]))
					{
						write(1, "Invalid Option\n", 15);
						return (0);
					}
				}
				continue ;
			}
			while (s[++j])
			{
				if (s[j] == 'h')
				{
					write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
					return (0);
				}
				else if (is_lower_case(s[j]))
					tab[31 - (s[j] - 'a')] = '1';
				else
				{
					write(1, "Invalid Option\n", 15);
					return (0);
				}
			}
		}
		i = -1;
		while (++i < 32)
		{
			if (i != 0 && (i % 8) == 0)
				write(1, " ", 1);
			write(1, &tab[i], 1);
		}
		write(1, "\n", 1);
	}
	else
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
	return (0);
}
