/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 21:40:34 by dholiday          #+#    #+#             */
/*   Updated: 2019/06/10 16:45:38 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clean_setka(char **setka)
{
	int i;

	i = 0;
	while (setka[i] != 0)
	{
		free(setka[i]);
		i++;
	}
	free(setka);
}

int		ft_helper2(t_etris *new_elem, t_kvadrat b, int past, int size)
{
	if (past == size)
	{
		new_elem->best_i = b.i;
		new_elem->best_j = b.j;
		return (1);
	}
	return (0);
}

int		ft_search_r(char **setka, int size)
{
	int i;
	int j;
	int r;

	r = 0;
	i = size - 1;
	while (i >= 0)
	{
		j = size - 1;
		while (j >= 0)
		{
			if (setka[i][j] != '.')
			{
				if (i > r)
					r = i;
				if (j > r)
					r = j;
			}
			j--;
		}
		i--;
	}
	return (r + 1);
}

void	ft_tetrimino_push_back(t_etris *begin_list, t_etris *new)
{
	t_etris	*p;

	p = begin_list;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}
