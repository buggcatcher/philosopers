/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:07:46 by mailinci          #+#    #+#             */
/*   Updated: 2024/11/30 17:20:18 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long get_time(void)
{
	struct timeval	tv;
	unsigned long	time;

	time = 0;
	if (gettimeofday(&tv, NULL))
		return (printf("Error: getting the time of day\n"), 0);
	time = (tv.tv_sec * (unsigned long)1000) + (tv.tv_usec / 1000);
	return (time);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}