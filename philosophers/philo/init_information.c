/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_information.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:31:23 by ynachat           #+#    #+#             */
/*   Updated: 2024/08/10 15:55:52 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
		// // to do 
		// //////////////////////
		// // manage eating () //
		// /////////////////////
		
		// 	// take left fork
		// pthread_mutex_lock(philo->left_fork);
		// 	// take right fork
		// pthread_mutex_lock(philo->right_fork);
		// 	// X is eating
		// printf("%d is eating\n", philo->id);
		// 	// start eating (usleep(time to eat))
		// usleep(philo->time_to_eat);
		// 	// put left fork
		// // if (philo->id == 2)
		// // {	printf("-->...%d\n",philo->id);
		// // 	exit(1);
		// // }
		// pthread_mutex_unlock(philo->left_fork);
		// 	// put right fork
		// pthread_mutex_unlock(philo->right_fork);
		// /////////////////////
		// // manage sleeping //
		// /////////////////////
		// 	//  X is sleeping
		// printf("%d is sleeping\n", philo->id);
		// 	// start sleeping
		// usleep(philo->time_to_sleep);
		// /////////////////////
		// // manage thinking //
		// /////////////////////
		// 	// X is thinking
		// printf("%d is thinking\n", philo->id);

long long	current_time_ms(void)
{
	struct timeval	time;
	long long		time_ms;

	gettimeofday(&time, NULL);
	time_ms = time.tv_sec * 1000;
	time_ms += time.tv_usec / 1000;
	return (time_ms);
}

long	ft_usleep(long long time)
{
	long long	start;

	start = current_time_ms();
	while (current_time_ms() - start < time)
		usleep(100);
	return (0);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%d has taken a left fork\n", philo->id);
	pthread_mutex_lock(philo->right_fork);
	printf("%d has taken a right fork\n", philo->id);
	printf("%d is eating\n", philo->id);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	printf("%d is sleeping\n", philo->id);
	ft_usleep(philo->time_to_sleep);
}

void *routine(void *param)
{
	t_philo *philo;

	philo = (t_philo *)param;
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		printf("%d is thinking\n", philo->id);
	}
	return NULL ;
}

void init_forks(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_ph)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}	
}

void init_inf1(t_data *data, char **av)
{
	int i;
	i = 0;

	init_forks(data);
	while (i < data->nb_ph)
	{
		data->philo[i].time_to_eat = ft_atoi(av[2]);
		data->philo[i].time_to_sleep = ft_atoi(av[3]);
		data->philo[i].time_to_die = ft_atoi(av[4]);
		data->philo[i].id = i + 1;
		data->philo[i].left_fork = &data->forks[i];
		if (i == data->nb_ph - 1)
			data->philo[i].right_fork = &data->forks[0];
		else
			data->philo[i].right_fork = &data->forks[i + 1];
		i++;
	}
	i = 0;
	while (i < data->nb_ph)
	{
		if (pthread_create(&data->philo[i].th_philo , NULL, routine , &data->philo[i]))
		{
			printf("Error thread id %d\n", data->philo[i].id);
			return ;
		}
		i++;
	}
	i = 0;
	while (i < data->nb_ph)
	{
		pthread_detach(data->philo[i].th_philo);
		i++;
	}
	// pthread_mutex_destroy(data->forks);
}

int init_information(t_data *data, int nb_philo, char **av)
{
	data = malloc(sizeof(t_data));
	if (!data)
	{
		printf("Error malloc data\n");
		return (1);
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!data->forks)
	{
		printf("Error malloc data\n");
		return (1);
	}
	data->philo = malloc(sizeof(t_philo) * nb_philo);
	if (!data)
	{
		printf("Error malloc data_philo\n");
		return (1);
	}
	data->nb_ph = nb_philo;
	init_inf1(data, av);
	return (0);
}
