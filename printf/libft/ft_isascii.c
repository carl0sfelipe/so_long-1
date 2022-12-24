/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:08:46 by csiqueir          #+#    #+#             */
/*   Updated: 2022/12/24 17:08:51 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_isascii checks whether c is an ascii character or not.

	RESULT VALUE :
	Non-zero if c is ascii, zero if not.
*/

int	ft_isascii(int c)
{
	if (c == 0)
		return (1);
	if (c > 0 && c <= 127)
		return (c);
	return (0);
}
