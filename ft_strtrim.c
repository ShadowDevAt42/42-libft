/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:04:20 by fdi-tria          #+#    #+#             */
/*   Updated: 2024/10/14 15:21:18 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_start(const char *s1, const char *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	return (start);
}

static size_t	ft_end(const char *s1, const char *set)
{
	size_t	end;

	end = 0;
	while (s1[end])
		end++;
	if (end == 0)
		return (0);
	end--;
	while (end > 0 && ft_isset(s1[end], set))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (end >= start)
		len = end - start + 1;
	else
		len = 0;
	trimmed_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!trimmed_str)
		return (NULL);
	while (start <= end)
		*trimmed_str++ = s1[start++];
	*trimmed_str = '\0';
	return (trimmed_str - len);
}
