/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 22:41:32 by nkhribec          #+#    #+#             */
/*   Updated: 2019/07/04 22:54:39 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 22:05:14 by nkhribec          #+#    #+#             */
/*   Updated: 2019/07/04 22:40:48 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
	int i;

	i = 2;
	if (n == 1)
		return (0);
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (n % i++ == 0)
			return (0);
	}
	return (1);
}

int diviseur(int n)
{
	int i;

	i = 1;
	while (++i < n)
	{
		if (n % i == 0)
			return (i);
	}
	return (1);
}

int main(int ac, char **av)
{
	int		n;
	int		tab[20];
	int		i;
	int		imax;

	if (ac == 2)
	{
		n = atoi(av[1]);
		if (n == 0 || n == 1)
		{
			printf("%d\n", n);
			return (0);
		}
		i = 0;
		while (!(is_prime(n)))
		{
			tab[i] = diviseur(n);
			n /= diviseur(n);
			i++;
		}
		tab[i] = n;
		imax = i;
		i = 0;
		printf("%d", tab[i++]);
		while (i <= imax)
		{
			printf("*%d", tab[i++]);
		}
	}
	printf("\n");
}
