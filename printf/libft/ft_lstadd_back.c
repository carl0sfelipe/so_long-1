/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:09:11 by csiqueir          #+#    #+#             */
/*   Updated: 2022/12/24 17:09:14 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_lstadd_back adds a new node to the back of a list:
		[.]->[.]->[.]->[NEW]->[NULL]

	RETURN VALUE :
	None.
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast(*alst);
	tmp->next = new;
}
