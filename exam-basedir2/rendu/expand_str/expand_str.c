/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:23:25 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/15 21:11:41 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int main(int ac, char **av)
{
	int i;
	int j;
	char *s;
	
	if (ac == 2)
	{
		s = av[1];
		i = 0;
		j = 0;
		while (s[j])
			j++;
		j--;
		while (is_space(s[j]))
				j--;
		while (is_space(s[i]))
			i++;
		while(s[i] && i < j)
		{
			if (is_space(s[i]))
			{
				write(1, "   ", 3);
				while (is_space(s[i]) && i < j )
					i++;
			}
			write(1, &s[i], 1);
			i++;
		}
		write(1, &s[i], 1);
	}
	write(1, "\n", 1);
}
