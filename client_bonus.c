/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:43:17 by ialdidi           #+#    #+#             */
/*   Updated: 2024/01/21 14:43:20 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int sig);
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
			signal(SIGUSR2, signal_handler);
			sid = send_message(sid, msg);
			if (sid == 0)
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

void	signal_handler(int sig)
{
	(void)sig;
	ft_putstr("Message sent successfully \xE2\x9C\x85\n");
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
				return (-1);
			usleep(50);
			mask <<= 1;
		}
		str++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
	return (0);
}
