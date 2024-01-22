/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:36:25 by ialdidi           #+#    #+#             */
/*   Updated: 2024/01/22 15:29:58 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	show_pid(pid_t pid);
void	receive_byte(int sig, siginfo_t *info, void *context);

int	main(void)
{
	struct sigaction	sa;

	show_pid(getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &receive_byte;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
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
	static unsigned char	c = 0;
	static char				counter = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (client_pid != info->si_pid)
	{
		c = 0;
		counter = 0;
	}
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		c += 1 << counter;
	counter++;
	if (counter == 8)
	{
		write(1, &c, 1);
		counter = 0;
		c = 0;
	}
}
