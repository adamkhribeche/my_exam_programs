/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 00:11:47 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/16 01:00:08 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void turn_low(char *s)
{
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z')
			*s = *s - 'A' + 'a';
		s++;
	}
}

int main(int ac, char **av)
{	
	int i;
	int j;
	char *s;


	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			s = av[i];
			turn_low(s);
			j = 0;
			while (s[j] && is_space(s[j]))
			{
				write(1, &s[j], 1);
				j++;
			}
			if (!s[j])
				return (0);
			if (s[j] >= 'a' && s[j] <= 'z')
			{
				s[j] = s[j] - 'a' + 'A';
				write(1, &s[j++], 1);
			}
			while (s[j])
			{
				if ((s[j] >= 'a' && s[j] <= 'z') && is_space(s[j - 1]))
				{
					s[j] = s[j] - 'a' + 'A';
					write(1, &s[j], 1);
				}
				else
					write(1, &s[j], 1);
				j++;
			}
		write(1, "\n", 1);
		i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
