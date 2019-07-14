/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 00:54:27 by nkhribec          #+#    #+#             */
/*   Updated: 2019/07/14 00:58:09 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int are_match(char a, char b)
{
	return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}
int is_correct(char *s)	
{
	char buff[1000];
	int count;
	int i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			buff[++count] = s[i];
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (!are_match(buff[count--], s[i]))
				return (0);
		}
		i++;
	}
	if (count == 0)
		return (1);
	else
		return (0);
}

int main(int ac, char **av)
{
	int i;
	
	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			if (is_correct(av[i]))
				write(1, "OK", 2);
			else
				write(1, "Error", 5);
			i++;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
}
