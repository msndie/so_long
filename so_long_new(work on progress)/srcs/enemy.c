/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:45:11 by sclam             #+#    #+#             */
/*   Updated: 2022/03/12 16:49:40 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_enemy	*ft_lst_new(void)
{
	t_enemy	*tmp;

	tmp = malloc(sizeof(t_enemy));
	if (tmp == NULL)
		return (0);
	tmp->next = NULL;
	return (tmp);
}

t_enemy	*ft_lst_last(t_enemy *lst)
{
	t_enemy	*tmp;

	tmp = lst;
	while (lst && tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	ft_lst_add_back(t_enemy **lst, t_enemy *new)
{
	t_enemy	*tmp;

	if (!new)
		return (-1);
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	else
	{
		tmp = ft_lst_last(*lst);
		tmp->next = new;
	}
	return (0);
}
