/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:08:00 by sde-mull          #+#    #+#             */
/*   Updated: 2022/06/15 15:24:36 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	str;
	static int	bits;

	(void)context;
	if (sig == SIGUSR1)
		str |= (128 >> bits);
	bits++;
	if (bits == 8)
	{
		write(1, &str, 1);
		if (str == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			write(1, "\n", 1);
		}
		str = 0;
		bits = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &ft_handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("The pid number is: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
