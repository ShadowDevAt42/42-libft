/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:47:38 by fdi-tria          #+#    #+#             */
/*   Updated: 2024/08/30 23:31:50 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
	{
		return (ft_memcpy(dst, src, len));
	}
	else if (d > s)
	{
		d += len;
		s += len;
		while (len--)
		{
			*--d = *--s;
		}
	}
	return (dst);
}
