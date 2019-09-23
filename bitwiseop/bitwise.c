/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 00:28:20 by nkhribec          #+#    #+#             */
/*   Updated: 2019/09/24 00:28:24 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned char	reversebbb(unsigned char c);
unsigned char	swapb(unsigned char c);
void			printb(unsigned char c);

unsigned char	swapb(unsigned char c)
{
	return (c >> 4 | c << 4);
}

unsigned char		reversebbb(unsigned char c)
{
	/*return ((((c & (1 << 0)) << 7) | (((c & (1 << 7))) >> 7)) |\
		(((c & (1 << 1)) << 5) | (((c & (1 << 6))) >> 5)) |\
		(((c & (1 << 2)) << 3) | (((c & (1 << 5))) >> 3)) |\
		(((c & (1 << 3)) << 1) | (((c & (1 << 4))) >> 1)));*/
	unsigned char	ret;
	int				i;
	int				n;

	i = -1;
	ret = 0;
	n = 7;
	while (++i < 4)
	{
		ret |= (((c & (1 << i)) <<  n) | ((c & (1 << (7 - i))) >>  n));
		n -= 2;
	}
	return (ret);
}

void			printb(unsigned char c)
{
	int				i;
	unsigned char	m;

	i = 8;
	while (--i > -1)
	{
		m = (((c & (1 << i)) >> i) + '0');
		write(1, &m, 1);
	}
	write(1, "\n", 1);
}

int				main()
{
	unsigned char c = 156;
	unsigned char c1 = 15;
	unsigned char c2 = 159;
	unsigned char c3 = 255;
	unsigned char m;
	
	printb(c);
	m = reversebbb(c);
	printb(m);
	printb(c1);
	m = reversebbb(c1);
	printb(m);
	printb(c2);
	m = reversebbb(c2);
	printb(m);
	printb(c3);
	m = reversebbb(c3);
	printb(m);
}
