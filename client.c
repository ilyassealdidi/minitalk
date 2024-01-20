/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:54:48 by ialdidi           #+#    #+#             */
/*   Updated: 2024/01/20 17:54:49 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_message(pid_t pid, char *str)
{
	int			i;
	unsigned char mask;

	while (*str)
	{
		i = -1;
		mask = 1;
		while (++i < 8)
		{
			if (kill(pid, SIGUSR1 + !(mask & *str)) < 0)
				return (-1);
			usleep(50);
			mask <<= 1;
		}
		str++;
	}
	return (0);
}

int main(int ac, char **av) {
	int		sid;
	char	*msg;

	if (ac != 3)
	{
		ft_putstr_fd("The format must be as follows : ./program [pid] [message]", 1);
	}
	else
	{
		sid = ft_atoi(av[1]);
		msg = av[2];
		if (sid > 0 && msg[0])
		{
			sid = send_message(sid, msg);
			if (sid == 0)
				return (EXIT_SUCCESS);
			ft_putstr_fd("Connection failed : no such process", 1);
		}
		else
		{
			ft_putstr_fd("Invalid process id or An empty message provided", 1);
		}
	}
    return (EXIT_FAILURE);
}
