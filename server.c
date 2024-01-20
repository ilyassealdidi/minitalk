/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:36:25 by ialdidi           #+#    #+#             */
/*   Updated: 2024/01/20 17:09:54 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char counter = 0;
char c = 0;

void receive_char(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
		c += 1 << counter;
	counter++;
	if (counter == 8)
	{
		write(1, &c, 1);
		counter = c = 0;
	}
}

void	show_pid(pid_t pid)
{
	ft_putstr_fd("Process Id : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	struct sigaction sa;

	show_pid(getpid());
	
	sa.sa_sigaction = &receive_char;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return 0;
}
