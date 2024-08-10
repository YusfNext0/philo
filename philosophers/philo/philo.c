/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:57:31 by ynachat           #+#    #+#             */
/*   Updated: 2024/08/10 15:35:58 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char *av[])
{
	t_data *data;

	data = NULL;

	if (ac == 5 || ac == 6)
	{
		if (parcing(ac, av) == -1)
		{
			printf("Erorr !!!\n");
			return (1);
		}
		init_information(data, ft_atoi(av[1]), av);
	}else
	{
		printf("Error\n");
		return (1);
	}
	while (1)
		;
	return (0);
}
