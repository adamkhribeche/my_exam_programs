/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 21:17:17 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/15 22:02:21 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	char *s;
	int len;
	unsigned int n;

	if (nbr == 0)
		return ("0");
	n = nbr > 0 ? nbr : -nbr;
	len = 0;
	while (n)
	{
	//	printf("-------\n");
		n /= 10;
		len++;
	}
	if (nbr < 0)
	{
		n = (-1) * nbr;
		len++;
	}
	else
		n = nbr;
	//printf("%d\n", len);
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	while (n)
	{
		printf("-------\n");
		s[--len] = '0' + n % 10;
		//printf("%c\n", s[len + 1]);
		n /= 10;
	}
	//printf("%d\n", len);
	if (nbr < 0)
		s[0] = '-';
	return (s);
}

int main()
{
	printf("%s\n", ft_itoa(0));
	return (0);
}
