/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:26:59 by sde-mull          #+#    #+#             */
/*   Updated: 2022/06/12 15:37:17 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void ft_failure()
{
	ft_printf("Wrong PID\n");
	exit(EXIT_FAILURE);
}

void ft_sucess(int sig)
{
	if (sig)
		ft_printf("Everything received!\n");
	exit(EXIT_SUCCESS);
}

void	ft_send_char(int pid, char c)
{
	int bits;

	bits = 0;
	while (bits < 8)
	{
		if (c & (128 >> bits))
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_failure();
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				ft_failure();
		usleep(100);
		bits++;
	}
}

int main(int argc, char *argv[])
{
	int pid;
	char *str;
	int i;
	
	i = -1;
    if (argc > 3 || argc <= 2)
		return (ft_printf("Error!\n\"./client [PID] [STRING]\"\n"));
	pid = ft_atoi(argv[1]);
	if (!pid)
		return (ft_printf("Error!\nWrong PID"));
	signal(SIGUSR1, ft_sucess);
	str = argv[2];
	while (str[++i] != '\0')
		ft_send_char(pid, str[i]);
	ft_send_char(pid, str[i]);
	while(1)
		pause();
}
