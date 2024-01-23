/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:54:48 by ialdidi           #+#    #+#             */
/*   Updated: 2024/01/23 08:23:17 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		send_message(pid_t pid, char *str);

int	main(int ac, char **av)
{
	int		sid;
	char	*msg;

	if (ac != 3)
	{
		ft_putstr("The format must be as follows : ./program [pid] [message]");
	}
	else
	{
		sid = ft_atoi(av[1]);
		msg = av[2];
		if (sid > 0 && msg[0])
		{
			sid = send_message(sid, msg);
			if (sid == EXIT_SUCCESS)
				return (EXIT_SUCCESS);
			ft_putstr("No such process");
		}
		else
		{
			ft_putstr("Invalid process id or An empty message provided");
		}
	}
	return (EXIT_FAILURE);
}

int	send_message(pid_t pid, char *str)
{
	int				i;
	unsigned char	mask;

	while (*str)
	{
		i = -1;
		mask = 1;
		while (++i < 8)
		{
			if (kill(pid, SIGUSR1 + !(mask & *str)) < 0)
				return (EXIT_FAILURE);
			usleep(500);
			mask <<= 1;
		}
		str++;
	}
	return (EXIT_SUCCESS);
}
