/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:53:02 by ynachat           #+#    #+#             */
/*   Updated: 2024/08/08 11:23:13 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parcing(int ac, char **av)
{
	while (--ac)
	{
		if (ac == 5 )
		{
			if (ft_atoi(av[ac]) == -1)
				return (-1);
		}
		if (ac == 4 || ac == 3 || ac == 2)
		{
			if (ft_atoi(av[ac]) < 60 || ft_atoi(av[ac]) == -1)
				return (-1);
		}
		if (ac == 1)
		{
			if (ft_atoi(av[ac]) > 200 || ft_atoi(av[ac]) == -1)
				return (-1);
		}
	}
	return (0);
}
