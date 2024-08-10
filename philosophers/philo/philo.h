/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:47:21 by ynachat           #+#    #+#             */
/*   Updated: 2024/08/10 14:18:50 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

# ifndef PHILO_H
# define PHILO_H

typedef struct s_philo
{
	int	id;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_t	th_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
} t_philo ;

typedef struct s_data
{
	pthread_mutex_t	*forks;

	int	nb_ph;
	t_philo *philo;
} t_data ;

void	free_mat(char **mtr);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
int		parcing(int ac, char **av);
int	init_information(t_data *data, int nb_philo , char **av);



#endif