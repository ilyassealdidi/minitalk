/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:44:10 by ialdidi           #+#    #+#             */
/*   Updated: 2024/01/23 09:26:33 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		sign = 1 - 2 * (*str++ == '-');
	while (*str >= '0' && *str <= '9')
	{
		if (num > 922337203685477580
			|| (num == 922337203685477580 && *str - '0' > 7))
			return (-1 * (sign == 1));
		num = num * 10 + *str++ - '0';
	}
	if (!*str)
		return (0);
	return (num * sign);
}
