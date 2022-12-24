/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:10:23 by csiqueir          #+#    #+#             */
/*   Updated: 2022/12/24 17:10:25 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memset fills the first len bytes of the memory area
	pointed	to by b with the byte c. Both b and c are interpreted as 
	unsigned char.

	RETURN VALUE :
	A pointer to memory area s.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	ch;

	p = (unsigned char *)b;
	ch = c;
	while (len--)
	{
		*p = ch;
		p++;
	}
	return (b);
}
