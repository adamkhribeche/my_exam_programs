/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 23:41:58 by nkhribec          #+#    #+#             */
/*   Updated: 2019/06/16 00:08:23 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char *s1;
	char *s2;
	char *s3;
	
	if (ac == 4)
	{
		s1 = av[1];
		s2 = av[2];
		s3 = av[3];
		if (*s2 == '+')
			printf("%d", atoi(s1) + atoi(s3));
		else if (*s2 == '-')
			printf("%d", atoi(s1) - atoi(s3));
		else if (*s2 == '/')
			printf("%d", atoi(s1) / atoi(s3));
		else if (*s2 == '%')
			printf("%d", atoi(s1) % atoi(s3));
		else if (*s2 == '*')
			printf("%d", atoi(s1) * atoi(s3));
	}
	printf("\n");
	return (0);
}
