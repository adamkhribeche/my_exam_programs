/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 01:18:02 by nkhribec          #+#    #+#             */
/*   Updated: 2019/07/14 01:20:16 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t			j;
	char			s[] = "0123456789abcdef";
	unsigned char	*p;

	p = (unsigned char*)addr;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16 && i + j < size)
		{
			write(1, &s[*(p + i + j) / 16 % 16], 1);
			write(1, &s[*(p + i + j) % 16], 1);
			if ((j + 1) % 2 == 0)
				write(1, " ", 1);
			j++;
		}
		while (j < 16)
		{
			write(1, "  ", 2);
			if ((j + 1) % 2 == 0)
				write(1, " ", 1);
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (*(p + i + j) >= 32 && *(p + i + j) < 127)
				write(1, (p + i + j), 1);
			else
				write(1, ".", 1);
			j++;
		}
		write(1, "\n", 1);
		i += 16;
	}
}
