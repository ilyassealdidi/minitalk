/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:36:25 by ialdidi           #+#    #+#             */
/*   Updated: 2024/01/21 13:54:33 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	show_pid(pid_t pid);
void	receive_byte(int sig, siginfo_t *info, void *context);

int	main(void)
{
	struct sigaction	sa;

	show_pid(getpid());
	sa.sa_sigaction = &receive_byte;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}

void	show_pid(pid_t pid)
{
	ft_putstr("Process Id : ");
	ft_putnbr(pid);
	ft_putchar('\n');
}

void	receive_byte(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static char	counter = 0;

	(void)context;
	if (sig == SIGUSR1)
		c += 1 << counter;
	counter++;
	if (counter == 8)
	{
		if (!c)
			kill(info->si_pid, SIGUSR2);
		write(1, &c, 1);
		counter = 0;
		c = 0;
	}
}
