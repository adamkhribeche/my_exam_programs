/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:39:47 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/16 02:36:40 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_in_base(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '0' + base - 1);
	return ((c >= '0' && c <= '0' + base - 1) || (c >= 'A' && c <= 'A' + base - 11));
}

char	*ft_itoa_base(int value, int base)
{
	int nbr;
	char s[] = "0123456789ABCDEF";
	int len;
	char *res;
	
	len = 0;
	if (value == 0)
		return ("0");
	if (base < 2 || base > 16)
		return (NULL);
	nbr = value > 0 ? value : -value;
	while (nbr)
	{
		if (!is_in_base(s[nbr % base], base))
			return (NULL);
		len++;
		nbr /= 10;
	}
	if (value < 0 && base == 10)
		len++;
	res = (char*)malloc(sizeof(char) * (len + 1));
	res[len--] = '\0';
	nbr = value > 0 ? value : -value;

	while (nbr)
	{
		printf("----------\n");
		if (nbr % base >= 0 && nbr % base <= 9)
			res[len--] = '0' + nbr % base;
		else
			res[len--] = 'A' + nbr % base - 10;
		nbr /= base;
	}
	if (value < 0 && base == 10)
		res[len] = '-';
	return (res);
}

int main()
{
	printf("%s\n", ft_itoa_base(125487, 16));
}
