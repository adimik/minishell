/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimik <adimik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:59:45 by adimik            #+#    #+#             */
/*   Updated: 2024/10/27 11:59:45 by adimik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t num_elements, size_t size_of_element)
{
	unsigned char *arr;
	size_t i;

	if (num_elements != 0 && size_of_element > sizeof(size_t) / num_elements)
		return (NULL);
	i = 0;
	arr = malloc(num_elements * size_of_element);
	if (!arr)
		return (NULL);
	while (i < (num_elements * size_of_element))
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)(arr));
}
