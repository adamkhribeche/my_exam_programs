/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 23:10:54 by nkhribec          #+#    #+#             */
/*   Updated: 2019/07/21 00:20:35 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct     s_list
{
	int            data;
	struct s_list  *next;
}                  t_list;

int		cycle_detector(const t_list *list)
{
	const t_list *n;
	const t_list *n2;

	n = list;
	n2 = list;
	if (!list)
		return (0);
	while (1)
	{
		n = n->next;
		if (n2->next)
			n2 = n2->next->next;
		else
			return (0);
		if (!n || !n2)
			return (0);
		if (n == n2)
			return (1);
	}
}
