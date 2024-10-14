/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:13:14 by fdi-tria          #+#    #+#             */
/*   Updated: 2024/10/13 22:50:24 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_convert(char *str, int n, int len)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		str[0] = '-';
		sign = -1;
	}
	str[len] = '\0';
	while (len > 0 && (n || sign == -1))
	{
		str[--len] = (n % 10) * sign + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_convert(str, n, len);
	return (str);
}
