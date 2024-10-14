/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:21:07 by fdi-tria          #+#    #+#             */
/*   Updated: 2024/10/13 22:52:40 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
		ft_putnbr_rec_fd(n / 10, fd);
	if (n < 0)
		ft_putchar_fd(-(n % 10) + '0', fd);
	else
		ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_rec_fd(n, fd);
}
