/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:12:05 by mailinci          #+#    #+#             */
/*   Updated: 2024/11/30 15:12:06 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_bzero(void *s, size_t n)
{
	size_t  i;
	char    *str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void    *ft_calloc(size_t number_of_elements, size_t size)
{
	void    *array;

	array = (void *)malloc(size * number_of_elements);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (size * number_of_elements));
	return (array);
}

void *safe_alloc(size_t n_elem, size_t bytes, const char *description)
{
    void *memory_allocation;

    memory_allocation = calloc(n_elem, bytes);
    if (memory_allocation == NULL)
    {
        printf("Error: memory allocation for %s has failed\n", description);
        exit(EXIT_FAILURE);
    }
    return memory_allocation;
}