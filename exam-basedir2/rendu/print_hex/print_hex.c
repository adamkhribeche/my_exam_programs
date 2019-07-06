/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:16:13 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/15 19:53:48 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *s)
{
	int i;
	int result;

	result = 0;
	i = -1;
	while (s[++i])
		result = result * 10 + (s[i] - '0');
	return (result);
}

void 	print_hex(int nbr)
{
	char s[] = "0123456789abcdef";
	char c[8];
	int i;

	i = -1;
	while (nbr)
	{
		c[++i] = s[nbr % 16];
		nbr /= 16;
	}
	while (i + 1)
		write(1, &c[i--], 1);
}

int main(int ac, char **av)
{	
	int nbr;

	if (ac == 2)
	{
		nbr = ft_atoi(av[1]);
		print_hex(nbr);
	}
	write(1, "\n", 1);
}
